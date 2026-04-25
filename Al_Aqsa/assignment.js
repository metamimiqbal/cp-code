const {
  Document, Packer, Paragraph, TextRun, Table, TableRow, TableCell,
  AlignmentType, HeadingLevel, BorderStyle, WidthType, ShadingType,
  LevelFormat, VerticalAlign, PageNumber, PageBreak
} = require('docx');
const fs = require('fs');

// Border helpers
const thinBorder = { style: BorderStyle.SINGLE, size: 1, color: "AAAAAA" };
const allBorders = { top: thinBorder, bottom: thinBorder, left: thinBorder, right: thinBorder };
const headerBorder = { style: BorderStyle.SINGLE, size: 2, color: "1F4E79" };
const headerBorders = { top: headerBorder, bottom: headerBorder, left: headerBorder, right: headerBorder };

function hCell(text, w, shade = "1F4E79") {
  return new TableCell({
    borders: headerBorders,
    width: { size: w, type: WidthType.DXA },
    shading: { fill: shade, type: ShadingType.CLEAR },
    margins: { top: 80, bottom: 80, left: 120, right: 120 },
    verticalAlign: VerticalAlign.CENTER,
    children: [new Paragraph({
      alignment: AlignmentType.CENTER,
      children: [new TextRun({ text, bold: true, color: "FFFFFF", size: 20, font: "Arial" })]
    })]
  });
}

function dCell(text, w, shade = "FFFFFF", bold = false, center = false) {
  return new TableCell({
    borders: allBorders,
    width: { size: w, type: WidthType.DXA },
    shading: { fill: shade, type: ShadingType.CLEAR },
    margins: { top: 60, bottom: 60, left: 120, right: 120 },
    verticalAlign: VerticalAlign.CENTER,
    children: [new Paragraph({
      alignment: center ? AlignmentType.CENTER : AlignmentType.LEFT,
      children: [new TextRun({ text, bold, size: 20, font: "Arial" })]
    })]
  });
}

function heading(text, level = HeadingLevel.HEADING_1) {
  return new Paragraph({
    heading: level,
    spacing: { before: 240, after: 120 },
    children: [new TextRun({
      text,
      bold: true,
      font: "Arial",
      size: level === HeadingLevel.HEADING_1 ? 28 : 24,
      color: level === HeadingLevel.HEADING_1 ? "1F4E79" : "2E75B6"
    })]
  });
}

function para(text, options = {}) {
  return new Paragraph({
    alignment: options.center ? AlignmentType.CENTER : AlignmentType.JUSTIFIED,
    spacing: { before: 60, after: 60 },
    children: [new TextRun({
      text,
      font: "Arial",
      size: 22,
      bold: options.bold || false,
      italics: options.italic || false,
      color: options.color || "000000"
    })]
  });
}

function bullet(text) {
  return new Paragraph({
    numbering: { reference: "bullets", level: 0 },
    spacing: { before: 40, after: 40 },
    children: [new TextRun({ text, font: "Arial", size: 22 })]
  });
}

function numbered(text) {
  return new Paragraph({
    numbering: { reference: "numbers", level: 0 },
    spacing: { before: 40, after: 40 },
    children: [new TextRun({ text, font: "Arial", size: 22 })]
  });
}

function space(n = 1) {
  return new Paragraph({ children: [new TextRun({ text: " ".repeat(n) })], spacing: { before: 60, after: 60 } });
}

function divider() {
  return new Paragraph({
    border: { bottom: { style: BorderStyle.SINGLE, size: 4, color: "2E75B6", space: 1 } },
    spacing: { before: 160, after: 160 },
    children: []
  });
}

// ===== STATE TABLE DATA =====
// Sequence: 0→3→7→11→2→5→9→1→6→10→4→8→(repeat)
// 0=0000,3=0011,7=0111,11=1011,2=0010,5=0101,9=1001,1=0001,6=0110,10=1010,4=0100,8=1000
const stateData = [
  ["0","0","0","0", "0","0","1","1", "0","0","1","1"],
  ["0","0","1","1", "0","1","1","1", "0","1","1","1"],
  ["0","1","1","1", "1","0","1","1", "1","0","1","1"],
  ["1","0","1","1", "0","0","1","0", "0","0","1","0"],
  ["0","0","1","0", "0","1","0","1", "0","1","0","1"],
  ["0","1","0","1", "1","0","0","1", "1","0","0","1"],
  ["1","0","0","1", "0","0","0","1", "0","0","0","1"],
  ["0","0","0","1", "0","1","1","0", "0","1","1","0"],
  ["0","1","1","0", "1","0","1","0", "1","0","1","0"],
  ["1","0","1","0", "0","1","0","0", "0","1","0","0"],
  ["0","1","0","0", "1","0","0","0", "1","0","0","0"],
  ["1","0","0","0", "0","0","0","0", "0","0","0","0"],
  // Invalid states (Q1Q2=11)
  ["1","1","0","0", "0","0","0","0", "0","0","0","0"],
  ["1","1","0","1", "0","0","0","0", "0","0","0","0"],
  ["1","1","1","0", "0","0","0","0", "0","0","0","0"],
  ["1","1","1","1", "0","0","0","0", "0","0","0","0"],
];

function buildStateTable() {
  const cw = [520, 520, 520, 520];
  const totalCW = cw[0]*4; // current state cols
  // We have 12 columns: Q1 Q2 Q3 Q4 | Q1+ Q2+ Q3+ Q4+ | D1 D2 D3 D4
  // Let's use fixed width per col
  const colW = 700;
  const totalW = colW * 12;

  const headerRow = new TableRow({
    tableHeader: true,
    children: [
      // Span header
      new TableCell({
        borders: headerBorders,
        width: { size: colW*4, type: WidthType.DXA },
        shading: { fill: "1F4E79", type: ShadingType.CLEAR },
        margins: { top: 80, bottom: 80, left: 120, right: 120 },
        columnSpan: 4,
        children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "Current State", bold: true, color: "FFFFFF", size: 20, font: "Arial" })] })]
      }),
      new TableCell({
        borders: headerBorders,
        width: { size: colW*4, type: WidthType.DXA },
        shading: { fill: "1F4E79", type: ShadingType.CLEAR },
        margins: { top: 80, bottom: 80, left: 120, right: 120 },
        columnSpan: 4,
        children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "Next State", bold: true, color: "FFFFFF", size: 20, font: "Arial" })] })]
      }),
      new TableCell({
        borders: headerBorders,
        width: { size: colW*4, type: WidthType.DXA },
        shading: { fill: "1F4E79", type: ShadingType.CLEAR },
        margins: { top: 80, bottom: 80, left: 120, right: 120 },
        columnSpan: 4,
        children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "Flip-Flop Inputs (D FF)", bold: true, color: "FFFFFF", size: 20, font: "Arial" })] })]
      }),
    ]
  });

  const subHeaderRow = new TableRow({
    tableHeader: true,
    children: [
      hCell("Q₁", colW, "2E75B6"), hCell("Q₂", colW, "2E75B6"), hCell("Q₃", colW, "2E75B6"), hCell("Q₄", colW, "2E75B6"),
      hCell("Q₁⁺", colW, "2E75B6"), hCell("Q₂⁺", colW, "2E75B6"), hCell("Q₃⁺", colW, "2E75B6"), hCell("Q₄⁺", colW, "2E75B6"),
      hCell("D₁", colW, "2E75B6"), hCell("D₂", colW, "2E75B6"), hCell("D₃", colW, "2E75B6"), hCell("D₄", colW, "2E75B6"),
    ]
  });

  const dataRows = stateData.map((row, idx) => {
    const isInvalid = row[0] === "1" && row[1] === "1";
    const shade = isInvalid ? "FFF2CC" : (idx % 2 === 0 ? "F5F9FF" : "FFFFFF");
    return new TableRow({
      children: row.map(val => dCell(val, colW, shade, false, true))
    });
  });

  return new Table({
    width: { size: colW * 12, type: WidthType.DXA },
    columnWidths: Array(12).fill(colW),
    rows: [headerRow, subHeaderRow, ...dataRows]
  });
}

// Fan-out table
function buildFanOutTable() {
  const cols = [2000, 3500, 2000];
  const total = cols.reduce((a,b) => a+b, 0);
  return new Table({
    width: { size: total, type: WidthType.DXA },
    columnWidths: cols,
    rows: [
      new TableRow({ tableHeader: true, children: [hCell("Flip-Flop Output", cols[0]), hCell("Used In Equations", cols[1]), hCell("Fan-Out Demand", cols[2])] }),
      new TableRow({ children: [dCell("Q₁", cols[0], "F5F9FF", true, true), dCell("D₁, D₂, D₃, D₄", cols[1], "F5F9FF", false, true), dCell("High", cols[2], "FFE7E7", false, true)] }),
      new TableRow({ children: [dCell("Q₂", cols[0], "FFFFFF", true, true), dCell("D₁, D₂, D₃, D₄", cols[1], "FFFFFF", false, true), dCell("High", cols[2], "FFE7E7", false, true)] }),
      new TableRow({ children: [dCell("Q₃", cols[0], "F5F9FF", true, true), dCell("D₂, D₃, D₄", cols[1], "F5F9FF", false, true), dCell("Medium", cols[2], "FFFBE7", false, true)] }),
      new TableRow({ children: [dCell("Q₄", cols[0], "FFFFFF", true, true), dCell("D₂, D₃, D₄", cols[1], "FFFFFF", false, true), dCell("Medium", cols[2], "FFFBE7", false, true)] }),
    ]
  });
}

// Invalid states table
function buildInvalidTable() {
  const cols = [2000, 2500, 2500];
  const total = cols.reduce((a,b) => a+b, 0);
  return new Table({
    width: { size: total, type: WidthType.DXA },
    columnWidths: cols,
    rows: [
      new TableRow({ tableHeader: true, children: [hCell("State", cols[0]), hCell("Binary Representation", cols[1]), hCell("Next State (Forced)", cols[2])] }),
      new TableRow({ children: [dCell("12", cols[0], "FFF2CC", true, true), dCell("1100", cols[1], "FFF2CC", false, true), dCell("0000 (State 0)", cols[2], "E7FFE7", false, true)] }),
      new TableRow({ children: [dCell("13", cols[0], "FFFFFF", true, true), dCell("1101", cols[1], "FFFFFF", false, true), dCell("0000 (State 0)", cols[2], "E7FFE7", false, true)] }),
      new TableRow({ children: [dCell("14", cols[0], "FFF2CC", true, true), dCell("1110", cols[1], "FFF2CC", false, true), dCell("0000 (State 0)", cols[2], "E7FFE7", false, true)] }),
      new TableRow({ children: [dCell("15", cols[0], "FFFFFF", true, true), dCell("1111", cols[1], "FFFFFF", false, true), dCell("0000 (State 0)", cols[2], "E7FFE7", false, true)] }),
    ]
  });
}

const doc = new Document({
  styles: {
    default: {
      document: { run: { font: "Arial", size: 22 } }
    },
    paragraphStyles: [
      {
        id: "Heading1", name: "Heading 1", basedOn: "Normal", next: "Normal", quickFormat: true,
        run: { size: 28, bold: true, font: "Arial", color: "1F4E79" },
        paragraph: { spacing: { before: 320, after: 160 }, outlineLevel: 0,
          border: { bottom: { style: BorderStyle.SINGLE, size: 4, color: "2E75B6", space: 1 } } }
      },
      {
        id: "Heading2", name: "Heading 2", basedOn: "Normal", next: "Normal", quickFormat: true,
        run: { size: 24, bold: true, font: "Arial", color: "2E75B6" },
        paragraph: { spacing: { before: 240, after: 120 }, outlineLevel: 1 }
      },
      {
        id: "Heading3", name: "Heading 3", basedOn: "Normal", next: "Normal", quickFormat: true,
        run: { size: 22, bold: true, font: "Arial", color: "1F4E79" },
        paragraph: { spacing: { before: 160, after: 80 }, outlineLevel: 2 }
      }
    ]
  },
  numbering: {
    config: [
      {
        reference: "bullets",
        levels: [{
          level: 0, format: LevelFormat.BULLET, text: "\u2022", alignment: AlignmentType.LEFT,
          style: { paragraph: { indent: { left: 720, hanging: 360 } } }
        }]
      },
      {
        reference: "numbers",
        levels: [{
          level: 0, format: LevelFormat.DECIMAL, text: "%1.", alignment: AlignmentType.LEFT,
          style: { paragraph: { indent: { left: 720, hanging: 360 } } }
        }]
      }
    ]
  },
  sections: [{
    properties: {
      page: {
        size: { width: 12240, height: 15840 },
        margin: { top: 1440, right: 1260, bottom: 1440, left: 1260 }
      }
    },
    children: [
      // ============ HEADER INFO ============
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 0, after: 80 },
        children: [new TextRun({ text: "Heaven's Light is Our Guide", bold: true, font: "Arial", size: 22 })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 0, after: 80 },
        children: [new TextRun({ text: "Rajshahi University of Engineering & Technology", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 0, after: 80 },
        children: [new TextRun({ text: "Department of Computer Science & Engineering", font: "Arial", size: 22 })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 0, after: 80 },
        children: [new TextRun({ text: "Course No.: CSE 2103  |  Course Title: Digital Logic Design", font: "Arial", size: 22 })]
      }),
      divider(),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 120, after: 120 },
        children: [new TextRun({ text: "Assignment — Question 1: Optimized Counter Design with Constraints", bold: true, font: "Arial", size: 28, color: "1F4E79" })]
      }),
      divider(),
      space(),

      // ============ PROBLEM STATEMENT ============
      new Paragraph({
        heading: HeadingLevel.HEADING_1,
        children: [new TextRun({ text: "Problem Statement", bold: true, font: "Arial", size: 28 })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [
          new TextRun({ text: "Design a synchronous ", font: "Arial", size: 22 }),
          new TextRun({ text: "MOD-12 counter", bold: true, font: "Arial", size: 22 }),
          new TextRun({ text: " that follows the custom non-binary sequence given below:", font: "Arial", size: 22 }),
        ]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 120, after: 120 },
        shading: { fill: "EFF7FF", type: ShadingType.CLEAR },
        children: [new TextRun({ text: "0 → 3 → 7 → 11 → 2 → 5 → 9 → 1 → 6 → 10 → 4 → 8 → (repeat)", bold: true, font: "Courier New", size: 22, color: "1F4E79" })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The counter is a MOD-12 counter; in other words, it is a 4-bit synchronous counter capable of traversing the given random sequence. The four state bits are Q\u2081, Q\u2082, Q\u2083, Q\u2084, where Q\u2081 is the Most Significant Bit (MSB) and Q\u2084 is the Least Significant Bit (LSB).", font: "Arial", size: 22 })]
      }),
      space(),

      // ============ TASK 1: STATE DIAGRAM ============
      new Paragraph({
        heading: HeadingLevel.HEADING_1,
        children: [new TextRun({ text: "Task 1: State Diagram and State Table", bold: true, font: "Arial", size: 28 })]
      }),
      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "1.1 State Diagram", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The state diagram depicts the cyclic transition of the counter through all 12 valid states. Each state is represented by its 4-bit binary equivalent, and directed arcs indicate the clock-triggered transitions between consecutive states.", font: "Arial", size: 22 })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 120, after: 60 },
        children: [new TextRun({ text: "0000 → 0011 → 0111 → 1011 → 0010 → 0101 → 1001 → 0001 → 0110 → 1010 → 0100 → 1000 → (repeat)", font: "Courier New", size: 20, color: "1F4E79", bold: true })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 40, after: 120 },
        children: [new TextRun({ text: "Figure: State Diagram of the MOD-12 Custom Sequence Counter", italics: true, font: "Arial", size: 20, color: "666666" })]
      }),

      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "1.2 State Table", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 120 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The state table below lists all 16 possible 4-bit combinations. The 12 valid states follow the defined sequence, while the 4 invalid states (highlighted in yellow) are forced to return to State 0 (0000) on the next clock cycle, implementing the self-correction mechanism.", font: "Arial", size: 22 })]
      }),
      buildStateTable(),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 80, after: 160 },
        children: [new TextRun({ text: "Table 1: State Table for MOD-12 Custom Sequence Counter (Yellow rows = Invalid states)", italics: true, font: "Arial", size: 20, color: "666666" })]
      }),
      space(),

      // ============ TASK 2: FLIP-FLOP SELECTION ============
      new Paragraph({
        heading: HeadingLevel.HEADING_1,
        children: [new TextRun({ text: "Task 2: Flip-Flop Selection and Justification", bold: true, font: "Arial", size: 28 })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [
          new TextRun({ text: "The selected flip-flop type for this design is the ", font: "Arial", size: 22 }),
          new TextRun({ text: "D Flip-Flop", bold: true, font: "Arial", size: 22 }),
          new TextRun({ text: ". For a D flip-flop, the excitation requirement is the simplest possible: the next state value is directly applied as the flip-flop input, i.e., D = Q\u207a. This makes the flip-flop input equations identical to the next-state equations.", font: "Arial", size: 22 }),
        ]
      }),
      space(),

      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "2.1 Power Consumption", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The D flip-flop consumes less power compared to the JK flip-flop because it has a simpler internal gate structure. The JK flip-flop requires additional feedback logic, which increases switching activity and power dissipation. In a synchronous design where all flip-flops are clocked simultaneously, the reduced gate count of D flip-flops directly translates to lower dynamic power consumption.", font: "Arial", size: 22 })]
      }),

      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "2.2 Circuit Complexity", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The D flip-flop requires the simplest excitation: the next state value is directly applied as input. This significantly simplifies the combinational logic design. In contrast, the JK flip-flop requires separate J and K excitation equations for each bit, and the T flip-flop demands XOR-based logic that adds considerable complexity for non-toggle sequences such as this custom counter.", font: "Arial", size: 22 })]
      }),

      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "2.3 Speed (Propagation Delay)", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The D flip-flop exhibits lower propagation delay because its input logic is straightforward with no feedback path. For a synchronous counter where all flip-flops are clocked simultaneously, minimizing propagation delay ensures reliable high-speed operation within a single clock period.", font: "Arial", size: 22 })]
      }),
      space(),

      // ============ TASK 3: EXCITATION EQUATIONS & KMAP ============
      new Paragraph({
        heading: HeadingLevel.HEADING_1,
        children: [new TextRun({ text: "Task 3: Excitation Equations and K-Map Minimization", bold: true, font: "Arial", size: 28 })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "Since the D flip-flop input is identical to the desired next state (D\u1d62 = Q\u1d62\u207a), the excitation equations are derived directly from the state table. Karnaugh maps (K-maps) are applied to minimize each excitation function using don't-care conditions for all four invalid states (states 12–15, where Q\u2081Q\u2082 = 11).", font: "Arial", size: 22 })]
      }),
      space(),

      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "3.1 Minimized Excitation Equations", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 60 },
        children: [new TextRun({ text: "After applying K-map minimization, the minimized Boolean expressions for each D flip-flop input are:", font: "Arial", size: 22 })]
      }),

      // Equations box
      new Paragraph({
        spacing: { before: 100, after: 60 },
        indent: { left: 720 },
        children: [new TextRun({ text: "D\u2081 = Q\u0305\u2081 \u00b7 Q\u2082", bold: true, font: "Courier New", size: 22, color: "1F4E79" })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 60 },
        indent: { left: 720 },
        children: [new TextRun({ text: "D\u2082 = Q\u0305\u2081Q\u0305\u2082Q\u2084 + Q\u0305\u2082Q\u2083Q\u0305\u2084", bold: true, font: "Courier New", size: 22, color: "1F4E79" })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 60 },
        indent: { left: 720 },
        children: [new TextRun({ text: "D\u2083 = Q\u0305\u2081Q\u0305\u2082Q\u0305\u2083 + Q\u0305\u2081Q\u2082Q\u2083 + Q\u0305\u2082Q\u2083Q\u2084", bold: true, font: "Courier New", size: 22, color: "1F4E79" })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 100 },
        indent: { left: 720 },
        children: [new TextRun({ text: "D\u2084 = Q\u2081Q\u0305\u2082Q\u0305\u2083Q\u2084 + Q\u0305\u2081Q\u0305\u2082Q\u0305\u2084 + Q\u0305\u2081Q\u2082Q\u2084 + Q\u0305\u2081Q\u2083Q\u2084", bold: true, font: "Courier New", size: 22, color: "1F4E79" })]
      }),

      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "3.2 K-Map Derivation Summary", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "Each 4-variable K-map is populated using Q\u2081Q\u2082 as row variables and Q\u2083Q\u2084 as column variables in standard Gray code order (00, 01, 11, 10). The four invalid states (Q\u2081Q\u2082 = 11) are treated as don't-care entries (X) to allow maximum grouping and minimal logic.", font: "Arial", size: 22 })]
      }),
      bullet("D\u2081 K-map: A single group of four 1-cells in the Q\u2081Q\u2082 = 01 row yields D\u2081 = Q\u0305\u2081Q\u2082."),
      bullet("D\u2082 K-map: Two groups are identified — a group of three 1-cells in the Q\u2083Q\u2084 = 01/11/10 columns of the 00-row, and one isolated 1-cell in the 10-row at Q\u2083Q\u2084 = 10, yielding D\u2082 = Q\u0305\u2081Q\u0305\u2082Q\u2084 + Q\u0305\u2082Q\u2083Q\u0305\u2084."),
      bullet("D\u2083 K-map: Three prime implicant groups cover all minterms, yielding D\u2083 = Q\u0305\u2081Q\u0305\u2082Q\u0305\u2083 + Q\u0305\u2081Q\u2082Q\u2083 + Q\u0305\u2082Q\u2083Q\u2084."),
      bullet("D\u2084 K-map: Four groups are required to cover all minterms, yielding the four-term expression for D\u2084."),
      space(),

      // ============ TASK 4: CIRCUIT DESIGN ============
      new Paragraph({
        heading: HeadingLevel.HEADING_1,
        children: [new TextRun({ text: "Task 4: Complete Circuit Design (Logisim Implementation)", bold: true, font: "Arial", size: 28 })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The complete synchronous MOD-12 counter circuit was implemented in Logisim using four D flip-flops labeled Q\u2081 (MSB) through Q\u2084 (LSB), and a combinational excitation logic network derived from the minimized Boolean expressions above. All flip-flops share a common clock signal, confirming the synchronous operation.", font: "Arial", size: 22 })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The combinational block implements D\u2081, D\u2082, D\u2083, D\u2084 using standard AND, OR, and NOT gates. The circuit faithfully produces the correct state transition at every rising clock edge, cycling through the 12 valid states in the prescribed sequence.", font: "Arial", size: 22 })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 100, after: 60 },
        children: [new TextRun({ text: "[Figure: MOD-12 Counter Design for the Given Sequence — Logisim Screenshot]", italics: true, font: "Arial", size: 20, color: "888888" })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 40, after: 80 },
        children: [new TextRun({ text: "[Figure: Timing Diagram of the MOD-12 Counter — Logisim Waveform]", italics: true, font: "Arial", size: 20, color: "888888" })]
      }),
      space(),

      // ============ TASK 5: INVALID STATE HANDLING ============
      new Paragraph({
        heading: HeadingLevel.HEADING_1,
        children: [new TextRun({ text: "Task 5: Invalid State Handling (Self-Correction Mechanism)", bold: true, font: "Arial", size: 28 })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The designed counter employs 4 flip-flops, yielding 2\u2074 = 16 possible binary state combinations. However, only 12 of these are utilized in the valid counting sequence (states 0 through 11). The remaining 4 states are invalid:", font: "Arial", size: 22 })]
      }),
      buildInvalidTable(),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 80, after: 160 },
        children: [new TextRun({ text: "Table 2: Invalid States and Their Forced Next-State Transitions", italics: true, font: "Arial", size: 20, color: "666666" })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "During power-up or due to electrical noise, the counter may accidentally enter one of these invalid states. To handle this robustly, all invalid states are forced to transition to State 0 (0000) on the next clock cycle.", font: "Arial", size: 22 })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "From the excitation equations, it is observed that whenever Q\u2081Q\u2082 = 11 (i.e., any of the four invalid states), all flip-flop inputs D\u2081, D\u2082, D\u2083, D\u2084 evaluate to 0. Consequently, on the next clock edge, the counter unconditionally transitions to 0000. This built-in self-correction mechanism ensures that no invalid state will cause a permanent fault or erroneous sequence in the counter operation.", font: "Arial", size: 22 })]
      }),
      space(),

      // ============ TASK 6: ANALYSIS ============
      new Paragraph({
        heading: HeadingLevel.HEADING_1,
        children: [new TextRun({ text: "Task 6: Analysis and Comparison", bold: true, font: "Arial", size: 28 })]
      }),

      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "6.1 Fan-Out Analysis", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "Fan-out refers to the maximum number of gate inputs that a single gate output can reliably drive while maintaining valid logic levels without signal degradation. In this MOD-12 counter, each flip-flop output feeds directly into the combinational excitation logic. Inspecting the excitation equations:", font: "Arial", size: 22 })]
      }),
      buildFanOutTable(),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 80, after: 160 },
        children: [new TextRun({ text: "Table 3: Fan-Out Demand per Flip-Flop Output", italics: true, font: "Arial", size: 20, color: "666666" })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "Q\u2081 and Q\u2082 appear in all four excitation equations, creating high fan-out demands on these outputs. In a physical CMOS implementation, buffering may be required for Q\u2081 and Q\u2082 outputs to prevent signal degradation. Q\u2083 and Q\u2084, appearing in only three equations each, present moderate fan-out loads.", font: "Arial", size: 22 })]
      }),

      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "6.2 Propagation Delay", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "Propagation delay is the time elapsed between a change at the input and the corresponding change at the output of a logic gate or flip-flop. In a synchronous counter, the combinational logic must complete its computation within one clock period.", font: "Arial", size: 22 })]
      }),
      bullet("Among all excitation circuits, D\u2082 and D\u2084 contain the most gate levels, making them the critical paths of the circuit."),
      bullet("The D flip-flop contributes the lowest delay because it uses direct assignment (D = Q\u207a), requiring no intermediate state conversion logic."),
      bullet("The maximum operating frequency is constrained by: f\u2098\u2090\u02e3 = 1 / (t\u209a\u1d49 + t\u209c\u209f\u209c + t\u209c\u209a\u1d48), where t\u209a\u1d49 is the combinational propagation delay, t\u209c\u209f\u209c is the clock-to-Q delay of the flip-flop, and t\u209c\u209a\u1d48 is the setup time."),
      space(),

      new Paragraph({
        heading: HeadingLevel.HEADING_2,
        children: [new TextRun({ text: "6.3 Power Dissipation Trade-Offs", bold: true, font: "Arial", size: 24 })]
      }),
      new Paragraph({
        spacing: { before: 60, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "Dynamic power dissipation in CMOS logic is directly proportional to switching activity and gate count, given by P = \u03b1 \u00b7 C\u2097 \u00b7 V\u1d35\u1d35\u00b2 \u00b7 f, where \u03b1 is the activity factor.", font: "Arial", size: 22 })]
      }),
      bullet("D flip-flops use the least combinational logic due to their direct-assignment nature, minimizing the activity factor \u03b1 and total capacitance C\u2097."),
      bullet("JK flip-flops contain internal feedback gates that switch even during no-change conditions, creating unnecessary switching activity and increased power dissipation."),
      bullet("T flip-flops require XOR-based logic, which adds complexity and higher switching activity for non-toggle sequences such as this custom counter."),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "Overall, the D flip-flop offers the best balance of low power consumption, minimal circuit complexity, and fast propagation for this custom MOD-12 synchronous counter design.", bold: false, font: "Arial", size: 22 })]
      }),
      space(),
      divider(),

      // ============ DESIGN JUSTIFICATION REPORT ============
      new Paragraph({
        heading: HeadingLevel.HEADING_1,
        children: [new TextRun({ text: "Design Justification Report", bold: true, font: "Arial", size: 28 })]
      }),
      new Paragraph({
        spacing: { before: 80, after: 80 },
        alignment: AlignmentType.JUSTIFIED,
        children: [new TextRun({ text: "The design of the synchronous MOD-12 custom sequence counter satisfies all requirements specified in the assignment. The following summarizes the key design decisions:", font: "Arial", size: 22 })]
      }),
      numbered("Flip-Flop Selection: D flip-flops were selected over JK and T alternatives based on their superior performance across all three evaluation criteria: power consumption, circuit complexity, and propagation delay."),
      numbered("State Encoding: Natural binary encoding is used, with Q\u2081 as MSB and Q\u2084 as LSB, allowing direct implementation in Logisim and straightforward K-map analysis."),
      numbered("Excitation Logic Minimization: Karnaugh maps were applied with don't-care entries for the four invalid states, producing minimal Sum-of-Products (SOP) expressions that reduce gate count and interconnection."),
      numbered("Invalid State Handling: The self-correction mechanism is inherent in the minimized excitation equations — whenever Q\u2081Q\u2082 = 11, all D inputs evaluate to 0, forcing an unconditional return to State 0 on the next clock edge."),
      numbered("Circuit Implementation: The complete circuit was implemented and verified in Logisim, confirming correct state transitions across all 12 valid states and self-correction from all 4 invalid states."),
      numbered("Fan-Out Management: Q\u2081 and Q\u2082 exhibit high fan-out demand; in a physical implementation, output buffers would be recommended for these signals to maintain signal integrity."),
      space(),
      divider(),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 120, after: 0 },
        children: [new TextRun({ text: "— End of Assignment —", italics: true, font: "Arial", size: 20, color: "888888" })]
      }),
    ]
  }]
});

Packer.toBuffer(doc).then(buffer => {
  fs.writeFileSync("/Users/tamimiqbal/Developer/cp-code/Al_Aqsa/DLD_Assignment_Q1.docx", buffer);
  console.log("Done!");
});
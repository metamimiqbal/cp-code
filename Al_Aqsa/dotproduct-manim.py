"""
Dot Product — Comprehensive Manim Animation
============================================
Teaches:
  1. What vectors are (brief recap)
  2. How dot product "collapses" two vectors into one number
  3. Geometric intuition: projection and directional alignment
  4. The formula:  a·b = |a||b|cos(θ)  and  a·b = ax*bx + ay*by
  5. Edge cases: parallel (max), perpendicular (zero), anti-parallel (negative)

Run with:
    manim -pql dot_product.py DotProductScene       # low quality preview
    manim -pqh dot_product.py DotProductScene       # high quality
"""

from manim import *
import numpy as np


# ── colour palette ──────────────────────────────────────────────────────────
C_BG        = "#0D1117"   # near-black background
C_GRID      = "#1E2A38"   # subtle grid
C_A         = "#58A6FF"   # vector a  (blue)
C_B         = "#F0883E"   # vector b  (orange)
C_PROJ      = "#3DDC97"   # projection (teal)
C_ANGLE     = "#FF7B72"   # angle arc  (red-ish)
C_SCALAR    = "#E8C76B"   # result scalar (gold)
C_TEXT      = "#C9D1D9"   # body text
C_HIGHLIGHT = "#FFFFFF"   # white highlight

config.background_color = C_BG


# ── helpers ──────────────────────────────────────────────────────────────────
def vec_arrow(start, end, color, buff=0, tip_length=0.22, stroke=4):
    return Arrow(
        start, end, color=color,
        buff=buff,
        tip_length=tip_length,
        stroke_width=stroke,
        max_tip_length_to_length_ratio=0.4,
    )


def label_vector(tex, arrow, direction=UP, color=WHITE, scale=0.7, buff=0.18):
    lbl = MathTex(tex, color=color).scale(scale)
    lbl.next_to(arrow.get_center(), direction, buff=buff)
    return lbl


# ════════════════════════════════════════════════════════════════════════════
class DotProductScene(Scene):
    """Full dot-product lesson — ~3 min at normal speed."""

    # ── scene entry point ────────────────────────────────────────────────────
    def construct(self):
        self.scene_01_title()
        self.scene_02_vectors_recap()
        self.scene_03_two_numbers_one_number()
        self.scene_04_formula_algebraic()
        self.scene_05_geometric_projection()
        self.scene_06_angle_formula()
        self.scene_07_alignment_demo()
        self.scene_08_summary()

    # ────────────────────────────────────────────────────────────────────────
    # 01 · TITLE
    # ────────────────────────────────────────────────────────────────────────
    def scene_01_title(self):
        title = Text("The Dot Product", font_size=72,
                     color=C_HIGHLIGHT, weight=BOLD)
        subtitle = Text("How two vectors collapse into one number",
                        font_size=32, color=C_TEXT)
        subtitle.next_to(title, DOWN, buff=0.5)

        # decorative arrows
        a_arrow = vec_arrow(LEFT * 3.5 + DOWN * 1.8, LEFT * 1.5 + DOWN * 1.8,
                            C_A, stroke=6)
        b_arrow = vec_arrow(LEFT * 3.5 + DOWN * 2.5, RIGHT * 0 + DOWN * 1.8,
                            C_B, stroke=6)
        dot_sym = MathTex(r"\vec{a} \cdot \vec{b} = \text{scalar}",
                          color=C_SCALAR, font_size=36)
        dot_sym.to_edge(DOWN, buff=0.6)

        self.play(Write(title), run_time=1.2)
        self.play(FadeIn(subtitle, shift=UP * 0.3), run_time=0.8)
        self.play(GrowArrow(a_arrow), GrowArrow(b_arrow), run_time=1)
        self.play(Write(dot_sym), run_time=1)
        self.wait(1)
        self.play(FadeOut(Group(title, subtitle, a_arrow, b_arrow, dot_sym)))

    # ────────────────────────────────────────────────────────────────────────
    # 02 · QUICK VECTORS RECAP
    # ────────────────────────────────────────────────────────────────────────
    def scene_02_vectors_recap(self):
        header = Text("Quick Recap: Vectors", font_size=44,
                      color=C_HIGHLIGHT).to_edge(UP, buff=0.4)
        self.play(Write(header))

        axes = Axes(
            x_range=[-0.5, 5, 1], y_range=[-0.5, 4, 1],
            x_length=5, y_length=4,
            axis_config={"color": C_GRID, "stroke_width": 2},
        ).shift(DOWN * 0.5)

        origin = axes.get_origin()

        # vector a = (3, 2)
        a_end = axes.c2p(3, 2)
        a_arr = vec_arrow(origin, a_end, C_A, stroke=5)
        a_lbl = MathTex(r"\vec{a} = \begin{pmatrix}3\\2\end{pmatrix}",
                        color=C_A, font_size=32).next_to(a_arr, UP + RIGHT, buff=0.1)

        # vector b = (1, 3)
        b_end = axes.c2p(1, 3)
        b_arr = vec_arrow(origin, b_end, C_B, stroke=5)
        b_lbl = MathTex(r"\vec{b} = \begin{pmatrix}1\\3\end{pmatrix}",
                        color=C_B, font_size=32).next_to(b_arr, LEFT, buff=0.15)

        # dashed component lines for a
        ax_dash = DashedLine(a_end, axes.c2p(3, 0),
                             color=C_A, stroke_width=1.5, dash_length=0.12)
        ay_dash = DashedLine(a_end, axes.c2p(0, 2),
                             color=C_A, stroke_width=1.5, dash_length=0.12)
        ax_lbl = MathTex("a_x=3", color=C_A, font_size=22).next_to(axes.c2p(3, 0), DOWN, 0.1)
        ay_lbl = MathTex("a_y=2", color=C_A, font_size=22).next_to(axes.c2p(0, 2), LEFT, 0.1)

        note = Text("A vector has direction AND magnitude",
                    font_size=26, color=C_TEXT).to_edge(DOWN, buff=0.3)

        self.play(Create(axes))
        self.play(GrowArrow(a_arr), Write(a_lbl))
        self.play(GrowArrow(b_arr), Write(b_lbl))
        self.play(Create(ax_dash), Create(ay_dash),
                  Write(ax_lbl), Write(ay_lbl))
        self.play(Write(note))
        self.wait(1.5)
        self.play(FadeOut(Group(header, axes, a_arr, a_lbl, b_arr, b_lbl,
                                ax_dash, ay_dash, ax_lbl, ay_lbl, note)))

    # ────────────────────────────────────────────────────────────────────────
    # 03 · TWO NUMBERS → ONE NUMBER (visual compression)
    # ────────────────────────────────────────────────────────────────────────
    def scene_03_two_numbers_one_number(self):
        header = Text("Two Vectors → One Number",
                      font_size=44, color=C_HIGHLIGHT).to_edge(UP, buff=0.4)
        self.play(Write(header))

        # draw the two component boxes
        a_box = RoundedRectangle(width=2.6, height=1.6,
                                 corner_radius=0.15, color=C_A, stroke_width=2)
        a_box.shift(LEFT * 4)
        a_tex = MathTex(r"\vec{a}=\begin{pmatrix}3\\2\end{pmatrix}",
                        color=C_A, font_size=34).move_to(a_box)

        b_box = RoundedRectangle(width=2.6, height=1.6,
                                 corner_radius=0.15, color=C_B, stroke_width=2)
        b_box.shift(LEFT * 1)
        b_tex = MathTex(r"\vec{b}=\begin{pmatrix}1\\3\end{pmatrix}",
                        color=C_B, font_size=34).move_to(b_box)

        dot_op = MathTex(r"\cdot", color=C_TEXT, font_size=60).shift(LEFT * 2.5)

        # result box
        res_box = RoundedRectangle(width=2.4, height=1.6,
                                   corner_radius=0.15,
                                   color=C_SCALAR, stroke_width=2)
        res_box.shift(RIGHT * 3)
        res_tex = MathTex("9", color=C_SCALAR, font_size=60).move_to(res_box)
        res_label = Text("scalar", color=C_SCALAR, font_size=22)\
            .next_to(res_box, DOWN, buff=0.2)

        arrow_result = vec_arrow(LEFT * 2.1, RIGHT * 1.7, C_TEXT, stroke=3)

        calc = MathTex(
            r"3 \times 1 \;+\; 2 \times 3 \;=\; 3 + 6 \;=\; 9",
            color=C_TEXT, font_size=30,
        ).shift(DOWN * 2.2)

        self.play(FadeIn(a_box), Write(a_tex))
        self.play(FadeIn(b_box), Write(b_tex))
        self.play(Write(dot_op))
        self.play(GrowArrow(arrow_result))
        self.play(FadeIn(res_box), Write(res_tex), Write(res_label))
        self.play(Write(calc), run_time=1.5)
        self.wait(2)
        self.play(FadeOut(Group(header, a_box, a_tex, b_box, b_tex,
                                dot_op, arrow_result, res_box, res_tex,
                                res_label, calc)))

    # ────────────────────────────────────────────────────────────────────────
    # 04 · ALGEBRAIC FORMULA
    # ────────────────────────────────────────────────────────────────────────
    def scene_04_formula_algebraic(self):
        header = Text("Algebraic Definition",
                      font_size=44, color=C_HIGHLIGHT).to_edge(UP, buff=0.4)
        self.play(Write(header))

        formula = MathTex(
            r"\vec{a} \cdot \vec{b}",
            r"= a_x b_x + a_y b_y",
            color=C_TEXT, font_size=48,
        ).shift(UP * 0.8)
        formula[0].set_color(C_HIGHLIGHT)
        formula[1].set_color(C_TEXT)

        # annotate components
        ax_brace = Brace(formula[1][1:3], DOWN, color=C_A)
        bx_brace = Brace(formula[1][3:5], DOWN, color=C_B)
        ay_brace = Brace(formula[1][6:8], DOWN, color=C_A)
        by_brace = Brace(formula[1][8:], DOWN, color=C_B)

        ax_note = ax_brace.get_tex(r"a_x").set_color(C_A)
        bx_note = bx_brace.get_tex(r"b_x").set_color(C_B)
        ay_note = ay_brace.get_tex(r"a_y").set_color(C_A)
        by_note = by_brace.get_tex(r"b_y").set_color(C_B)

        example = MathTex(
            r"\begin{pmatrix}3\\2\end{pmatrix} \cdot \begin{pmatrix}1\\3\end{pmatrix}"
            r"= (3)(1) + (2)(3) = 3 + 6 = \mathbf{9}",
            color=C_TEXT, font_size=32,
        ).shift(DOWN * 2.0)
        example[-1].set_color(C_SCALAR)

        self.play(Write(formula), run_time=1.5)
        self.wait(0.5)
        self.play(
            Create(ax_brace), Create(bx_brace),
            Create(ay_brace), Create(by_brace),
            Write(ax_note), Write(bx_note),
            Write(ay_note), Write(by_note),
            run_time=1.2,
        )
        self.play(Write(example), run_time=1.5)
        self.wait(2)
        self.play(FadeOut(Group(header, formula,
                                ax_brace, bx_brace, ay_brace, by_brace,
                                ax_note, bx_note, ay_note, by_note, example)))

    # ────────────────────────────────────────────────────────────────────────
    # 05 · GEOMETRIC PROJECTION
    # ────────────────────────────────────────────────────────────────────────
    def scene_05_geometric_projection(self):
        header = Text("Geometric Meaning: Projection",
                      font_size=40, color=C_HIGHLIGHT).to_edge(UP, buff=0.35)
        self.play(Write(header))

        axes = NumberPlane(
            x_range=[-1, 5], y_range=[-1, 4],
            background_line_style={"stroke_color": C_GRID,
                                   "stroke_width": 1,
                                   "stroke_opacity": 0.5},
            axis_config={"stroke_color": C_GRID},
        ).scale(0.85).shift(LEFT * 0.5 + DOWN * 0.5)
        self.play(Create(axes), run_time=0.8)

        origin = axes.c2p(0, 0)
        a_pt   = axes.c2p(4, 0)     # a = (4,0) horizontal for clarity
        b_pt   = axes.c2p(2, 3)     # b = (2,3)

        a_arr = vec_arrow(origin, a_pt, C_A, stroke=5)
        b_arr = vec_arrow(origin, b_pt, C_B, stroke=5)
        a_lbl = MathTex(r"\vec{a}", color=C_A, font_size=34)\
            .next_to(a_arr, DOWN, buff=0.15)
        b_lbl = MathTex(r"\vec{b}", color=C_B, font_size=34)\
            .next_to(b_arr, LEFT, buff=0.1)

        self.play(GrowArrow(a_arr), GrowArrow(b_arr),
                  Write(a_lbl), Write(b_lbl))

        # projection of b onto a
        a_vec  = np.array([4, 0, 0])
        b_vec  = np.array([2, 3, 0])
        a_unit = a_vec / np.linalg.norm(a_vec)
        proj_scalar = np.dot(b_vec, a_unit)          # = 2
        proj_pt = axes.c2p(proj_scalar, 0)

        proj_arr = vec_arrow(origin, proj_pt, C_PROJ, stroke=5)
        proj_lbl = MathTex(r"\text{proj}_{\vec{a}}\vec{b}",
                           color=C_PROJ, font_size=28)\
            .next_to(proj_arr, DOWN, buff=0.25)

        # perpendicular drop line
        drop = DashedLine(axes.c2p(proj_scalar, 0), b_pt,
                          color=C_PROJ, stroke_width=2, dash_length=0.15)

        right_angle = RightAngle(
            Line(b_pt, axes.c2p(proj_scalar, 0)),
            Line(axes.c2p(proj_scalar, 0), origin),
            length=0.2, color=C_PROJ
        )

        explanation = MathTex(
            r"\vec{a} \cdot \vec{b} = |\vec{a}|\,\underbrace{|\vec{b}|\cos\theta"
            r"}_{\text{projection of }\vec{b}\text{ onto }\vec{a}}",
            color=C_TEXT, font_size=28,
        ).to_edge(RIGHT, buff=0.3).shift(UP * 0.4)

        self.play(Create(drop), Create(right_angle))
        self.play(GrowArrow(proj_arr), Write(proj_lbl))
        self.play(Write(explanation), run_time=1.5)
        self.wait(2)
        self.play(FadeOut(Group(header, axes, a_arr, b_arr, a_lbl, b_lbl,
                                drop, right_angle, proj_arr, proj_lbl,
                                explanation)))

    # ────────────────────────────────────────────────────────────────────────
    # 06 · ANGLE FORMULA   a·b = |a||b|cosθ
    # ────────────────────────────────────────────────────────────────────────
    def scene_06_angle_formula(self):
        header = Text("The Angle Formula",
                      font_size=44, color=C_HIGHLIGHT).to_edge(UP, buff=0.35)
        self.play(Write(header))

        formula = MathTex(
            r"\vec{a} \cdot \vec{b} = |\vec{a}|\,|\vec{b}|\,\cos\theta",
            color=C_TEXT, font_size=50,
        ).shift(UP * 1.8)

        # annotation table
        rows = VGroup(
            MathTex(r"|\vec{a}|", r"\text{ — magnitude of } \vec{a}",
                    color=C_A, font_size=30),
            MathTex(r"|\vec{b}|", r"\text{ — magnitude of } \vec{b}",
                    color=C_B, font_size=30),
            MathTex(r"\cos\theta",
                    r"\text{ — how aligned they are (-1 to +1)}",
                    color=C_ANGLE, font_size=30),
        )
        for i, row in enumerate(rows):
            row.arrange(RIGHT, buff=0.3)
            row.shift(DOWN * (0.3 + i * 0.85))

        # cos range bar
        bar_bg = RoundedRectangle(width=6, height=0.4,
                                  corner_radius=0.2, color=C_GRID,
                                  fill_opacity=1, stroke_width=0).shift(DOWN * 3.1)
        bar_fill = bar_bg.copy().set_fill(
            C_SCALAR,
            opacity=1,
        ).stretch(1, 0)
        label_neg = MathTex(r"\cos\theta=-1", color=C_ANGLE, font_size=22)\
            .next_to(bar_bg, LEFT, buff=0.2)
        label_zero = MathTex(r"0", color=C_TEXT, font_size=22)\
            .next_to(bar_bg, DOWN, buff=0.1)
        label_pos = MathTex(r"\cos\theta=+1", color=C_A, font_size=22)\
            .next_to(bar_bg, RIGHT, buff=0.2)

        self.play(Write(formula), run_time=1)
        for row in rows:
            self.play(Write(row), run_time=0.7)
        self.play(FadeIn(bar_bg), FadeIn(bar_fill),
                  Write(label_neg), Write(label_zero), Write(label_pos))
        self.wait(2)
        self.play(FadeOut(Group(header, formula, rows,
                                bar_bg, bar_fill,
                                label_neg, label_zero, label_pos)))

    # ────────────────────────────────────────────────────────────────────────
    # 07 · ALIGNMENT DEMO  (rotate b and watch dot product change)
    # ────────────────────────────────────────────────────────────────────────
    def scene_07_alignment_demo(self):
        header = Text("Direction Alignment Demo",
                      font_size=40, color=C_HIGHLIGHT).to_edge(UP, buff=0.35)
        self.play(Write(header))

        axes = Axes(
            x_range=[-3.5, 3.5], y_range=[-3, 3],
            x_length=6, y_length=5,
            axis_config={"color": C_GRID, "stroke_width": 2},
        ).shift(LEFT * 0.8 + DOWN * 0.2)
        self.play(Create(axes))

        origin = axes.get_origin()
        a_fixed = np.array([2.5, 0, 0])           # fixed horizontal
        a_end   = axes.c2p(*a_fixed[:2])

        a_arr = vec_arrow(origin, a_end, C_A, stroke=5)
        a_lbl = MathTex(r"\vec{a}", color=C_A, font_size=32)\
            .next_to(a_arr, DOWN, buff=0.2)
        self.play(GrowArrow(a_arr), Write(a_lbl))

        # info panel on the right
        angle_disp = MathTex(r"\theta = 0°", color=C_TEXT, font_size=30)\
            .to_edge(RIGHT, buff=0.4).shift(UP * 2.2)
        dot_disp   = MathTex(r"\vec{a}\cdot\vec{b} = 6.25", color=C_SCALAR,
                             font_size=30).next_to(angle_disp, DOWN, buff=0.5)
        meaning    = Text("Same direction → max value",
                         font_size=22, color=C_PROJ)\
            .next_to(dot_disp, DOWN, buff=0.5)

        self.play(Write(angle_disp), Write(dot_disp), Write(meaning))

        b_mag = 2.5
        b_angle_tracker = ValueTracker(0)

        def get_b_end():
            theta = b_angle_tracker.get_value()
            bx = b_mag * np.cos(theta)
            by = b_mag * np.sin(theta)
            return axes.c2p(bx, by)

        b_arr = always_redraw(
            lambda: vec_arrow(origin, get_b_end(), C_B, stroke=5)
        )
        b_lbl = always_redraw(
            lambda: MathTex(r"\vec{b}", color=C_B, font_size=32)
            .next_to(get_b_end(), UP + RIGHT, buff=0.1)
        )

        def update_angle_disp(mob):
            theta_deg = np.degrees(b_angle_tracker.get_value()) % 360
            mob.become(
                MathTex(rf"\theta = {theta_deg:.0f}°",
                        color=C_TEXT, font_size=30)
                .to_edge(RIGHT, buff=0.4).shift(UP * 2.2)
            )

        def update_dot_disp(mob):
            theta = b_angle_tracker.get_value()
            val = (b_mag * 2.5) * np.cos(theta)      # |a|=2.5, |b|=2.5
            mob.become(
                MathTex(rf"\vec{{a}}\cdot\vec{{b}} = {val:.2f}",
                        color=C_SCALAR, font_size=30)
                .next_to(angle_disp, DOWN, buff=0.5)
            )

        def update_meaning(mob):
            theta = b_angle_tracker.get_value() % (2 * PI)
            if theta < PI / 6:
                txt, col = "Same direction → max value",    C_PROJ
            elif theta < PI / 2 + 0.1:
                txt, col = "Diverging → value shrinks",     C_TEXT
            elif abs(theta - PI / 2) < 0.15:
                txt, col = "Perpendicular → zero!",         C_ANGLE
            elif theta < PI - 0.1:
                txt, col = "Diverging more → negative",     C_B
            elif abs(theta - PI) < 0.2:
                txt, col = "Opposite direction → minimum",  "#FF7B72"
            else:
                txt, col = "Swinging back…",                C_TEXT
            mob.become(
                Text(txt, font_size=22, color=col)
                .next_to(dot_disp, DOWN, buff=0.5)
            )

        angle_disp.add_updater(update_angle_disp)
        dot_disp.add_updater(update_dot_disp)
        meaning.add_updater(update_meaning)

        self.add(b_arr, b_lbl)

        # ── rotation sequence ──
        # 1. parallel  (θ = 0)
        self.wait(0.8)
        # 2. rotate to 90° (perpendicular)
        self.play(b_angle_tracker.animate.set_value(PI / 2),
                  run_time=2.5, rate_func=smooth)
        self.wait(0.8)
        # 3. rotate to 180° (anti-parallel)
        self.play(b_angle_tracker.animate.set_value(PI),
                  run_time=2.5, rate_func=smooth)
        self.wait(0.8)
        # 4. rotate all the way around back to ~30°
        self.play(b_angle_tracker.animate.set_value(PI / 6),
                  run_time=3, rate_func=smooth)
        self.wait(1)

        angle_disp.clear_updaters()
        dot_disp.clear_updaters()
        meaning.clear_updaters()

        self.play(FadeOut(Group(header, axes, a_arr, a_lbl, b_arr, b_lbl,
                                angle_disp, dot_disp, meaning)))

    # ────────────────────────────────────────────────────────────────────────
    # 08 · SUMMARY CARD
    # ────────────────────────────────────────────────────────────────────────
    def scene_08_summary(self):
        header = Text("Summary", font_size=52,
                      color=C_HIGHLIGHT, weight=BOLD).to_edge(UP, buff=0.4)
        self.play(Write(header))

        items = [
            (r"\vec{a}\cdot\vec{b} = a_xb_x + a_yb_y",
             "Algebraic: multiply matching components, sum them", C_A),
            (r"\vec{a}\cdot\vec{b} = |\vec{a}||\vec{b}|\cos\theta",
             "Geometric: magnitudes × cosine of angle between them", C_B),
            (r"\theta=0° \;\Rightarrow\; \text{dot} = |\vec{a}||\vec{b}|",
             "Parallel vectors → maximum (fully aligned)", C_PROJ),
            (r"\theta=90° \;\Rightarrow\; \text{dot} = 0",
             "Perpendicular vectors → zero (no shared direction)", C_ANGLE),
            (r"\theta=180° \;\Rightarrow\; \text{dot} = -|\vec{a}||\vec{b}|",
             "Anti-parallel vectors → most negative (fully opposed)", C_SCALAR),
        ]

        group = VGroup()
        for i, (formula, desc, col) in enumerate(items):
            f = MathTex(formula, color=col, font_size=26)
            d = Text(desc, font_size=20, color=C_TEXT)
            d.next_to(f, RIGHT, buff=0.35)
            row = VGroup(f, d).shift(DOWN * (0.3 + i * 0.95) + UP * 0.5)
            group.add(row)

        for row in group:
            self.play(FadeIn(row, shift=RIGHT * 0.3), run_time=0.55)

        takeaway = Text(
            "The dot product measures how much two vectors\n"
            "point in the same direction.",
            font_size=26, color=C_HIGHLIGHT,
            line_spacing=1.3,
        ).to_edge(DOWN, buff=0.35)
        box = SurroundingRectangle(takeaway, color=C_SCALAR,
                                   corner_radius=0.15, buff=0.2)
        self.play(Write(takeaway), Create(box), run_time=1.5)
        self.wait(3)
        self.play(FadeOut(Group(header, group, takeaway, box)))

        # ── final flourish ──
        end = Text("Dot Product", font_size=60,
                   color=C_HIGHLIGHT, weight=BOLD)
        sub = MathTex(r"\vec{a}\cdot\vec{b} = |\vec{a}||\vec{b}|\cos\theta",
                      color=C_SCALAR, font_size=42)
        sub.next_to(end, DOWN, buff=0.5)
        self.play(Write(end), Write(sub), run_time=1.5)
        self.wait(2)
        self.play(FadeOut(Group(end, sub))) 
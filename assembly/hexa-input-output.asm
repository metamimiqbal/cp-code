
.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    XOR BX, BX
; ---------- HEX INPUT ----------
INP:
    MOV AH, 01H
    INT 21H
    CMP AL, 0DH
    JE OUTPUT
    CMP AL, '9'
    JBE DIGIT_IN
    SUB AL, 07H
DIGIT_IN:
    SUB AL, 30H
    SHL BX, 4
    OR  BL, AL
    JMP INP
; ---------- HEX OUTPUT ----------
OUTPUT:
    XOR CX, CX
DIVIDING:
    MOV AX, BX
    XOR DX, DX
    MOV SI, 16
    DIV SI              ; AX = quotient, DX = remainder
    PUSH DX
    INC CX
    MOV BX, AX
    CMP BX, 0
    JNE DIVIDING
PRINTING:
    POP DX
    CMP DL, 9
    JBE NUMBER
    ADD DL, 37H         ; 10–15 -> A–F
    JMP PRINT
NUMBER:
    ADD DL, 30H         ; 0–9 -> ASCII
PRINT:
    MOV AH, 02H
    INT 21H
    LOOP PRINTING
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN


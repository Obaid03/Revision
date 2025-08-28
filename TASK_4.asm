COMMENT!
TASK-4
A hardware counter records values: 11010110b – 9C4h + 220 + 18 +
1011110b – D + 12. Write Assembly code to calculate the result.


INCLUDE Irvine32.inc

.data
    counter DWORD ?
    var1 DWORD 11010110b       ; binary notation (214 decimal)
    var2 DWORD 09C4h           ; hex 9C4 = 2500 decimal
    var3 DWORD 220
    var4 DWORD 18
    var5 DWORD 1011110b        ; binary notation (94 decimal)
    var6 DWORD 0Dh             ; hex D = 13 decimal
    var7 DWORD 12

.code
main PROC
    mov eax, var1          ; eax = var1
    sub eax, var2          ; eax = var1 - var2
    add eax, var3          ; eax += var3
    add eax, var4          ; eax += var4
    add eax, var5          ; eax += var5
    sub eax, var6          ; eax -= var6
    add eax, var7          ; eax += var7

    mov counter, eax       ; store final result in counter

    call WriteDec          ; print eax as decimal
    
    call Crlf              ; new line
    call WriteInt           ; print eax as decimal

main ENDP
END main !

COMMENT!
TASK-4
A hardware counter records values: 11010110b – 9C4h + 220 + 18 +
1011110b – D + 12. Write Assembly code to calculate the result.!


INCLUDE Irvine32.inc

.data
    counter DWORD ?

.code
main PROC

    mov eax,11010110b
    sub eax,9C4h
    add eax,220
    add eax,18
    add eax,1011110b
    sub eax,Dh
    add eax,12

    mov counter, eax       ; store final result in counter

    call WriteDec          ; print eax as decimal
    
    call Crlf              ; new line
    call WriteInt           ; print eax as decimal

main ENDP

END main

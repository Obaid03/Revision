COMMENT!
BYTE or BW 8 BIT	;Data Types
WORD or DW 16 BIT	;Data Types
DWORD or DD 32 BIT	;Data Types
!
INCLUDE Irvine 
. data
	
	COMMENT! Variable Definition & Initialization inside .data !
	OBAID BW ?		;Uninitialized
	var0 DW ?		;Uninitialized
	var1 DWORD 12Ah ;Hexa-Decimal
	var2 DD  0Fh	;Hexa-Decimal
	var3 DD 7o		;Octal
	var4 DD 25		;Decimal
	var5 SDWORD -39	;Signed Decimal Number
	vaR6 DD 66		;By default Decimal
	var7 DD 10101	;Binary
	var8 BW 'A'		;Single Character ALways in BYTE
	var9 BYTE "HEllo World" ;String
	msg BYTE "HEllo World",0 ;0 --> null termintaor
	

.code
main PROC
	Count=500  ;can also initialize like this
	mov eax,10
	mov ebx,15
	imul eax,eab  	;For multiplication b/w 2 registers
	imul eax		;will multiply eax with 10
	INC eax			;will increment with 1
	Dec eax			;will decrement with 1

	movzx ; mov zero extended(will take only positive)

	mov bx,6
	movzx eax,bx  ;movzx is applicable for all size of registers (8 to 16/32 || 16 to 32)
	
	mov bx,A69Bh
	movzx eax,bx    ;8 bit to 1 or 32 bit will add zero  (zero e.g: 0000-->A69Bh)
	movzx ecx, bh
	movzx ebx,bl

	1 byte = 8 bits
	1 nibble= 4 bits =each hexadecimal character=half byte

	movsx  ; mov sign extended(will take negative and positive both)
	;movsx will convert 0 to F or 1.

	mov bx,A69Bh
	movsx eax,bx    ;8 bit to 1 or 32 bit  will  F or 1(zero e.g: FFFF-->A69Bh)
	movsx ecx, bh
	movsx ebx,bl

	"xchg"

	mov eax,6
	mov ebx,15
	xchg eax,ebx  ;will swap values of Registers (should be of same size)

	"Neg"
	mov eax,6
	Neg eax  	;will negate the value in eax

	;Similar To MAIN FUNCTION(C++)
	call DumpRegs ;Prints the value for all registers
	mov edx, OFFSET msg		;offset moves address of msg to edx / Only have to store in edx
	call WriteString
	call WriteInt
	call DumpRegs         	;will print all registers
	

exit
main ENDP
END main

COMMENT!
THis is A block Comment!

;Inline Comment
!

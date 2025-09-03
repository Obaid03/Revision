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
	;Similar To MAIN FUNCTION(C++)
	call DumpRegs ;Prints the value for all registers
	mov edx, OFFSET msg		;offset moves address of msg to edx / Only have to store in edx
	call WriteString

	

exit
main ENDP
END main

COMMENT!
THis is A block Comment!

;Inline Comment
!

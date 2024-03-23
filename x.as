.define sz = 2
MAIN: mov r3, LIST[sz]
LOOP: jmp L1
	mcr my_mcr
	cmp r3, #sz
	bne END
	endmcr
	mcr my_mcr2
	mov STR[3] , STR[5]
	endmcr
	mov STR[5], STR[2]
	sub r1, r4
	prn #-5
	my_mcr
	my_mcr2
L1: inc K
	bne LOOP
END: hlt
.define len = 4
STR: .string 
LIST: .data 6, -9, len
K: .data 22

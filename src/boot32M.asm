mainSector:

BITS 32

_bootMain:

	call _run

_run:

	mov esp, StackTop
	
	extern startup
	call startup

_haltSystem:

	cli
	jmp $

section .bss

	align 4

StackBottom: equ $

	resb 16384

StackTop:
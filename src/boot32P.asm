section .btldr

BITS 16								 

    global _btldr_start

_btldr_start:

	mov ax, 0x2401
	int 0x15

	mov ax, 0x3
	int 0x10

	mov [disk], dl

	mov ah, 0x2    			
	mov al, 6      			        
	mov ch, 0      			
	mov dh, 0      			
	mov cl, 2      			
	mov dl, [disk] 			
	mov bx, mainSector	
	int 0x13
    
	cli

	lgdt [GDTablePointer]
	mov eax, cr0
	or eax, 0x1
	mov cr0, eax

    mov ax, DATA_SEG
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax

	jmp CODE_SEG: _printMessage

GDTableStart:

	dq 0x0

GDTableCode:

	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10011010b
	db 11001111b
	db 0x0

GDTableData:

	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0

GDTableEnd:

GDTablePointer:

	dw GDTableEnd - GDTableStart
	dd GDTableStart

disk:

	db 0x0

CODE_SEG equ GDTableCode - GDTableStart
DATA_SEG equ GDTableData - GDTableStart

BITS 32                    

_printMessage:

	mov esi, message
	mov ebx, 0xb8000
	
_printingLoop:

	lodsb

    cmp al, 0           
	je _goMain

	or eax, 0x0e00          
	mov word [ebx], ax
	add ebx, 2
    
	jmp _printingLoop

_goMain:

	jmp CODE_SEG: _bootMain

message: 
    
    db "[MODE] x32/PROTECTED", 0

    times 510 - ($ - $$) db 0
    dw 0xaa55

%include "boot32M.asm"
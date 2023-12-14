.MODEL SMALL
.STACK 100h

.DATA
str1 DB "Hello world$", 0
str2 DB "e", 0
str3 DB "found$", 0
str4 DB "not found$", 0

.CODE
start:
    mov ax, @data
    mov ds, ax

    mov cx, 11
    lea di, str1
    mov al, 'e'
    repne scasb 
    jnz notfound

    mov ah, 09h
    lea dx, str3
    int 21h
    jmp endprog

notfound:
    mov ah, 09h
    lea dx, str4
    int 21h

endprog:
    mov ah, 4Ch
    int 21h

END start

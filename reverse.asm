.model small
.stack 100h
.data
    originalString db "hello world!$"
    stringLength   dw 12 
    reversedString db 13 dup(0)
.code
main proc
    mov ax, @data
    mov ds, ax

    lea si, originalString
    lea di, reversedString

    mov cx, stringLength
    add si, cx 

    reverse_loop:
        dec si
        mov al, [si]
        mov [di], al
        inc di
    loop reverse_loop

    mov byte ptr [di], '$'

    mov ah, 09h
    lea dx, reversedString
    int 21h 


    mov ax, 4c00h
    int 21h
main endp
end main

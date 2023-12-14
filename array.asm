.model small
.data
string1 db "Enter string....: $"
string2 db "String is....: $"
string3 db "Length is....: $"
enter db 0ah,0dh, "$"
len db 0
str db 11 dup(?)

.code
mov ax,@data
mov ds,ax

mov ah,09h
mov dx,offset string1
int 21h

mov cx,10
mov si,offset str


input:
    mov ah,01h
    int 21h
    mov [si],al
    cmp al,0dh
    je exitloop
    inc si 
    inc len 
loop input


exitloop:

mov bl,"$"
mov[si],bl
mov ah,09h
mov dx,offset enter
int 21h




mov ah,09h
mov dx,offset string2
int 21h

mov ah,09h
mov dx,offset str
int 21h

mov ah,09h
mov dx,offset enter
int 21h



mov ah,09h
mov dx,offset string3
int 21h


add len,48
mov ah,02h
mov dl,len
int 21h

mov ah,04ch
int 21h
end
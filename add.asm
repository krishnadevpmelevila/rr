.model small
.data
string1 db "enter num1: $"
string2 db "enter num2: $"
string3 db "enter num3: $"

.code
mov ax,@data
mov ds,ax

mov ah,09h
mov dx,offset string1
int 21h

mov ah,01h
int 21h
mov bl,al

mov ah,09h
mov dx,offset string2
int 21h


mov ah,01h
int 21h
mov cl,al

add bl,cl
sub bl,48

mov dl,bl
mov ah,02h
int 21h

mov  ah,04ch
int 21h
end
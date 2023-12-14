.model small
.data
string1 db "Enter the letter: $"
string2 db "The capital letter is : $"
.code
mov ax,@data
mov ds,ax

mov  ah,09h
mov dx,offset string1
int 21h

mov ah,01h
int 21h
mov bl,al


sub bl,32

mov ah,09h 
mov dx,offset string2
int 21h

mov dl,bl
mov ah,02h
int 21h

mov ah,04ch
int 21h
end
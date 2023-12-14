.model small
.data
string1 db "The ascii table is............: $"
.code
mov ax,@data
mov ds, ax



mov ah,09h
mov dx,offset string1
int 21h
mov cx,26
mov dx,65
asciiloop:
mov ah,02h
int 21h
add dx,1

Loop asciiloop

mov ah,04ch
int 21h
end
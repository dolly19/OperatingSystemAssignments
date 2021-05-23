        global _start
        global checkGreater
        section .text

_start:
        mov rdi , 2
        mov rsi , 5
        call checkGreater                     ;calling checkGreater
        mov rax, 60                             
        mov rdi, 0                            ;routine for exit syscall
        syscall

checkGreater:
        cmp rdi , rsi                         ;comparing 
        jg  l1                                ;if rdi>rsi jump to l1 label
        jle l2                                ;if rdi<= rsi jump to l2 label
        ret
l1:
        mov rax , 1
        mov rdi , 1
        mov rsi , msg1
        mov rdx , len1
        syscall                                ; syscall for write
        ret
l2:
        mov rax , 1
        mov rdi , 1
        mov rsi , msg2
        mov rdx , len2
        syscall
        ret



        section .data
msg1:   db "1" , 10
len1:   equ $-msg1
msg2:   db "0" , 10
len2:   equ $-msg2

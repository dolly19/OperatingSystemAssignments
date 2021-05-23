  global add             
  section .text
add:
    mov rax , rdi       ;rax intially holds integer a 
    add rax , rsi       ;add with rsi which holding a integer b
    ret                 ;the addition result will be in rax
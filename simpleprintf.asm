        global _main
        extern _printf
        section .text
_main:
        mov rdi, message
        sub rsp, 8
        call _printf
        mov rax, 0x02000001
        xor rdi, rdi
        syscall
        section .data
message:    db      "hello galaxy, a message using printf",10,0
len:        equ     $-message   
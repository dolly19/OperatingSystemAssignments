compile_asm :
	@echo "Converting source code to object code"
	nasm -f elf64 p1.asm -o p1a.o
compile_C :
	@echo "Converting source code to object code"
	gcc -c p1.c -o p1.o
linking :
	@echo "Linking"
	gcc p1a.o p1.o -o final
output:
	@echo "output"
	./final
compile_nasm :
	@echo "Converting add.asm to object code"
	nasm -f elf64 add.asm -o add.o
compile_C :
	@echo "Converting add.c to object code"
	gcc -c prog-add.c -o prog-add.o
linking :
	@echo "Linking"
	gcc add.o prog-add.o -o final
output:
	@echo "output"
	./final
	

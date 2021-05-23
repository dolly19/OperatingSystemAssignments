P4_1asm :
	@echo "Converting source code to object code"
	nasm -f elf32 long.asm -o long.o
outputx86 :
	@echo "output"
	gcc -m32 long.o longAdd.c -o final
	./final
P4_2asm :
	@echo "Converting source code to object code"
	nasm -f elf64 extended.asm -o extended.o
outputx64 :
	@echo "output"
	gcc extended.o extendedAdd.c -o final1
	./final1
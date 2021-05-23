default:
	gcc hello.c 
	./a.out
preprocessor:
	gcc -E hello.c -o hello.i
	cat hello.i 
compiler:
	gcc -S hello.c -o hello.s
	cat hello.s 
assembler:
	gcc -c hello.c -o hello.o
	cat hello.o
linker:
	gcc hello.c -o hello	
output:
	./hello
clean:
	rm hello hello.o hello.s hello.i


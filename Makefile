buffermake: BufferOverFlow.c
	gcc -g -fno-stack-protector -z execstack -no-pie -m64 BufferOverFlow.c -o BOF

Instructions:

1. Switch to Root User (sudo -i )and run the following 
	echo 0 > /proc/sys/kernel/randomize_va_space
	(This disables ASLR)

2. Create python script to produce string argument 
	filename: fuzz
	content:

		#!/usr/bin/python

		str = 'A'*78
		print(str)

3. Give Root previleges to python script
	sudo chmod a+x fuzz

4. Run 'fuzz' and save output to file 'f'
	./fuzz > f

5. Create Makefile for ease
	filename: Makefile
	content:

		buffermake: BufferOverFlow.c
			gcc -g -fno-stack-protector -z execstack -no-pie -m64 BufferOverFlow.c -o BOF

	explanations:

		g flag: Adds debug information to the compilation

		fno-stack-protector: allows overwriting of stack

		z execstack: makes stack executable

		no-pie: prevents compiler from generating ASLR compatible code binary

		m64: 64bit binary







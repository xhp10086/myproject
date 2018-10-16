main:main.c
	gcc -I ./moduleA -I ./moduleB  main.c -o main -L./release -lstudent -lclass  

all: pilhaGenerica.exe
	echo 'iniciando teste de pilha generica:'
	pilhaGenerica.exe

pilhaGenerica.exe: main.o pilha.o
	gcc main.o pilha.o -o pilhaGenerica.exe

main.o: main.c pilha.c pilha.h
	gcc -c main.c

pilha.o: pilha.c pilha.h
	gcc -c pilha.c
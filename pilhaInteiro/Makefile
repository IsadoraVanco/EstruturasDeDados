all: pilhaInteiro.exe
	echo 'iniciando teste de pilha:'
	pilhaInteiro.exe

pilhaInteiro.exe: main.o pilhaInteiro.o
	gcc main.o pilhaInteiro.o -o pilhaInteiro.exe

pilhaInteiro.o: pilhaInteiro.c pilhaInteiro.h
	gcc -c pilhaInteiro.c

main.o: main.c pilhaInteiro.c pilhaInteiro.h
	gcc -c main.c
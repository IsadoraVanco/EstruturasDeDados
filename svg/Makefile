PROJ_NAME=ted
# ALUNO=isadora
# LIBS=
# OBJETOS= ?????????

# compilador
CC=gcc
# Flags
# CFLAGS= -ggdb -O0 -std=c99 -fstack-protector-all -Werror=implicit-function-declaration
# LDFLAGS=-O0 ????

# gente, oq é isso, namoral?
# $(PROJ_NAME): $(OBJETOS)
# $(CC) -o $(PROJ_NAME)$(LDFLAGS) $(OBJETOS) $(LIBS)
# %.o : %.c
# $(CC) -c $(CFLAGS) $< -o $@

# EMPACOTAR PARA ENTREGA
#
# - se necessario: sudo apt install zip ???????????
# pack: $(PROJ_NAME)
# rm -f ../$(ALUNO).zip
# echo $(ALUNO)
# date >> .entrega

# OQ É ISSOOOOOOOOOOOOOOOOO ?????????
# cd ..; zip $(ALUNO).zip -r src/*.c src/*.h src/Makefile LEIA-ME.txt .entrega

# oq importa no momento:

all: svg.exe
	svg.exe

svg.exe: svg.o main.o
	gcc svg.o main.o -o svg.exe

svg.o: svg.c svg.h
	gcc -c svg.c

main.o: main.c svg.c svg.h
	gcc -c main.c
# Nome do projeto
PROJETO = rubroNegra

# Pasta de saída
OUT = out/

# Cria a pasta de saída se ela não existir
$(shell mkdir -p $(OUT))

# Arquivos .c
FONTES = main.c rubroNegra.c ../Ferramentas/Diretorios/diretorios.c ../Ferramentas/Dot/dot.c

# Arquivos .h (iguais os fontes, exceto o main)
HEADERS = $(filter-out main.h, $(FONTES:.c=.h))

# Arquivos .o (iguais os fontes)
OBJETOS = $(addprefix $(OUT), $(FONTES:.c=.o))
# OBJETOS = $(FONTES:.c=.o)

# Compilador e opções de compilação
CC = gcc
CFLAGS = -Wall -Wextra -pedantic-errors -fstack-protector-all -Werror=implicit-function-declaration -g

# Regra padrão
all: $(PROJETO)

# Regra para compilar o projeto
$(PROJETO): $(FONTES) $(HEADERS)
	$(CC) $(FONTES) $(HEADERS) -o $@ -lm

%.c: %.c

# out/main.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@ 
# Cria os arquivos objeto
$(OUT)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Inclui as dependências dos arquivos objeto
-include $(OBJETOS:.o=.d)

# Regra para limpar os arquivos objeto e o executável
clean:
	rm -rf $(PROJETO)
	rm -rf $(OUT)

# Regra para executar o programa
run: all
	./$(PROJETO)

# Regra para executar o programa com o Valgrind
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROJETO)

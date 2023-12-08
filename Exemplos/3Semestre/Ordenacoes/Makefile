# Juntando todas as ordenações :)

bubble = .\BubbleSort\bubbleSort.c .\BubbleSort\bubbleSort.h
insert = .\InsertionSort\insertionSort.c .\InsertionSort\insertionSort.h
merge = .\MergeSort\mergeSort.c .\MergeSort\mergeSort.h
quick = .\QuickSort\quickSort.c .\QuickSort\quickSort.h
select = .\SelectionSort\selectionSort.c .\SelectionSort\selectionSort.h

# Constantes
CC_FLAGS = -ggdb -O0 -std=c99 -fstack-protector-all -Werror=implicit-function-declaration
# -c => compilar um arquivo que não tem main()

all: ordenacoes.exe

ordenacoes.exe: main.o bubbleSort.o insertionSort.o mergeSort.o quickSort.o selectionSort.o
	gcc -o ordenacoes.exe main.o bubbleSort.o insertionSort.o mergeSort.o quickSort.o selectionSort.o

main.o: main.c bubbleSort.o insertionSort.o mergeSort.o quickSort.o selectionSort.o
	gcc -c main.c bubbleSort.o insertionSort.o mergeSort.o quickSort.o selectionSort.o

bubbleSort.o: $(bubble)
	gcc -c .\BubbleSort\bubbleSort.c

insertionSort.o: $(insert)
	gcc -c .\InsertionSort\insertionSort.c

mergeSort.o: $(merge)
	gcc -c .\MergeSort\mergeSort.c

quickSort.o: $(quick)
	gcc -c .\QuickSort\quickSort.c

selectionSort.o: $(select)
	gcc -c .\SelectionSort\selectionSort.c

clear:
	rm *.o
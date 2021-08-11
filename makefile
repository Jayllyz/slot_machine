all: PROJET EXCUTION
PROJET: main.c  fonctions.h
	gcc -c -Wall main.c -Werror
	gcc -o EXEC main.o 
EXCUTION: EXEC
	./EXEC

exec:
	gcc musica.c -c -g
	gcc main.c musica.o -o exec
clear:
	rm musica.o
	rm exec
	clear

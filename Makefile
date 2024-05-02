exec:
	gcc musica.c -c -g
	gcc main.c musica.o -o exec -g
clear:
	rm musica.o
	rm exec
	clear
gdb:
	make exec
	gdb exec

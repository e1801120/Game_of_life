all: main.o draw_function.o calculate_function.o
	gcc main.o draw_function.o calculate_function.o -lncurses
main.o: main.c header.h
	gcc -c main.c
draw_function.o: draw_function.c header.h
	gcc -c draw_function.c
calculate_function.o: calculate_function.c header.h
	gcc -c calculate_function.c
clean:
	rm main.o draw_function.o calculate_function.o

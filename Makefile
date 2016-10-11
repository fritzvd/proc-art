all: draw

draw: main.o
	./main.o

main.o: main.c
	gcc main.c `pkg-config --cflags --libs cairo` -o main.o

clean:
	rm *.o

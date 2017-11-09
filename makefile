all: signals.c
	gcc -o signals signals.c

run: all
	./signals

clean:
	rm -f *.o
	rm -f *~
	rm -f signals
	rm -f sigint
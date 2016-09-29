a.out: stringthings.c
	gcc stringthings.c -o a.out

clean:
	rm *~

run: a.out
	./a.out

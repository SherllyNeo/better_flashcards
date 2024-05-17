CC=tcc


flashcards src/main.c: 
	mkdir -p bin
	$(CC) src/main.c -std=gnu11 -o ./bin/flashcards -lm
install:
	mkdir -p bin
	$(CC) src/main.c -std=gnu11 -o ./bin/flashcards -lm && cp ./bin/flashcards .local/bin
clean:
	mkdir -p bin
	$(CC) src/main.c -std=gnu11 -o ./bin/flashcards -lm && rm vg*

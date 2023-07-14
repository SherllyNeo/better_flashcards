flashcards: flashcards.c
	$(CC) flashcards.c config.h -std=gnu11 -o flashcards -lm
install:
	cp -f flashcards /usr/local/bin
clean:
	$(CC) flashcards.c config.h  -g -std=gnu11 -o smt -lm && rm vg*

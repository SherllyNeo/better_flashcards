flashcards: flashcards.c 
	$(CC) flashcards.c -g -std=gnu99 -o flashcard-cli -ljson-c
install:
	cp -f flashcard-cli /usr/local/bin

flashcards: flashcards.c file_manip.h dir.h time_strings.h flashcard.h
	$(CC) flashcards.c -std=gnu99 -o flashcard-cli -ljson-c
install:
	cp -f flashcard-cli /usr/local/bin

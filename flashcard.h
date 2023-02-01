#include <time.h>
#include <stdio.h>
#include <stdlib.h>


struct flashcard {
  char prompt[MAX_SIZE];
  char answer[MAX_SIZE];
  time_t lastseen;
  int delay;
};

struct flashcard string_to_flashcard(char* flashcard_string) {

	struct flashcard new_flashcard;
	time_t t = time(NULL);
	strcpy(new_flashcard.prompt,"when was the battle of hastings?");
	strcpy(new_flashcard.answer,"1066");
	new_flashcard.lastseen = t;
	new_flashcard.delay = 0;
	return new_flashcard;


}

// struct flashcard string_to_flashcard(char* flashcard_string) {
//
//
//
//
// }


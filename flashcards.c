#define _XOPEN_SOURCE 700
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include "file_manip.h"
#include "dir.h"
#include "flashcard.h"
#include "time_strings.h"

#define MAX_SIZE 10000




int main() {
    srand(time(NULL));
    printf("\n Welcome to my flashcard app - Sherlly's app \n \n");
    start:
    setup_directory();


    char * home = getenv("HOME");
    char flashpath[1024];
    sprintf(flashpath,"%s/.local/share/flashcards",home);
    //path is now the path to the right place

    //read in directories within the flashcards folder

	int amount_of_files = count_dir(flashpath);
    	char** filesList = DirectoryArray(flashpath,amount_of_files);

	for(int i=0; i<amount_of_files; i++)
	    printf("please press %d for deck %s\n",i,filesList[i]);

	int user_choice;

	//validate user choice

	const int result = scanf ("%d",&user_choice);
	if (1 != result) {
		printf("please type in a valid option \n");
		goto start;
		}
	if (user_choice < 0 || user_choice > amount_of_files-1) {
		printf("please type in a valid option \n");
		goto start;
	}


	//set deck path
	char deck_path[1024];
    	sprintf(deck_path,"%s/.local/share/flashcards/%s",home,filesList[user_choice]);
	printf("drawing flashcard files from %s\n",deck_path);



	int amount_of_files_deckpath = count_dir(deck_path);
	char ** deckList = DirectoryArray(deck_path,amount_of_files_deckpath);

	printf("amount of flashcards in deck are: %d \n",amount_of_files_deckpath);
	sleep(1);


	char* choice;
 	char flash_card_path[1024];
	struct flashcard chosen_card;
	char* file_string;
	int random_index;
	int forbidden = 1;
	while (forbidden == 1) {
	choice:
	random_index = rand() % (amount_of_files_deckpath);
 	choice = deckList[random_index];
 	//set filepath
     	sprintf(flash_card_path,"%s/%s",deck_path,choice);
	//read file
        file_string = readFile(flash_card_path);

	//parse file into struct
	chosen_card = string_to_flashcard(file_string);
	printf("card chosen was %s\n",chosen_card.prompt);
	//see if delay forbids showing

	forbidden = check_if_forbidden(chosen_card.lastseen,chosen_card.delay);
 	if (forbidden == 1) {
 		printf("\n random choice %s has been seen recently and you did correctly \n \n redrawing.. \n \n", choice);
 	}
	}

	//ask prompt
	prompt:
	printf("\n \n grabbing flashcard from deck ....\n \n");
	sleep(1);
	printf("Prompt: %s \n \n \nplease press r to reveal answer \n \n",chosen_card.prompt);
	char show_answer[30];

	// use user choice
scanf("%s",&show_answer);
	if (show_answer[0] == 'r') {
	 printf("Answer is: %s \n",chosen_card.answer);

	}
	else {
		printf("\nthat isn't an r, showing promt again \n");
		goto prompt;
	}


	//ask if they got the flashcard correct
	printf("\ndid you get this one correct? (y/n) \n \n ");
	char correct_question[1];
	int delay_value = chosen_card.delay;

	 //use user choice
	scanf("%s",&correct_question);
 	if (correct_question[0] == 'y') {
 	 printf("Well done getting it right, it will be hidden for longer \n");
	  ++delay_value;
 	}
 	else {
 		printf("Don't worry about getting it wrong \n");
		delay_value = 0;
 	}
	sleep(1);
      //write to file
        time_t today = time(NULL);
  	chosen_card.lastseen = today;
  	chosen_card.delay = delay_value;
	char* string_of_new_card = flashcard_to_string(chosen_card);
	writeFile(flash_card_path,string_of_new_card);
	//free malloced string
	free(string_of_new_card);
        free(file_string);

	goto choice;


return 0;
}


#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <regex.h>
#include <time.h>
#include <dirent.h>
#include "file_manip.h"
#include "dir.h"
#include "flashcard.h"
#include "time_strings.h"

#define MAX_SIZE 2000

int main() {
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
	choice:
	char* choice = deckList[choose_random(0,amount_of_files_deckpath)];
	//set filepath
	char flash_card_path[1024];
    	sprintf(flash_card_path,"%s/%s",deck_path,choice);

	//read file
	char* file_string = readFile(flash_card_path);
	//parse file into struct
	struct flashcard chosen_card;
	chosen_card = string_to_flashcard(file_string);

	//set last seen time

	//see if delay forbids showing
	char* forbidden = "Yes";
	if (forbidden == "No") {
	goto choice;
	}

	//free malloced string
	free(file_string);

	//ask prompt
	prompt:
	printf("card chosen from deck is %s\n",flash_card_path);
	printf("Prompt: %s \nplease press r to reveal answer \n \n",chosen_card.prompt);
	char show_answer[30];

	// use user choice
	scanf("%s",&show_answer);
	if (show_answer[0] == 'r') {
	 printf("Answer is: %s \n",chosen_card.answer);

	}
	else {
		printf("that isn't an r, showing promt again \n");
		goto prompt;
	}


	//ask if they got the flashcard correct
	printf("\n did you get this one correct? (y/n) \n \n ");
	char correct_question[30];

	// use user choice
	scanf("%s",&correct_question);
	if (correct_question[0] == 'y') {
	 printf("Well done getting it right, you will see it in some time \n");
	}
	else {
		printf("Don't worry about getting it wrong \n");
	}
	//write to file

	goto choice;

return 0;
}


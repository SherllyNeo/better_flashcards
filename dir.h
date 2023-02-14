#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_SIZE 1000

void setup_directory() {
    //awful flashcard directory maker

    char * home = getenv("HOME");
    int check;
    char path[1024];
    sprintf(path,"%s/.local",home);
    char * settings_path = path;
    check = mkdir(settings_path,0777);


    sprintf(path,"%s/.local/share",home);
    settings_path = path;
    check = mkdir(settings_path,0777);

    sprintf(path,"%s/.local/share/flashcards",home);
    settings_path = path;
    check = mkdir(settings_path,0777);
}

int choose_random(int min, int max) {
	srand(time(NULL));
	int number = (rand() % (max - min)) + min;
	return number;

}





int count_dir(char *filepath) {
	int n=0, i=0;
	DIR *d;
	struct dirent *dir;
	d = opendir(filepath);

	//Determine the number of files
	while((dir = readdir(d)) != NULL) {
	    if ( !strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") )
	    {

	    } else {
		n++;
	    }
	}
	if ( n == 0 ) {
	  printf("there are no flashcard decks!\n");
	  sleep(1);
	  exit(0);

	}
	rewinddir(d);
	return n;
}

char** DirectoryArray(char* filepath,int n) {


    int i = 0;
    DIR *d;
    struct dirent *dir;
    d = opendir(filepath);


	static char *filesList[MAX_SIZE];

	//Put file names into the array
	while((dir = readdir(d)) != NULL) {
	    if ( !strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") )
	    {}
	    else {
		filesList[i] = (char*) malloc (strlen(dir->d_name)+1);
		strncpy (filesList[i],dir->d_name, strlen(dir->d_name) );
		i++;
	    }
	}
	rewinddir(d);
	return filesList;
}


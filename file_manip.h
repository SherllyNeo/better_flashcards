#include <stdio.h>
#include <stdlib.h>
char* readFile(char* filename)
{
    FILE* file = fopen(filename,"r");
    if(file == NULL)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    rewind(file);

    char* content = calloc(size + 1, 1);

    fread(content,1,size,file);

    return content;
}

int writeFile(char *filepath, char *data) {

    remove(filepath);
    int rc = 0;

    FILE *fOut = fopen (filepath, "ab+");
    if (fOut != NULL) {
        if (fputs (data, fOut) != EOF) {
            rc = 1;
        }
        fclose (fOut);
    }

    return rc;
}


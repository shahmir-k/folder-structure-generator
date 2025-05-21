/* ------

Shahmir Khan
University of Guelph Bachelor of Computer Engineering
github.com/shahmir-k
linkedin.com/in/shahmir-k

Please hire me

------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInput.h"




int getUserInput(char *directory)
{
    if (fgets(directory, MAX_DIR_LENGTH, stdin) == NULL)
    { // read user input into directory from stdin, with a max size of MAX_DIR_LENGTH
        printf(ANSI_COLOR_RED "\nError reading input\n\n" ANSI_COLOR_RESET);
        return 0;
    }
    directory[strlen(directory) - 1] = '\0'; // remove newline character due to fgets
    return 1;
}

int validateUserInput(char *directory)
{
    if (strlen(directory) == 0)
    {
        printf(ANSI_COLOR_RED "\nError: Directory cannot be empty\n\n" ANSI_COLOR_RESET);
        return 0;
    }

    if (strlen(directory) >= MAX_DIR_LENGTH)
    {
        printf(ANSI_COLOR_RED "\nError: Directory cannot be longer than %d characters\n\n" ANSI_COLOR_RESET, MAX_DIR_LENGTH - 1);
        return 0;
    }

    FILE *file = fopen(directory, "r");
    if (file == NULL)
    {
        printf(ANSI_COLOR_RED "\nError: Directory does not exist\n\n" ANSI_COLOR_RESET);
        return 0;
    }
    fclose(file);

    return 1;
}
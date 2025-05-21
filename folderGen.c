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

#include "src/userInput.h"

int debug = 1;

int main()
{
    printf("\n-----------------------------------------\n\n");
    printf("Welcome to ASCII Folder Structure Generator by Shahmir Khan 2025\n");
    printf("Please checkout my Github and LinkedIn for more projects\n\n");
    printf("   https://github.com/shahmir-k\n");
    printf("   https://www.linkedin.com/in/shahmir-k\n\n");
    printf("-----------------------------------------\n\n");

    char directory[MAX_DIR_LENGTH];

    int inputNotRead = 1;
    while (inputNotRead)
    {
        memset(directory, 0, MAX_DIR_LENGTH); //set directory string to all \0's 
        printf(ANSI_COLOR_GREEN "Please enter the directory you want to generate the folder structure for: \n" ANSI_COLOR_RESET);
        printf("Example: C:\\Users\\shahm\\Documents\\GitHub\\folder-structure-generator  Or  /home/shahmir/folder-structure-generator\n\n");

        if (!getUserInput(directory)) {
            continue; //reset loop if input is not read
        }
        if (!validateUserInput(directory)) {
            continue; //reset loop if input is not valid or directory does not exist
        }
        inputNotRead = 0;  // Exit the loop when both conditions are met
    }
    
    printf("\nGenerating folder structure for %s\n", directory);

    printf("-----------------------------------------\n\n");

    readFolderStructure(directory);
}

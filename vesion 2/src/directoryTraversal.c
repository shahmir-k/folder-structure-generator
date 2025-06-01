#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include "userInput.h"

void printDirectoryStructure(const char *path, int level)
{
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char fullPath[1024];
    int isLast = 0;
    int count = 0;
    int total = 0;

    if (!(dir = opendir(path)))
    {
        printf("Error: Cannot open directory %s\n", path);
        return;
    }

    // First count total valid entries
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            total++;
        }
    }
    rewinddir(dir);

    // Now process entries
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        count++;
        isLast = (count == total);

        // Create full path
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        // Get file status
        if (lstat(fullPath, &statbuf) == -1)
        {
            printf("Error: Cannot get status for %s\n", fullPath);
            continue;
        }

        // Print indentation
        for (int i = 0; i < level; i++)
            printf("│   ");

        // Print file/directory name with appropriate symbol
        if (S_ISDIR(statbuf.st_mode))
        {
            printf("%s── %s/\n", isLast ? "└" : "├", entry->d_name);
            // Recursively print subdirectory
            printDirectoryStructure(fullPath, level + 1);
        }
        else
        {
            printf("%s── %s\n", isLast ? "└" : "├", entry->d_name);
        }
    }

    closedir(dir);
}

void readFolderStructure(const char *directory)
{
    printf("%s/\n", directory);
    printDirectoryStructure(directory, 0);

    printf("\n");
    printf("\n");
}
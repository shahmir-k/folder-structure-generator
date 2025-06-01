#define MAX_DIR_LENGTH (1000 + 1)  // +1 for null terminator


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
// thanks to https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c


int getUserInput(char *directory);
int validateUserInput(char *directory);
void readFolderStructure(const char *directory);



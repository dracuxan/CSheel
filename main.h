#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAX_INPUT 1024
#define MAX_ARGS 100

void read_input (char *input);
// Reads user input from the command line.
// Removes any trailing newline characters.

void parse_input (char *input, char **args);
// Splits the user input into a command and its arguments.
// Stores them in an array for execution.

void execute_command (char **args);
// Forks a new process to run the given command.
// Uses execvp() to execute the command.
// Waits for the child process to complete.

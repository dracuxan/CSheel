#include "main.h"

int
main ()
{
  char input[MAX_INPUT];
  char *args[MAX_ARGS];

  while (1)
    {
      read_input (input);
      if (strcmp (input, "exit") == 0)
        {
          printf ("Exiting CSheel...\n");
          break;
        }
      parse_input (input, args);
      if (args[0] != NULL)
        {
          execute_command (args);
        }
    }
  exit (EXIT_SUCCESS);
}

void
read_input (char *input)
{
  printf (">> ");
  fgets (input, MAX_INPUT, stdin);
  input[strcspn (input, "\n")] = 0;
}

void
parse_input (char *input, char **args)
{
  int i = 0;
  args[i] = strtok (input, " ");
  while (args[i] != NULL)
    {
      i++;
      args[i] = strtok (NULL, " ");
    }
}

void
execute_command (char **args)
{
  pid_t pid = fork ();

  if (pid < 0)
    {
      perror ("Process failed while creating fork\n");
      exit (EXIT_FAILURE);
    }
  else if (pid == 0)
    {
      if (execvp (args[0], args) == -1)
        {
          perror ("Command execution failed\n");
        }
      exit (1);
    }
  else
    {
      wait (NULL);
    }
}

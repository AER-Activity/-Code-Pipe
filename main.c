/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

//Recode function usefull like strtowordarray strcat etc...

void print_prompt(void)
{
    printf("\033[1;32m");
    if (isatty(STDIN_FILENO) == 1)
        printf("$> ");
    printf("\033[0m");
}

void my_pipe() {
    int fd[2];
    pid_t pid;

    pipe(fd);
    pid = fork();
    if (pid == 0) {
        // use close to close the read end of the pipe
        // dup2 to redirect the write end of the pipe to stdout
        // execute the first command (ls | cat -e == ls)
    } else {
        // use close to close the write end of the pipe
        // dup2 to redirect the read end of the pipe to stdin
        // execute the second command (ls | cat -e == cat -e)
    }
}

void exec_cmd(char *buffer, char **env)
{
    char **cmd = my_str_to_word_array(buffer, " \t\n");

    if (//si il y a un pipe)
        my_pipe();
    else 
        printf("%s: command not found\n", cmd[0]);
    exit(0);
}

int main(int argc, char **argv, char **env)
{
    char *buffer = NULL;
    size_t len = 0;

    print_prompt();
    while (getline(&buffer, &len, stdin) != -1) {
        pid_t pid = fork();
        if (pid == 0) {
            exec_cmd(buffer, env);
        }
        else {
            wait(NULL);
        }
        print_prompt();
    }
    return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void error_msg(const char *msg) {
    perror(msg);
    exit(1);
}

void create_pipes(int (*pipes)[2], int num_pipes) {
    for (int i = 0; i < num_pipes; i++) {
        if (pipe(pipes[i]) == -1) {
            error_msg("Error creating pipe\n");
        }
    }
}

void close_unused_pipes(int (*pipes)[2], int num_pipes, int current_pipe) {
    for (int i = 0; i < num_pipes; i++) {
        if (i != current_pipe) {
            close(pipes[i][0]);
            close(pipes[i][1]);
        } else {
            if (i != 0) {
                close(pipes[i][1]);
            }
            if (i != num_pipes - 1) {
                close(pipes[i][0]);
            }
        }
    }
}

int piper(int num_pipes) {
    int pipes[num_pipes][2];
    int pids[num_pipes];
    int error = 0;

    create_pipes(pipes, num_pipes);

    for (int i = 0; i < num_pipes; i++) {
        pids[i] = fork();
        if (pids[i] == -1) {
            error_msg("Error creating process\n");
        }
        if (pids[i] == 0) {
            // Child process
            close_unused_pipes(pipes, num_pipes, i);

            if (i > 0) {
                if (dup2(pipes[i-1][0], fileno(stdin)) == -1) {
                    error_msg("Error at dup\n");
                }
            }

            if (i < num_pipes - 1) {
                if (dup2(pipes[i][1], fileno(stdout)) == -1) {
                    error_msg("Error at dup\n");
                }
            }

            // Execute the command here
            char *argv[] = {"echo", "hello", NULL};
            execvp("echo", argv);
            error_msg("Error executing command\n");
        }
    }

    // Parent process
    close_unused_pipes(pipes, num_pipes, -1);

    for (int i = 0; i < num_pipes; i++) {
        waitpid(pids[i], &error, 0);
    }

    return 0;
}

int main() {
    int num_pipes = 3; // Change this to the desired number of pipes
    piper(num_pipes);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe_ls_awk[2];
    int pipe_awk_cat[2];
	int pipe_cat_cat[2];
    pid_t child_ls, child_awk, child_cat, child_cat2;

    // Create pipes
    if (pipe(pipe_ls_awk) == -1 || pipe(pipe_awk_cat) == -1 || pipe(pipe_cat_cat) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the first child process (ls)
    if ((child_ls = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_ls == 0) { // Child process (ls)
        // Close unnecessary pipe ends
        close(pipe_ls_awk[0]);
        close(pipe_awk_cat[0]);
        close(pipe_awk_cat[1]);
		close(pipe_cat_cat[0]);
		close(pipe_cat_cat[1]);
        // Redirect stdout to write to the pipe
        dup2(pipe_ls_awk[1], STDOUT_FILENO);

        // Close the remaining file descriptors
        close(pipe_ls_awk[1]);

        // Execute the ls command
        execlp("ls", "ls", "-l", (char *)NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Fork the second child process (awk)
    if ((child_awk = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_awk == 0) { // Child process (awk)
        // Close unnecessary pipe ends
        close(pipe_ls_awk[1]);
        close(pipe_awk_cat[0]);
		close(pipe_cat_cat[0]);
		close(pipe_cat_cat[1]);
        // Redirect stdin to read from the pipe
        dup2(pipe_ls_awk[0], STDIN_FILENO);

        // Redirect stdout to write to the pipe
        dup2(pipe_awk_cat[1], STDOUT_FILENO);

        // Close the remaining file descriptors
        close(pipe_ls_awk[0]);
        close(pipe_awk_cat[1]);

        // Execute the awk command
        execlp("awk", "awk", "{print $4}", (char *)NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Fork the third child process (cat)
    if ((child_cat = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_cat == 0) { // Child process (cat)
        // Close unnecessary pipe ends
        close(pipe_ls_awk[0]);
        close(pipe_ls_awk[1]);
        close(pipe_awk_cat[1]);

        // Redirect stdin to read from the pipe
        dup2(pipe_awk_cat[0], STDIN_FILENO);
        dup2(pipe_cat_cat[1], STDOUT_FILENO);

        // Close the remaining file descriptors
        close(pipe_awk_cat[0]);
        close(pipe_cat_cat[1]);
        // Redirect stdout to write to the file

        // Execute the cat command
        execlp("cat", "cat", (char *)NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    if ((child_cat2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_cat == 0) { // Child process (cat2)
		close(pipe_ls_awk[0]);
		close(pipe_ls_awk[1]);
		close(pipe_awk_cat[0]);
		close(pipe_awk_cat[1]);
        close(pipe_cat_cat[1]);
		
		dup2(pipe_cat_cat[0], STDIN_FILENO);
        close(pipe_cat_cat[0]);

		freopen("out.txt", "w", stdout);

        perror("execlp");
        exit(EXIT_FAILURE);
	}
    // Close all pipe ends in the parent process
    close(pipe_ls_awk[0]);
    close(pipe_ls_awk[1]);
    close(pipe_awk_cat[0]);
    close(pipe_awk_cat[1]);
    close(pipe_cat_cat[0]);
    close(pipe_cat_cat[1]);

    // Wait for all child processes to finish
    waitpid(child_ls, NULL, 0);
    waitpid(child_awk, NULL, 0);
    waitpid(child_cat, NULL, 0);
    waitpid(child_cat2, NULL, 0);

    return 0;
}

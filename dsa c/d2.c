#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int userInput; 

    // Taking user input
    printf("Enter a number: ");
    scanf("%d", &userInput);

    // Forking a process
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: The number you entered is %d\n", userInput);
        printf("Child process: My PID is %d, and my parent's PID is %d\n", getpid());
    } else {
        // Parent process
        wait(NULL); // Wait for child process to complete
        printf("Parent process: Child process completed.\n");
        printf("Parent process: My PID is %d, and my child's PID was %d\n", getpid(), pid);
    }

    return 0;
}
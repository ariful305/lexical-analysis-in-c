#include <stdio.h>  // Include the standard I/O library

/* This is a multi-line comment
   that spans more than one line.
   It will be removed by the program. */

#define MAX_SIZE 100  // Define a constant for maximum size

// This function prints a greeting message
void greet() {
    // Print a hello message
    printf("Hello, World!\n"); // End of the greeting
}

/*
 * This function takes two integers and returns their sum.
 * It also demonstrates a multi-line comment.
 */
int add(int a, int b) {
    return a + b; // Return the sum of a and b
}

int main() {
    int x = 5, y = 10;

    // Call the add function and print the result
    printf("Sum: %d\n", add(x, y));  // Print the sum

    // Calling the greet function
    greet();

    return 0;
}

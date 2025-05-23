#include <stdio.h>  



#define MAX_SIZE 100  


void greet() {
    
    printf("Hello, World!\n"); 
}


int add(int a, int b) {
    return a + b; 
}

int main() {
    int x = 5, y = 10;

    
    printf("Sum: %d\n", add(x, y));  

    
    greet();

    return 0;
}

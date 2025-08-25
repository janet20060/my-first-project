// main.c
#include <stdio.h>

int main() {
    int age;

    // Prompt user to enter their age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Categorize age using if-else if-else statements
    if (age < 13) {
        printf("You are a child!\n");
    } else if (age >= 13 && age <= 19) {
        printf("You are a teenager!\n");
    } else {
        printf("You are an adult!\n");
    }

    return 0;
}

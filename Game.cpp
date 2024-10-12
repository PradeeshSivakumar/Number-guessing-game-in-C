#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    int MAXIMUM_ATTEMPTS = 5;
    int MAXIMUM_NUMBER = 100;

    srand(time(NULL));
    number = rand() % MAXIMUM_NUMBER + 1; 

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a number between 1 and %d.\n", MAXIMUM_NUMBER);
    printf("You have %d attempts to guess it.\n", MAXIMUM_ATTEMPTS);

    
    while (attempts < MAXIMUM_ATTEMPTS) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < 1 || guess > MAXIMUM_NUMBER) {
            printf("Please guess a number between 1 and %d.\n", MAXIMUM_NUMBER);
            attempts--; // Don't count invalid attempts
            continue;
        }

        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", number, attempts);
            break;
        }

        if (attempts == MAXIMUM_ATTEMPTS) {
            printf("Sorry, you've used all your attempts. The number was %d.\n", number);
        }
    }

    return 0;
}


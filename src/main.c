#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char getComputerChoice() {
    int r = rand() % 5;
    if (r == 0) return 'r'; // rock
    if (r == 1) return 'p'; // paper
    if (r == 2) return 'l'; // lizard
    if (r == 3) return 'a'; // spock
    return 's'; // scissors
}

int determineWinner(char user, char computer) {
    if (user == computer) return 0; // tie
    if ((user == 'r' && computer == 's') ||
        (user == 'r' && computer == 'l') ||
        (user == 'p' && computer == 'r') ||
        (user == 'p' && computer == 'a') ||
        (user == 's' && computer == 'p') ||
        (user == 's' && computer == 'l') ||
        (user == 'l' && computer == 'a') ||
        (user == 'l' && computer == 'p') ||
        (user == 'a' && computer == 'r') ||
        (user == 'a' && computer == 's')) return 1; // user wins
    return -1; // computer wins
}

char parseChoice(const char *input) {
    if (strcmp(input, "rock") == 0) return 'r';
    if (strcmp(input, "paper") == 0) return 'p';
    if (strcmp(input, "scissors") == 0) return 's';
    if (strcmp(input, "lizard") == 0) return 'l';
    if (strcmp(input, "spock") == 0) return 'a';
    return '?';
}

int main(void) {
    char input[16];
    int userScore = 0, computerScore = 0;

    srand((unsigned int)time(NULL));
    printf("How about a game of Rock, Paper, Scissors, Lizard, Spock! Best of three wins.\n");

    for (int round = 1; round <= 3; ++round) {
        printf("\nRound %d - Enter rock, paper, scissors, lizard or spock: ", round);
        scanf("%15s", input);
        char userChoice = parseChoice(input);
        if (userChoice == '?') {
            printf("Invalid input. Try again.\n");
            --round;
            continue;
        }
        char computerChoice = getComputerChoice();

        printf("Computer chose: %s\n",
       computerChoice == 'r' ? "rock" :
       computerChoice == 'p' ? "paper" :
       computerChoice == 's' ? "scissors" :
       computerChoice == 'l' ? "lizard" :
       "spock");

        int result = determineWinner(userChoice, computerChoice);
        if (result == 0) {
            printf("It's a tie!\n");
        } else if (result == 1) {
            printf("You win this round!\n");
            userScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }
    }

    printf("\nFinal score - You: %d, Computer: %d\n", userScore, computerScore);
    if (userScore > computerScore) printf("Congratulations, you win!\n");
    else if (userScore < computerScore) printf("Computer wins! Better luck next time.\n");
    else printf("It's a tie overall!\n");

    return 0;
}
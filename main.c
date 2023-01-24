#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

//function to get the user's choice
char getUserChoice()
{
    char userChoice;
    printf("Welcome To Rock Paper Scissors Game,Choose A Character (r for rock, p for paper and s for scissors):");
    scanf("%c",&userChoice);
    userChoice=tolower(userChoice);
    return userChoice;
}

//function to get the random choice of the computer
char getComputerChoice()
{
    //all random income depending on time
    srand(time(NULL));

    //force the computer to choose random number from 1 to 3
    int randomChoice=(rand()%3)+1;

    //1 for Rock, 2 for Paper, 3 for Scissors
    char computerChoice;

    switch (randomChoice) {
        case 1:
            computerChoice='r';
            break;
        case 2:
            computerChoice='p';
            break;
        case 3:
            computerChoice='s';
            break;
    }
    return computerChoice;
}

//function to see the winner between the user and the computer
char getResult(char user,char computer)
{
    if(user==computer)
    {
       return 'd';
    }
    else if((user=='r' && computer=='s') || (user=='s' && computer=='p') || (user=='p' && computer=='r'))
    {
        return 'w';
    }
    else
    {
        return 'l';
    }

}

int main() {
    //assign functions to variables to simplify
    char userChoice=getUserChoice();
    char computerChoice=getComputerChoice();
    char result=getResult(userChoice,computerChoice);

    //indicate the result
    switch (result) {
        case 'w':
            printf("Your Pick Is:%c\n",userChoice);
            printf("Computer's Pick Is:%c\n",computerChoice);
            printf("YOU WON\n");
            break;
        case 'l':
            printf("Your Pick Is:%c\n",userChoice);
            printf("Computer's Pick Is:%c\n",computerChoice);
            printf("YOU LOST!\n");
            break;
        default:
            printf("Your Pick Is:%c\n",userChoice);
            printf("Computer's Pick Is:%c\n",computerChoice);
            printf("DRAW!\n");
    }
    return 0;
}

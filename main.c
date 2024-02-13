#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{

    // srand(time(NULL)); // returns random numbers

    char guessWords[][16] = {
        "green",
        "linux",
        "sarah",
        "python",
        "java",
        "golan",
    };

    int randmoIndex = rand() % 6;

    int numberLives = 5;

    int numCorrect = 0;

    int oldCorrect = 0;

    int lengthofWordChosen = strlen(guessWords[randmoIndex]);

    // loop through chosen word depending on user input and inject here according to index
    int letterGuessed[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    // int letterGuessed[8] = {0, 0, 1, 0, 1, 0, 0, 0}; replace with 1

    int quit = 0;

    int loopIndex = 0;

    char guess[16]; // to store user input

    char letterEnteredByUser;

    //---------------------- print this words for debugging
    //------------------------------------------------------
    //------------------------------------------------------
    printf("guessWords:%s randomIndex:%d lengthofWordChosen%d\n",
           guessWords[randmoIndex],
           randmoIndex,
           lengthofWordChosen);

    //---------------------- game loop
    //------------------------------------------------------
    //------------------------------------------------------
    while (numCorrect < lengthofWordChosen)
    {
        printf("number correct so far:%d\n", numCorrect);

        printf("enter a guess letter:");
        fgets(guess, 16, stdin);

        if (strncmp(guess, "quit", 4) == 0)
        {
            quit = 1;
            break;
        }

        letterEnteredByUser = guess[0];
        printf("letterEntered:%c\n", letterEnteredByUser);

        oldCorrect = numCorrect;

        for (loopIndex = 0; loopIndex < lengthofWordChosen; loopIndex++)
        {
            if (letterGuessed[loopIndex] == 1)
            {
                continue;
            }

            if (letterEnteredByUser == guessWords[randmoIndex][loopIndex])
            {
                letterGuessed[loopIndex] = 1;
                numCorrect++;
            }
        }

        // loose lives
        if (oldCorrect == numCorrect)
        {
            numberLives--;
            printf("wrong guess\n");
            if (numberLives == 0)
            {
                break;
            }
        }
        else
        {
            printf("correct guess\n");
        }
    }

    //------------------------------------------------------
    //------------------------------------------------------

    if (quit == 1)
    {
        printf("the user quit early\n");
    }
    else if (numberLives == 0)
    {
        printf("you lost, the word was: %s\n", guessWords[randmoIndex]);
    }
    else
    {
        printf("you win!!!\n");
    }

    return 0;
}

// strlen ---> returns len of a string
// rand()  --> random number
// fgets ---> reads a line of text
// strncmp()  --> used to compare 2 strings
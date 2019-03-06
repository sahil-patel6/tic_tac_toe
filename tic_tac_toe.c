#include <stdio.h>

void displayBoard(char a[], char b[], char c[]);

int checkWinner(char a[],char b[],char c[]);

int position,isThePlayer1 = 0, numOfIterations = 1;

char firstRow[3] = {NULL}, secondRow[3] = {NULL}, thirdRow[3] = {NULL};

int main() {
    printf("Welcome To Tic Tac Toe game\n");

    printf("You might know how to play this game.. Let's start..\n");

    displayBoard(firstRow, secondRow, thirdRow);

    do {

        input();

        if (isThePlayer1 == 0) {

            isThePlayer1 = 1;

        } else if (isThePlayer1 == 1) {

            isThePlayer1 = 0;

        }

        numOfIterations++;

        displayBoard(firstRow, secondRow, thirdRow);

        if (checkWinner(firstRow,secondRow,thirdRow) == 0){

            printf("Congrats, the winner is X\n");

            break;

        }else if(checkWinner(firstRow,secondRow,thirdRow) == 1){

            printf("Congrats, the winner is Y\n");

            break;

        }else if( (checkWinner(firstRow,secondRow,thirdRow) == 2) && (position == 9)){

            printf("It is tie\n");

            break;

        }

    }while (1);

    return 0;

}

void input(){

    if (isThePlayer1 == 0) {

            printf("Enter position to put 'X' in the above board\n");

            scanf("%d", &position);

            if ((position >= 0) && (position <= 3)) {

                if(firstRow[position - 1] == 'X' || firstRow[position - 1] == 'Y'){

                    printf("The value is already been placed\n");

                    input();

                }else{

                    firstRow[position - 1] = 'X';

                }

            } else if ((position >= 4) && (position <= 6)) {

                if(secondRow[position - 4] == 'X' || secondRow[position - 4] == 'Y'){

                    printf("The value is already been placed\n");

                    input();

                }else{

                    secondRow[position - 4] = 'X';

                }

            } else if ((position >= 7) && (position <= 9)) {

                if(thirdRow[position - 7] == 'X' || thirdRow[position - 7] == 'Y'){

                    printf("The value is already been placed\n");

                    input();

                }else{

                    thirdRow[position - 7] = 'X';

                }


            } else {

                printf("Invalid Input\n");

                input();

            }

        } else if (isThePlayer1 == 1) {

            printf("Enter position to put 'Y' in the above board\n");

            scanf("%d", &position);

            if ((position >= 0) && (position <= 3)) {

                if(firstRow[position - 1] == 'Y' || firstRow[position - 1] == 'X'){

                    printf("The value is already been placed\n");

                    input();

                }else{

                    firstRow[position - 1] = 'Y';

                }

            } else if ((position >= 4) && (position <= 6)) {

                if(secondRow[position - 4] == 'Y' || secondRow[position - 4] == 'X'){

                    printf("The value is already been placed\n");

                    input();

                }else{

                    secondRow[position - 4] = 'Y';

                }

            } else if ((position >= 7) && (position <= 9)) {

                if(thirdRow[position - 7] == 'Y' || thirdRow[position - 7] == 'X'){

                    printf("The value is already been placed\n");

                    input();

                }else{

                    thirdRow[position - 7] = 'Y';

                }

            } else {

                printf("Invalid Input\n");

                input();

            }

        }
}

void displayBoard(char a[], char b[], char c[]){

    for (int i = 0; i < 3; i++) {

        if (a[i] == NULL){

            printf("   | ");

        } else if (a[i] != NULL){

            printf(" %c | ",a[i]);

        }

    }

    printf("\n_________________\n");

    for (int j = 0; j < 3; j++) {

        if (b[j] == NULL){

            printf("   | ");

        }else if (b[j] != NULL){

            printf(" %c | ",b[j]);


        }

    }

    printf("\n_________________\n");

    for (int k = 0; k < 3; k++) {

        if (c[k] == NULL){

            printf("   | ");

        }else if (c[k] != NULL){

            printf(" %c | ",c[k]);

        }

    }

    printf("\n");

}

int checkWinner(char a[],char b[],char c[]){

    int isWinnerX = 0;

    int isWinnerY = 0;

    for (int i = 0; i < 3; i++) {

        if ( (a[i] == 'X') && (b[i] == 'X') && (c[i] == 'X') ){

            isWinnerX = 1;

        }else if ( (a[i] == 'Y') && (b[i] == 'Y') && (c[i] == 'Y') ){

            isWinnerY = 1;

        }

    }

    if( (a[0] == 'X') && (a[1] == 'X') && (a[2] == 'X') ){

        isWinnerX = 1;

    } else if( (a[0] == 'Y') && (a[1] == 'Y') && (a[2] == 'Y') ){

        isWinnerY = 1;

    } else if ( (b[0] == 'X') && (b[1] == 'X') && (b[2] == 'X') ){

        isWinnerX = 1;

    } else if( (b[0] == 'Y') && (b[1] == 'Y') && (b[2] == 'Y') ){

        isWinnerY = 1;

    }else if( (c[0] == 'X') && (c[1] == 'X') && (c[2] == 'X') ){

        isWinnerX = 1;

    }else if( (c[0] == 'Y') && (c[1] == 'Y') && (c[2] == 'Y') ){

        isWinnerY = 1;

    }else if( (a[0] == 'X') && (b[1] == 'X') && (c[2] == 'X') ){

        isWinnerX = 1;

    } else if( (a[0] == 'Y') && (b[1] == 'Y') && (c[2] == 'Y') ){

        isWinnerY = 1;

    }else if( (a[2] == 'X') && (b[1] == 'X') && (c[0] == 'X') ){

        isWinnerX = 1;

    }else if( (a[2] == 'Y') && (b[1] == 'Y') && (c[0] == 'Y') ){

        isWinnerY = 1;

    }

    if (isWinnerX == 1){

        return 0;

    }else if (isWinnerY == 1){

        return 1;

    } else {

        int filled = 0;

        for(int i = 0; i < 3; i++){
            if( a[i] != NULL && b[i] != NULL && c[i] != NULL){
                filled++;
            }
        }
        if(filled == 3){
            filled = 0;
            return 2;
        }else{
            filled = 0;
            return 3;
        }

    }

}

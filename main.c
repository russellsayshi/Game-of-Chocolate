#include "main.h"
#include "game.h"
#include "input.h"

int main(void) {
    printf("Welcome to the chocolate game.\n");
    printf("Rules: each round, each player\n");
    printf("may take 1-n pieces of chocol-\n");
    printf("ate. The person who takes the \n");
    printf("last piece wins. Good luck!\n");
    printf("------------------------------\n");
    printf("Enter the number of pieces (recommended 21): ");
    fflush(stdout);
    int pieces = handle_errors(get_integer(), 0, INT_MAX);
    printf("Enter the max pieces per move (recommended 4): ");
    fflush(stdout);
    int potential_pieces = handle_errors(get_integer(), 2, INT_MAX);
    printf("Want to go first? (0/1) ");
    fflush(stdout);
    int turn = handle_errors(get_integer(), 0, 1);
    if(turn == 0) {
        turn = MY_TURN;
    } else {
        turn = THEIR_TURN;
    }
    while(pieces > 0) {
        if(turn == MY_TURN) {
            int move = decide_move(pieces, potential_pieces);
            pieces -= move;
            if(pieces <= 0) {
                printf("I subtract %d pieces to win.\n", move);
                break;
            } else {
                printf("I subtract %d pieces and now there are %d total.\n", move, pieces);
            }
        } else {
            printf("Enter the number of pieces you take: ");
            fflush(stdout);
            int move = handle_errors(get_integer(), 1, potential_pieces);
            pieces -= move;
            if(pieces <= 0) {
                printf("You win!\n");
            } else {
                printf("There are now %d pieces.\n", pieces);
            }
        }
        turn *= -1; //swap turn
    }
    return 0;
}

int handle_errors(int value, int min, int max) {
    if(value > max || value < min) { //error
        printf("That is not a valid value.\nRange: %d-%d (inclusive). Try again? (0/1) ", min, max);
        fflush(stdout);
        int choice = get_integer();
        if(choice == 1) {
            printf("Great! Please enter your value: ");
            fflush(stdout);
            return handle_errors(get_integer(), min, max);
        } else {
            printf("Goodbye!");
            exit(0);
        }
    }
    return value;
}
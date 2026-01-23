#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)


//me parece que esta esta mal, le faltan los corchetes al for, la voy a corregir

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++){
        printf("................");
    }
    printf("\n");
}

void print_board(char board[3][3]){
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner(char board[3][3]){

    char winner = '-';
    
    bool winnerX = false;
    bool winnerO = false;

    //ganador por fila
    int row=0;
    while(row<3 && (!(winnerX)) && (!(winnerO))){
        winnerX = true; //le asigno true por cada fila, y despues en el ciclo de abajo me 
                        // fijo que cumpla para todos
        winnerO = true;

        for (int column=0; column<3; ++column){
            winnerX=(board[row][column] = 'X') && winnerX;
            winnerO=(board[row][column] = 'O') && winnerO;
        }
        ++row;
        printf("PRIMER CICLO");
    }

    //ganador por columna
    int column=0;
    while(column<3 && (!(winnerX)) && (!(winnerO))){
        winnerX=true;
        winnerO=true;

        for(int row=0; row<3; row++){
            winnerX=(board[row][column] = 'X') && winnerX;
            winnerO=(board[row][column] = 'O') && winnerO;
        }
        ++column;
        printf("SEGUNDO CICLO");
    }

    //ganador por diagonal descendente
    if((!(winnerX)) && (!(winnerO))){
        for(int row_column=0; row_column<3; ++row_column){
            winnerX=(board[row_column][row_column] = 'X') && winnerX;
            winnerO=(board[row_column][row_column] = 'O') && winnerO;
        }
    }

    //ganador diagonal ascendente
    if((!(winnerX)) && (!(winnerO))){
        for (int row_column=0; row_column<3; ++row_column){
            winnerX=(board[2-row_column][row_column] = 'X') && winnerX;
            winnerO=(board[2-row_column][row_column] = 'O') && winnerO;
        }
    }

    if(winnerX){
        winner= 'X';
    } else{
        winner = 'O';
    };

    return winner;
}

bool has_free_cell(char board[3][3])
{
    bool free_cell=false;
    for(int row = 0; row<3; ++row){
        for(int column = 0; column<3; ++column){
            free_cell = free_cell || (board[row][column] = '-');
        }
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}

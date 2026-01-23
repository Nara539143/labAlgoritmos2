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
    printf("33-en 0 esta %c\n", board[0][0]);
}

char get_winner(char board[3][3]){
    //int borrador; //para que avance de a poco
    //printf("row column  winnerX winnerO observaciones\n");
    //scanf("%d",&borrador);

    char winner = '-';
    
    bool winnerX = false;
    bool winnerO = false;

    //ganador por fila
    int row=0;
    //printf("%d           %d       %d   1    la inicializacion\n", row, winnerX, winnerO);
    //scanf("%d",&borrador);
    while(row<3 && (!(winnerX)) && (!(winnerO))){
        winnerX = true; //le asigno true por cada fila, y despues en el ciclo de abajo me 
                        // fijo que cumpla para todos
        winnerO = true;
        //printf("%d           %d       %d       entra a la %d vuelta del while\n", row, winnerX, winnerO, row+1);
        //scanf("%d",&borrador);

        for (int column=0; column<3; ++column){
            winnerX=(board[row][column] == 'X') && winnerX;
            winnerO=(board[row][column] == 'O') && winnerO;
            //printf("%d   %d       %d       %d       %d vuelta del for\n", row, column, winnerX, winnerO, column+1);
            //scanf("%d",&borrador);
        }
        ++row;
        //printf("\nSali del for, row vale %d\n", row);
        //el problema es que se queda en este y nunca pasa a los demas. voy a hacer una corrida
        printf("66-en 0 esta %c\n", board[0][0]);
    
    }

    /*

    voy a suponer que el tablero esta de tal forma que no hay ganadores

    row column  winnerX winnerO observaciones
    0           false   false   la inicializacion
    0           true    true    entra a la primera vuelta del while
    0   0       false   false   primera vuelta del for 
    0   1       false   false   segunda vuelta del for
    0   2       false   false   tercera vuelta del for (no hay ganadores en la fila 1)
    1           true    true    entra a la segunda vuelta del while
    1   0       false   false   primera vuelta del for 
    1   1       false   false   segunda vuelta del for
    1   2       false   false   tercera vuelta del for (no hay ganadores en la fila 1)
    2           true    true    entra a la tercera vuelta del while
    2   0       false   false   primera vuelta del for 
    2   1       false   false   segunda vuelta del for
    2   2       false   false   tercera vuelta del for (no hay ganadores en la fila 1)
    3                           ya no entra mas al while, porque es que queda valiendo true?
    voy a debugear

    soy una mensa, puse = en vez de ==

*/

    //ganador por columna
    int column=0;
    while(column<3 && (!(winnerX)) && (!(winnerO))){
        winnerX=true;
        winnerO=true;

        for(int row=0; row<3; row++){
            winnerX=(board[row][column] == 'X') && winnerX;
            winnerO=(board[row][column] == 'O') && winnerO;
        }
        ++column;
        //printf("SEGUNDO CICLO\n");
        printf("107-en 0 esta %c\n", board[0][0]);
    }

    //ganador por diagonal descendente
    if((!(winnerX)) && (!(winnerO))){
        winnerX=true;
        winnerO=true;
        for(int row_column=0; row_column<3; ++row_column){
            winnerX=(board[row_column][row_column] == 'X') && winnerX;
            winnerO=(board[row_column][row_column] == 'O') && winnerO;
            //printf("Tercer ciclo\n");
        }
        printf("119-en 0 esta %c\n", board[0][0]);
    }

    //ganador diagonal ascendente
    if((!(winnerX)) && (!(winnerO))){
        //printf("Ingrese al if de diagonal ascendente\n");
        //printf("winnerX=%d, winnerO=%d\n", winnerX, winnerO);
        winnerX=true;
        winnerO=true; //faltaban estas inicializaciones, ahora ya anda bien, creo, veamos, sip, era eso
        for (int row_column=0; row_column<3; ++row_column){
            //printf("Acabo de ingresar a la vuelta %d del for. \nlos valores son row_column=%d, winnerX=%d, winnerO=%d\n", row_column+1, row_column, winnerX, winnerO);
            winnerX=(board[(2-row_column)][row_column] == 'X') && winnerX;
            winnerO=(board[(2-row_column)][row_column] == 'O') && winnerO;
            //printf("Ya hice las asignaciones del for: winnerX=%d, winnerO=%d\n", winnerX, winnerO);

            //printf("Cuarto ciclo\n");
        }
        //esta no sirve
        printf("137-en 0 esta %c\n", board[0][0]);
    }
/*
    .........................
    |(0,0)  |(0,1)  |(0,2)  |
    .........................
    |(1,0)  |(1,1)  |(1,2)  |
    .........................
    |(2,0)  |(2,1)  |(2,2)  |
    .........................

    para tener una diagonal ascendente entonces tengo que cubrir (2,0), (1,1), (0,2)
*/


    if(winnerX){
        winner= 'X';
    } else if(winnerO){
        winner = 'O';
    };

    printf("158-en 0 esta %c\n", board[0][0]);
    return winner;

}

bool has_free_cell(char board[3][3]){
    bool free_cell=false;
    for(int row = 0; row<3; ++row){
        for(int column = 0; column<3; ++column){
            free_cell = free_cell || (board[row][column] == '-');
        }
    }
    printf("170-en 0 esta %c\n", board[0][0]);
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

    printf("184-en 0 esta %c", board[0][0]);

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
        printf("211-en 0 esta %c\n", board[0][0]);
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    printf("219-en 0 esta %c\n", board[0][0]);
    return 0;
}

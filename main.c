/* 
 *
 * Program: c2048 - Text based 2048 game
 * 
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

typedef struct game_grid{ 
    int cells[ROWS][COLS];
    int score;
    _Bool game_running;
} game_grid;

void print_grid( game_grid *theGrid) {
    printf("\n\n");

    printf("---------------------\n");
    for(int row=0;row<ROWS;row++) {
        for(int col=0;col<COLS;col++) {
            if(theGrid->cells[row][col]!=0)
                printf("|%4d", theGrid->cells[row][col]);
            else
                printf("|    ");
        }
        printf("|\n---------------------\n");
    }
}

void place_random(game_grid *theGrid) {
    srand(time(NULL));
    int tmp_array[ ROWS * COLS ]={0};
    int nbr_blank_space_locations=0;
    
    // Walk through the grid and save the positions of blank cells into a flat temp array.
    for(int row=0;row<ROWS;row++) {
        for(int col=0;col<COLS;col++) {
            if(theGrid->cells[row][col]==0){
                tmp_array[nbr_blank_space_locations]=(row*COLS)+col+1;
                nbr_blank_space_locations++;
            } else {
                printf("Skipping row:%d col:%d\n", row, col);
            }
        }
    }

    if(nbr_blank_space_locations==0) {
        printf("No more spaces available.  GAME OVER\n");
        exit(0);
    }

/*
            COLS

        0   1   2   3
        _________________
    0  | 1 | 2 | 3 | 4 |
        _________________
R   1  | 5 | 6 | 7 | 8 |
O       _________________
W   2  | 9 | 10| 11| 12|
S       _________________
    3  | 13| 14| 15| 16|
        _________________

*/

    // Now that we know how many blanks exist, pick one of them at random 
    int r = rand() % (nbr_blank_space_locations ); // Pick a random blank slot
    int newrow = tmp_array[r] / ROWS;
    int newcol = (tmp_array[r]%ROWS)-1;
     
    int rnbr = rand() % 2;
    if(rnbr == 0)
        theGrid->cells[newrow][newcol] = 2;
    else
        theGrid->cells[newrow][newcol] = 4;

    printf("writing col:%d row:%d\n", newcol, newrow);
}


int main(int argc, char **argv) {
      
    game_grid grid={.cells={0}, .score=0, .game_running=true};

    // Testing
    grid.cells[2][1] = 16;
    grid.cells[1][2] = 32;

    while(grid.game_running){
        print_grid(&grid);
        printf("Enter command:");

        int keypressed = getchar();

        switch(keypressed) {
            case 'q':
                printf("Quitting\n");
                grid.game_running = false;
                break;
            case 'h':
                //Left
                printf("Left\n");
                break;
            case 'l':
                //Right
                printf("Right\n");
                break;
            case 'j':
                //Down
                printf("Down\n");
                break;
            case 'k':
                //Up
                printf("Up\n");
                break;
        }
        place_random(&grid);
        fflush(stdin);
    }

    return 0;
}

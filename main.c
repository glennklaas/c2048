/* 
 *
 * Program: c2048 - Text based 2048 game
 * 
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    for(int rows=0;rows<ROWS;rows++) {
        for(int cols=0;cols<COLS;cols++) {
            if(theGrid->cells[rows][cols]!=0)
                printf("|%4d", theGrid->cells[rows][cols]);
            else
                printf("|    ");
        }
        printf("|\n---------------------\n");
    }
}

void place_random(game_grid *theGrid) {
    int tmp_array[ ROWS * COLS ]={NULL};
    int nbr_blank_space_locations=0;
    
    for(int rows=0;rows<ROWS;rows++) {
        for(int cols=0;cols<COLS;cols++) {
            if(theGrid->cells[rows][cols]==0){
                tmp_array[nbr_blank_space_locations] = (rows * COLS)+cols+1;
                nbr_blank_space_locations++;
            }
                //printf("%d:%d\n", (rows * COLS)+cols+1,theGrid->cells[rows][cols]); 
        }
    }

    int r = rand() % nbr_blank_space_locations;
    //int theValue = tmp_array[r] / ROWS + tmp_array % r;
    theGrid->cells[tmp_array[r] % r][tmp_array[r] / ROWS] = 2;
    //printf("Random cell nbr: %d\n",theValue); 
}


int main(int argc, char **argv) {
      
    game_grid grid={.cells={0}, .score=0, .game_running=true};

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


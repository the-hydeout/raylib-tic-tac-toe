#include <iostream>
#include <raylib.h>
#include <vector>


const int screenWidth = 600;
const int screenHeight = 600;

int game_grid [] = {
    1, 1, 1, // 0
    1, 1, 1, // 1
    1, 1, 1  // 2
};


// function prototypes
void draw_circle();
void draw_cross();
void draw_winner_line();
void draw_grid();

int mouse_pos_x;
int mouse_pos_y;

int main() {
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    // Main Game Loop
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        draw_grid();
        // draw_cross();
        // draw_circle();

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            std::cout << "ROW: " << (GetMouseY() / 200 ) + 1 << std::endl;
            std::cout << "COLUMN: " << (GetMouseX() / 200 ) + 1 << std::endl;
            // std::cout << std::endl;
            

        }

        // DrawCircleLines(
        //     col_x - 100,
        //     row_y,
        //     100.0f,
        //     WHITE
        // );

        // TODO: FINISH THIS
        for(int i = 0; i < 9; i++) {
            if (game_grid[i] == 1) {
                int col_x = ((i % 3) + 1) * 200;
                int row_y = (((i + 1) / 3)) * 200;

                if( i == 2 ) {
                    row_y = 00;
                } else if ( i == 5) {
                    row_y = 200;
                } else if ( i == 8) {
                    row_y = 400;
                }

                

                DrawCircleLines(
                    col_x - 100,
                    row_y + 100,
                    100.0f,
                    WHITE
                );

                // DrawLine(
                //     col_x - 200, row_y - 200, // start x start y
                //     col_x, row_y, // end x end y
                //     WHITE 
                // );

                // DrawLine(
                //     col_x - 200, row_y + 200, // start x start y
                //     col_x, row_y, // end x end y
                //     WHITE  
                // );


            }
        }


        // DRAWS CROSS IN THE MIDDLE
        // DrawLine (
        //     200, 200, // start x start y,
        //     400, 400, // end x end y
        //     WHITE
        // );

        // DrawLine (
        //     200, 400, // start x start y,
        //     400, 200, // end x end y
        //     WHITE
        // );

        // // DRAWS CROSS IN THE BOTTOM RIGHT
        // DrawLine (
        //     400, 400, // start x start y,
        //     600, 600, // end x end y
        //     WHITE
        // );

        // DrawLine (
        //     400, 600, // start x start y,
        //     600, 400, // end x end y
        //     WHITE
        // );
        

        EndDrawing();
    }

    return 0;
}


// implementation for function prototypes
void draw_grid() {
    // vertical lines
    DrawLine(200, 0, 200, screenHeight, WHITE);
    DrawLine(400, 0, 400, screenHeight, WHITE);

    // horiziontal lines
    DrawLine(0, 200, screenWidth, 200, WHITE);
    DrawLine(0, 400, screenWidth, 400, WHITE);
}

void draw_cross() {
    // DRAWS IN FIRST BOX
    DrawLine(0, 0, 200, 200, WHITE);
    DrawLine(0, 200, 200, 0, WHITE);
}

void draw_circle() {
    DrawCircleLines(100, 100, 100, WHITE);   
}
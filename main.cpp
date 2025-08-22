#include <iostream>
#include <raylib.h>
#include <vector>


const int screenWidth = 600;
const int screenHeight = 600;

int game_grid [] = {
    1, 2, 2,
    2, 1, 2,
    2, 2, 1
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

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            std::cout << "ROW: " << (GetMouseY() / 200 ) + 1 << std::endl;
            std::cout << "COLUMN: " << (GetMouseX() / 200 ) + 1 << std::endl;
        }

        // TODO: FIX THIS GARBAGE
        for(int i = 0; i < 9; i++) {
            if (game_grid[i] == 1) {
                int col_x = ((i % 3) + 1) * 200;
                int row_y = (i / 3) * 200;

                DrawCircleLines(
                    col_x - 100,
                    row_y + 100,
                    100.0f,
                    WHITE
                );


            } else if (game_grid[i] == 2) {
                int col_x = ((i % 3) + 1) * 200;
                int row_y = (i / 3) * 200;

                DrawLine (
                    col_x - 200, row_y, //start x start y
                    col_x, row_y + 200, // end x end y
                    WHITE
                );

                DrawLine (
                    col_x - 200, row_y + 200, //start x start y
                    col_x, row_y, // end x end y
                    WHITE
                );

            }
        }


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
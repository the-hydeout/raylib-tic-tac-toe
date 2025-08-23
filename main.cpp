#include <iostream>
#include <raylib.h>
#include <vector>


const int screenWidth = 600;
const int screenHeight = 600;

int game_grid [] = {
    0, 0, 0, // 0
    0, 0, 0, // 1
    0, 0, 0 // 2
};
// 0, 1, 2
// game_grid[(row * 3) + col]

// function prototypes
void draw_circle(int x, int y);
void draw_cross(int x, int y);
void draw_winner_line();
void draw_grid();

int mouse_pos_x;
int mouse_pos_y;

int col_x;
int row_y;

bool draw_shape = false; // false == x / true == o

int main() {
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    // Main Game Loop
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        draw_grid();

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // std::cout << "ROW: " << ( GetMouseY() / 200 ) << std::endl;
            // std::cout << "COLUMN: " << ( GetMouseX() / 200 ) << std::endl;

            std::cout << "CELL: " << (( GetMouseY() / 200 ) * 3) + ( GetMouseX() / 200 ) << std::endl;

            draw_shape = !draw_shape;
            // std::cout << draw_shape << std::endl;
            if(draw_shape) {
                game_grid[(( GetMouseY() / 200 ) * 3) + ( GetMouseX() / 200 )] = 1;
            } else {
                game_grid[(( GetMouseY() / 200 ) * 3) + ( GetMouseX() / 200 )] = 2;
            }
        }

        // TODO: FIX THIS GARBAGE
        for(int i = 0; i < sizeof(game_grid) / sizeof(game_grid[0]); i++) {
            col_x = ((i % 3) + 1) * 200;
            row_y = (i / 3) * 200;

            if (game_grid[i] == 1) {
                draw_circle(col_x, row_y);

            } else if (game_grid[i] == 2) {
               draw_cross(col_x, row_y);
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

void draw_circle(int x, int y) {
    DrawCircleLines(
        x - 100,
        y + 100,
        100.0f,
        WHITE
    );
}

void draw_cross(int x, int y) {
    DrawLine (
        x - 200, y, //start x start y
        x, y + 200, // end x end y
        WHITE
    );

    DrawLine (
        x - 200, y + 200, //start x start y
        x, y, // end x end y
        WHITE
    );
}
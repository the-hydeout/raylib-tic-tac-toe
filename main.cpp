#include <iostream>
#include <raylib.h>
#include <vector>

const int screenWidth = 600;
const int screenHeight = 600;

// 0 = empty
// 1 = circle
// 2 = cross
int game_grid [] = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0
};

// function prototypes
void draw_circle(int x, int y);
void draw_cross(int x, int y);
void get_player_input();
void draw_player_input();
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
        get_player_input();
        draw_player_input();
        

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

void get_player_input() {
    // TODO: FIX THIS GARBAGE
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(game_grid[(( GetMouseY() / 200 ) * 3) + ( GetMouseX() / 200 )] == 0) {
            if(draw_shape) {
                game_grid[(( GetMouseY() / 200 ) * 3) + ( GetMouseX() / 200 )] = 1;
            } else {
                game_grid[(( GetMouseY() / 200 ) * 3) + ( GetMouseX() / 200 )] = 2;
            }

            draw_shape = !draw_shape;
        }   
    }
}

void draw_player_input() {
    for(int i = 0; i < sizeof(game_grid) / sizeof(game_grid[0]); i++) {
        col_x = ((i % 3) + 1) * 200;
        row_y = (i / 3) * 200;


        if (game_grid[i] == 1) {
            draw_circle(col_x, row_y);
        } else if (game_grid[i] == 2) {
            draw_cross(col_x, row_y);
        }

    }
}
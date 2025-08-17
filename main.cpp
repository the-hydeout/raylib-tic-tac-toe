#include <iostream>
#include <raylib.h>


const int screenWidth = 600;
const int screenHeight = 600;

// function prototypes
void draw_circle();
void draw_cross();
void draw_winner_line();
void draw_center_lines();
void draw_grid();

int main() {
    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    // Main Game Loop
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        // draw_center_lines();
        draw_grid();

        EndDrawing();
    }

    return 0;
}


// implementation for function prototypes
void draw_center_lines() {
    DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, RED);
    DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, RED);
}

void draw_grid() {
    // vertical lines
    DrawLine(200, 0, 200, screenHeight, WHITE);
    DrawLine(400, 0, 400, screenHeight, WHITE);

    // horiziontal lines
    DrawLine(0, 200, screenWidth, 200, WHITE);
    DrawLine(0, 400, screenWidth, 400, WHITE);
    // DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, WHITE);
}
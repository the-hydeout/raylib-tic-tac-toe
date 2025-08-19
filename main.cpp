#include <iostream>
#include <raylib.h>
#include <vector>


const int screenWidth = 600;
const int screenHeight = 600;

int game_grid[] = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0
};

bool draw_shape = false; // false is x, true is o

// std::vector<>


// function prototypes
void draw_circle();
void draw_cross();
void draw_winner_line();
void draw_center_lines();
void draw_grid();

int mouse_pos_x;
int mouse_pos_y;

int main() {
    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    // Main Game Loop
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        // draw_center_lines();
        draw_grid();
        // draw_cross();
        // draw_circle();

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // if(GetMouseX() <= 200 && GetMouseY() <= 200) {
            //     std::cout << "ROW 1 COL 1" << std::endl;
            //     std::cout << "MOUSE X : " << GetMouseX() << " MOUSE Y : " << GetMouseY() << std::endl;
            // } 

            // else if(GetMouseX() <= 200 && GetMouseY() <= 400) {
            //     std::cout << "ROW 1 COL 2" << std::endl;
            //     std::cout << "MOUSE X : " << GetMouseX() << " MOUSE Y : " << GetMouseY() << std::endl;
            // } 

            // else if(GetMouseX() <= 200 && GetMouseY() <= 600) {
            //     std::cout << "ROW 1 COL 3" << std::endl;
            //     std::cout << "MOUSE X : " << GetMouseX() << " MOUSE Y : " << GetMouseY() << std::endl;
            // }

            // for(int i = 0; i < 9; i++) {
            //     game_grid[i]
            // }

            std::cout << "ROW: " << (GetMouseY() / 200 )<< std::endl;
            std::cout << "COLUMN: " << GetMouseX() / 200 << std::endl;
            std::cout << std::endl;
            

        }
        

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

void draw_cross() {
    // DRAWS IN FIRST BOX
    DrawLine(0, 0, 200, 200, WHITE);
    DrawLine(0, 200, 200, 0, WHITE);
}

void draw_circle() {
    DrawCircleLines(100, 100, 100, WHITE);   
}
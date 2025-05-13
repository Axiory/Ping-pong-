#include "pong.h"
#include <iostream>

// Colors
Color Green = Color{ 38, 185, 154, 255 };
Color Dark_Green = Color{ 20, 160, 133, 255 };
Color Light_Green = Color{ 129, 204, 184, 255 };
Color Yellow = Color{ 243, 213, 91, 255 };

// Scores
int player_score = 0;
int cpu_score = 0;

// Ball methods
void Ball::Draw() {
    DrawCircle(x, y, radius, Yellow);
}

void Ball::Update() {
    x += speed_x;
    y += speed_y;

    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speed_y *= -1;
    }
    // Cpu wins
    if (x + radius >= GetScreenWidth()) {
        cpu_score++;
        ResetBall();
    }

    if (x - radius <= 0) {
        player_score++;
        ResetBall();
    }
}

void Ball::ResetBall() {
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int speed_choices[2] = { -1, 1 };
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];
}

// Paddle methods
void Paddle::LimitMovement() {
    if (y <= 0) {
        y = 0;
    }
    if (y + height >= GetScreenHeight()) {
        y = GetScreenHeight() - height;
    }
}

void Paddle::Draw() {
    DrawRectangleRounded(Rectangle{ x, y, width, height }, 0.8, 0, WHITE);
}

void Paddle::Update() {
    if (IsKeyDown(KEY_UP)) {
        y = y - speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
        y = y + speed;
    }
    LimitMovement();
}

// CPU Paddle methods
void CpuPaddle::Update(int ball_y) {
    if (y + height / 2 > ball_y) {
        y = y - speed;
    }
    if (y + height / 2 <= ball_y) {
        y = y + speed;
    }
    LimitMovement();
}

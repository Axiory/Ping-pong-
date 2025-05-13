#ifndef PONG_H
#define PONG_H

#include <raylib.h>

// Colors
extern Color Green;
extern Color Dark_Green;
extern Color Light_Green;
extern Color Yellow;

// Scores
extern int player_score;
extern int cpu_score;

class Ball {
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw();
    void Update();
    void ResetBall();
};

class Paddle {
protected:
    void LimitMovement();

public:
    float x, y;
    float width, height;
    int speed;

    void Draw();
    void Update();
};

class CpuPaddle : public Paddle {
public:
    void Update(int ball_y);
};

#endif // PONG_H#pragma once

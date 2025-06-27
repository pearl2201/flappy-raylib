// MyConstants.h
#ifndef MY_CONSTANTS_H
#define MY_CONSTANTS_H

inline constexpr int SCENE_WIDTH = 405;
inline constexpr int SCENE_HEIGHT = 720;
inline constexpr float GRAVITY = 5*9.81f;
inline constexpr float PIPE_WIDTH = 100;
inline constexpr float PIPE_HEIGHT = 100;
inline constexpr float BIRD_WIDTH = 100;
inline constexpr float BIRD_HEIGHT = 100;
inline constexpr float SCENE_GROUND = 587;
inline constexpr float GAME_VIEWPORT_CENTER = SCENE_GROUND / 2;
inline constexpr float BIRD_Y_ACC = -100;
inline constexpr float PIPE_VELOCITY_X = 100;
inline constexpr float PIPE_DISTANCE = 140;
inline constexpr float START_PIPE_POS = 300;
inline constexpr int PIPE_COUNT = 3;
inline constexpr int DISTANCE_BETWEEN_PIPE = 200;
inline constexpr int RESET_PIPE_DISTANCE = PIPE_COUNT*DISTANCE_BETWEEN_PIPE;

#endif // MY_CONSTANTS_H
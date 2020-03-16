#ifndef BARBARIA_GAME_H
#define BARBARIA_GAME_H

class Game {
public:
    Game();
    void update(float currentTime);
    static float deltaTime;
protected:
private:
    float currentFrame;
    float lastFrame;
};

#endif //BARBARIA_GAME_H

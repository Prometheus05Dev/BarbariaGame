#ifndef BARBARIA_GAME_H
#define BARBARIA_GAME_H

#include "api/loader.h"
#include "game/windows/gamewindow.h"
#include <game/input/keyboard.h>

class Game {
public:
    Game();
    void postInit();
    void update();
    bool shouldClose;
protected:
private:
    GameWindow *gameWindow;
    Loader *gameLoader;
    Shader *gameShader;
    Camera *gameCamera;
    KeyBoard *gameKeyBoard;
};

#endif //BARBARIA_GAME_H

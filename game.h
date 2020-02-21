#ifndef BARBARIA_GAME_H
#define BARBARIA_GAME_H

#include <GL/glew.h>
#include "game/windows/gamewindow.h"
#include "api/loader.h"

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
};

#endif //BARBARIA_GAME_H

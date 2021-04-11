#ifndef EAT_RUN_GAME_H
#define EAT_RUN_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include<deque>
#include<fstream>
#include <vector>
#include "Player.h"
#include "Food.h"
#include "Enemy.h"


using namespace sf;
using namespace std;


class Game {
private:
    Vector2f placement;
    RenderWindow window;
    Player player;
    Food food;
    Enemy enemy;
    Enemy enemy1;
    int currentGameState;
    Text gameOverText;
    Text pointsText;
    Font mainFont;
    int points = 0;
    float xMin = 15;
    float yMin = 15;
    float xMax = 985;
    float yMax = 785;
public:
    enum GameState{RUNNING, GAMEOVER};
    static void setupText(Text *textItem, const Font &font, const String &value, int size, Color colour);
    Game();
    const unsigned int FPS = 60;
    static const Time TimePerFrame;
    void draw();
    void begin();
    void collision();
    void start();
};


#endif

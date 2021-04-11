#ifndef EAT_RUN_PLAYER_H
#define EAT_RUN_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

using namespace sf;

class Player {
private:
    CircleShape player;
public:
    Player();
    void setPosition(Vector2f newPosition);
    CircleShape getPlayer();
    void move(Vector2f);
};


#endif //EAT_RUN_PLAYER_H

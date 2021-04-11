#ifndef EAT_RUN_ENEMY_H
#define EAT_RUN_ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

using namespace sf;

class Enemy {
private:
    CircleShape enemy;
    float xMin = 15;
    float yMin = 15;
    float xMax = 985;
    float yMax = 785;
public:
    Enemy();
    void setPosition(Vector2f newPosition);
    CircleShape getEnemy();
    void move();
    void move1();
};


#endif //EAT_RUN_ENEMY_H

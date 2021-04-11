#include "Enemy.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Enemy::Enemy() {
    enemy.setRadius(15);
    enemy.setFillColor(Color(205, 92, 92));
    enemy.setPosition(650, 650);
}
void Enemy::setPosition(Vector2f newPosition) {
    enemy.setPosition(newPosition);
}
CircleShape Enemy::getEnemy() {
    return enemy;
}
void Enemy::move() {
    srand(time(nullptr));

    int randomMoveX = (rand()%3 - 1);
    int randomMoveY = (rand()%3 - 1);

    Vector2f moveEnemy((float)randomMoveX/3, (float)randomMoveY/3);
    enemy.move(moveEnemy);

    Vector2f pos = enemy.getPosition();
    if(pos.x < xMin){
        pos.x = xMin + 1; //stop at the edge
    }
    if(pos.x > xMax){
        pos.x = xMax - 1;
    }
    if(pos.y < yMin){
        pos.y = yMin + 1;
    }
    if(pos.y > yMax){
        pos.y = yMax - 1;
    }
    enemy.setPosition(pos);
}

void Enemy::move1() {
    srand(time(nullptr));

    int randomMoveX = (rand()%4 - 1);
    int randomMoveY = (rand()%4 - 1);

    Vector2f moveEnemy((float)randomMoveX/3, (float)randomMoveY/3);
    enemy.move(moveEnemy);

    Vector2f pos = enemy.getPosition();
    if(pos.x < xMin){
        pos.x = xMin + 1; //stop at the edge
    }
    if(pos.x > xMax){
        pos.x = xMax - 1;
    }
    if(pos.y < yMin){
        pos.y = yMin + 1;
    }
    if(pos.y > yMax){
        pos.y = yMax - 1;
    }
    enemy.setPosition(pos);
}

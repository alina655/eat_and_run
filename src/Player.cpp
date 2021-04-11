#include "Player.h"

Player::Player(){
    player.setRadius(15);
    player.setFillColor(Color(100, 149, 237));
    player.setOrigin(25, 25);
    player.setPosition(250, 250);
}

void Player::setPosition(Vector2f newPosition){
    player.setPosition(newPosition);
}

CircleShape Player::getPlayer(){
    return player;
}

void Player::move(Vector2f vec) {
    player.move(vec);
}

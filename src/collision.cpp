#include "Game.h"

void Game::collision() {
    //Add points and move food when there is a collision
    for(int i = 0; i < 10; i++){
            if (player.getPlayer().getGlobalBounds().intersects(food.getFood(i).getGlobalBounds())) {
                points++;
                pointsText.setString("points " + to_string(points));
                food.setPosition(i);
            }
    }

    //Game over after collision with the enemy
    if(player.getPlayer().getGlobalBounds().intersects(enemy.getEnemy().getGlobalBounds())){
        currentGameState = GameState::GAMEOVER;
    }
    if(player.getPlayer().getGlobalBounds().intersects(enemy1.getEnemy().getGlobalBounds())){
        currentGameState = GameState::GAMEOVER;
    }
}
#include "Game.h"

const sf::Time Game::TimePerFrame = seconds(1.f/60.f);

Game::Game() {
    placement = Vector2f(1000, 800);
    window.create(VideoMode(placement.x, placement.y), "eat&run", Style::Default);
    begin();
    mainFont.loadFromFile("assets/font/OpenSans-Regular.ttf");

    //game over text
    setupText(&gameOverText, mainFont, "GAME OVER\nPress enter to play again.", 72, Color(210, 105, 30));
    FloatRect gameOverTextBounds = gameOverText.getLocalBounds();
    gameOverText.setPosition(Vector2f(placement.x / 2 - gameOverTextBounds.width / 2, 100));
    gameOverText.setOutlineColor(Color::Black);
    gameOverText.setOutlineThickness(2);

    //points text
    setupText(&pointsText, mainFont, "points 0", 28, Color(135, 206, 250));
    pointsText.setPosition(Vector2f(20, 9));

}

void Game::setupText(Text *textItem, const Font &font, const String &value, int size, Color colour) {
    textItem->setFont(font);
    textItem->setString(value);
    textItem->setCharacterSize(size);
    textItem->setFillColor(colour);
}

void Game::begin() {
    window.clear();
    points = 0;
    player.setPosition(Vector2f(250, 250));
    enemy.setPosition(Vector2f(650, 650));
    enemy1.setPosition(Vector2f(500, 500));
    currentGameState = GameState::RUNNING;
    pointsText.setString("points " + to_string(points));
    pointsText.setPosition(Vector2f(20, 9));

}
void Game::draw() {
    //Draw window
    window.clear(Color(40, 40, 40));

    //Draw Food
    for(int i = 0; i < 10; i++){
        window.draw(food.getFood(i));
    }

    //Draw player
    window.draw(player.getPlayer());

    //Draw enemy
    window.draw(enemy.getEnemy());
    window.draw(enemy1.getEnemy());

    //Draw points
    window.draw(pointsText);

    //Draw Game over
    if(currentGameState == GameState::GAMEOVER){
        window.draw(gameOverText);
    }

    window.display();
}

void Game::start() {

    Clock clock;
    Vector2f moveDirect(0,0);

    //main loop = Runs untill window is closed
    while(window.isOpen()){
        Event event{};

        while (window.pollEvent(event)){
            if(currentGameState == GameState::GAMEOVER){
                if(event.key.code == Keyboard::Enter){
                    begin();
                    draw();
                }
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                    window.close();
                if (event.type == sf::Event::Closed)
                    window.close();
                sleep(milliseconds(2)); //sleep do we dont peg the CPU
                continue;
            }
            if (event.type == sf::Event::Closed)
                window.close();

            if(Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();

            //movement
            if(event.type == Event::KeyPressed && event.key.code == (Keyboard::Up))
                moveDirect = Vector2f (0, -0.2);
            if(event.type == Event::KeyPressed && event.key.code == (Keyboard::Down))
                moveDirect = Vector2f (0, +0.2);
            if(event.type == Event::KeyPressed && event.key.code == (Keyboard::Right))
                moveDirect = Vector2f (+0.2, 0);
            if(event.type == Event::KeyPressed && event.key.code == (Keyboard::Left))
                moveDirect = Vector2f (-0.2, 0);
//            if(event.type == Event::KeyReleased && (event.key.code == Keyboard::Up || event.key.code == Keyboard::Down || event.key.code == Keyboard::Right || event.key.code == Keyboard::Left))
//                moveDirect = Vector2f (0, 0);
            if(currentGameState == GameState::GAMEOVER)
                moveDirect = Vector2f (0, 0);
        }

        Vector2f pos = player.getPlayer().getPosition();
        if(pos.x < xMin){
            pos.x = xMin; //stop at the edge
        }
        if(pos.x > xMax){
            pos.x = xMax;
        }
        if(pos.y < yMin){
            pos.y = yMin;
        }
        if(pos.y > yMax){
            pos.y = yMax;
        }
        player.setPosition(pos);
        enemy.move();
        enemy1.move1();
        player.move(moveDirect);
        collision();
        draw();
    }
}


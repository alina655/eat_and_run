#include "Food.h"
#include <cstdlib>
#include <ctime>

Food::Food() {
    srand(time(nullptr));

    Vector2f foodPosition;
    bool isLocationCorrect;

    for (int i = 0; i < 10; i++) {
        circles[i].setRadius(10);
        circles[i].setFillColor(Color(50, 205, 50));
        do {
            isLocationCorrect = false;
            foodPosition.x = float(rand() % 960);
            foodPosition.y = float(rand() % 760);

        } while (isLocationCorrect);
        circles[i].setPosition(foodPosition);
    }
}
void Food::setPosition(int i) {
    srand(time(nullptr));
    Vector2f newFoodPosition;
    bool badLocation;

    do {
        badLocation = false;
        newFoodPosition.x = float(rand() % 760);
        newFoodPosition.y = float(rand() % 560);
        //check if it is in the apple
        for(int i = 0; i < 10; i++){
            if(getFood(i).getGlobalBounds().intersects(Rect<float>(newFoodPosition.x, newFoodPosition.y, 20, 20))){
                badLocation = true;
                break;
            }
        }
    }while(badLocation);
    circles[i].setPosition(newFoodPosition);
}

CircleShape Food::getFood(int i) {
        return circles[i];
}


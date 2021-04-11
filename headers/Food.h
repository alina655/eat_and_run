#ifndef EAT_RUN_FOOD_H
#define EAT_RUN_FOOD_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <array>

using namespace sf;
using namespace std;

class Food {
private:
    array<CircleShape, 10> circles;
public:
    Food();
    CircleShape getFood(int);
    void setPosition(int);
};


#endif //EAT_RUN_FOOD_H

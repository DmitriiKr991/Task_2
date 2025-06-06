#include "dinosaur.h"
#include "plant.h"

Dinosaur::Dinosaur(double weight, double speed) : Creature(weight, speed) {}

Herbivore::Herbivore(double weight, double speed) : Dinosaur(weight, speed) {}

void Herbivore::act() {
    std::cout << "Травоядный ищет пищу среди растений." << std::endl;
}

void Herbivore::eat(Creature* potentialFood) {
    if (dynamic_cast<Plant*>(potentialFood)) {
        std::cout << "Травоядный съел растение." << std::endl;
    }
}

Carnivore::Carnivore(double weight, double speed) : Dinosaur(weight, speed) {}

void Carnivore::act() {
    std::cout << "Плотоядный динозавр охотится." << std::endl;
}

void Carnivore::eat(Creature* potentialFood) {
    if (dynamic_cast<Dinosaur*>(potentialFood)) {
        std::cout << "Плотоядный динозавр поглотил жертву." << std::endl;
    }
}

Omnivore::Omnivore(double weight, double speed) : Dinosaur(weight, speed) {}

void Omnivore::act() {
    std::cout << "Всеядный динозавр ищет, что бы съесть." << std::endl;
}

void Omnivore::eat(Creature* potentialFood) {
    if (dynamic_cast<Plant*>(potentialFood) || dynamic_cast<Dinosaur*>(potentialFood)) {
        std::cout << "Всеядный динозавр употребил пищу." << std::endl;
    }
}

#include "plant.h"

Plant::Plant(double w, double nv) : Creature(w, nv) {}

void Plant::act() {
    std::cout << "Растение растет." << std::endl;
}

CarnivorousPlant::CarnivorousPlant(double w, double nv) : Plant(w, nv) {}

void CarnivorousPlant::act() {
    std::cout << "Плотоядное растение ловит добычу." << std::endl;
}

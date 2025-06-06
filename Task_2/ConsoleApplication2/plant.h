#ifndef PLANT_H
#define PLANT_H

#include "creature.h"
#include <iostream>

class Plant : public Creature {
public:
    Plant(double w, double nv);
    void act() override;
};

class CarnivorousPlant : public Plant {
public:
    CarnivorousPlant(double w, double nv);
    void act() override;
};

#endif // PLANT_H

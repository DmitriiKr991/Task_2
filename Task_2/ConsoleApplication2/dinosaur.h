#ifndef DINOSAUR_H
#define DINOSAUR_H

#include "creature.h"
#include <iostream>

class Dinosaur : public Creature {
public:
    Dinosaur(double w, double nv);
    virtual void eat(Creature* prey) = 0;
};

class Herbivore : public Dinosaur {
public:
    Herbivore(double w, double nv);
    void act() override;
    void eat(Creature* prey) override;
};

class Carnivore : public Dinosaur {
public:
    Carnivore(double w, double nv);
    void act() override;
    void eat(Creature* prey) override;
};

class Omnivore : public Dinosaur {
public:
    Omnivore(double w, double nv);
    void act() override;
    void eat(Creature* prey) override;
};

#endif // DINOSAUR_H

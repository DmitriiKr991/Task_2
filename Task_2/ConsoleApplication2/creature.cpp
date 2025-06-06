#include "creature.h"

Creature::Creature(double w, double nv) : weight(w), nutritionValue(nv) {}

double Creature::getWeight() const { return weight; }

double Creature::getNutritionValue() const { return nutritionValue; }

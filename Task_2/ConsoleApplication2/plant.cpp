#include "plant.h"

Plant::Plant(double w, double nv) : Creature(w, nv) {}

void Plant::act() {
    std::cout << "�������� ������." << std::endl;
}

CarnivorousPlant::CarnivorousPlant(double w, double nv) : Plant(w, nv) {}

void CarnivorousPlant::act() {
    std::cout << "���������� �������� ����� ������." << std::endl;
}

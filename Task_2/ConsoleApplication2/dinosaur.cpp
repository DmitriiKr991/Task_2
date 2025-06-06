#include "dinosaur.h"
#include "plant.h"

Dinosaur::Dinosaur(double weight, double speed) : Creature(weight, speed) {}

Herbivore::Herbivore(double weight, double speed) : Dinosaur(weight, speed) {}

void Herbivore::act() {
    std::cout << "���������� ���� ���� ����� ��������." << std::endl;
}

void Herbivore::eat(Creature* potentialFood) {
    if (dynamic_cast<Plant*>(potentialFood)) {
        std::cout << "���������� ���� ��������." << std::endl;
    }
}

Carnivore::Carnivore(double weight, double speed) : Dinosaur(weight, speed) {}

void Carnivore::act() {
    std::cout << "���������� �������� ��������." << std::endl;
}

void Carnivore::eat(Creature* potentialFood) {
    if (dynamic_cast<Dinosaur*>(potentialFood)) {
        std::cout << "���������� �������� �������� ������." << std::endl;
    }
}

Omnivore::Omnivore(double weight, double speed) : Dinosaur(weight, speed) {}

void Omnivore::act() {
    std::cout << "�������� �������� ����, ��� �� ������." << std::endl;
}

void Omnivore::eat(Creature* potentialFood) {
    if (dynamic_cast<Plant*>(potentialFood) || dynamic_cast<Dinosaur*>(potentialFood)) {
        std::cout << "�������� �������� ��������� ����." << std::endl;
    }
}

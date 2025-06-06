#include "simulation.h"
#include <iostream>

Simulation::Simulation() {
    creatures.push_back(new Herbivore(200, 5));
    creatures.push_back(new Carnivore(300, 8));
    creatures.push_back(new Omnivore(250, 6));
    creatures.push_back(new Plant(10, 2));
    creatures.push_back(new CarnivorousPlant(15, 4));
}

Simulation::~Simulation() {
    for (Creature* c : creatures)
        delete c;
}

void Simulation::run() {
    std::cout << "������ �������������� ���������..." << std::endl;
    for (Creature* c : creatures)
        c->act();
}

void Simulation::manualControl() {
    while (true) {
        std::cout << "\n�������� ��������:\n";
        std::cout << "1. �������� ���� �������\n";
        std::cout << "2. �������� ���\n";
        std::cout << "3. ��������� ���\n";
        std::cout << "4. �����\n";
        std::cout << "������� ����� ��������: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "�������� �� �����:\n";
            for (size_t i = 0; i < creatures.size(); i++) {
                std::cout << i + 1 << ". ";
                creatures[i]->act();
            }
        }
        else if (choice == 2) {
            int predatorIndex, preyIndex;
            std::cout << "�������� ��������� (�����): ";
            std::cin >> predatorIndex;
            std::cout << "�������� ������ (�����): ";
            std::cin >> preyIndex;

            if (predatorIndex > 0 && predatorIndex <= (int)creatures.size() &&
                preyIndex > 0 && preyIndex <= (int)creatures.size()) {
                Dinosaur* predator = dynamic_cast<Dinosaur*>(creatures[predatorIndex - 1]);
                if (predator) {
                    predator->eat(creatures[preyIndex - 1]);
                }
                else {
                    std::cout << "���� ������ �� ����� ����!\n";
                }
            }
            else {
                std::cout << "������������ ����!\n";
            }
        }
        else if (choice == 3) {
            std::cout << "��������� ��� ���������...\n";
            for (Creature* c : creatures)
                c->act();
        }
        else if (choice == 4) {
            std::cout << "����� �� ���������...\n";
            break;
        }
        else {
            std::cout << "������������ ����!\n";
        }
    }
}

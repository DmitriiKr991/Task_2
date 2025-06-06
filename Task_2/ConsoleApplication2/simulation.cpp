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
    std::cout << "Запуск автоматической симуляции..." << std::endl;
    for (Creature* c : creatures)
        c->act();
}

void Simulation::manualControl() {
    while (true) {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Показать всех существ\n";
        std::cout << "2. Динозавр ест\n";
        std::cout << "3. Следующий шаг\n";
        std::cout << "4. Выход\n";
        std::cout << "Введите номер действия: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Существа на плато:\n";
            for (size_t i = 0; i < creatures.size(); i++) {
                std::cout << i + 1 << ". ";
                creatures[i]->act();
            }
        }
        else if (choice == 2) {
            int predatorIndex, preyIndex;
            std::cout << "Выберите динозавра (номер): ";
            std::cin >> predatorIndex;
            std::cout << "Выберите добычу (номер): ";
            std::cin >> preyIndex;

            if (predatorIndex > 0 && predatorIndex <= (int)creatures.size() &&
                preyIndex > 0 && preyIndex <= (int)creatures.size()) {
                Dinosaur* predator = dynamic_cast<Dinosaur*>(creatures[predatorIndex - 1]);
                if (predator) {
                    predator->eat(creatures[preyIndex - 1]);
                }
                else {
                    std::cout << "Этот объект не может есть!\n";
                }
            }
            else {
                std::cout << "Некорректный ввод!\n";
            }
        }
        else if (choice == 3) {
            std::cout << "Следующий шаг симуляции...\n";
            for (Creature* c : creatures)
                c->act();
        }
        else if (choice == 4) {
            std::cout << "Выход из симуляции...\n";
            break;
        }
        else {
            std::cout << "Некорректный ввод!\n";
        }
    }
}

#include "simulation.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "");
    Simulation simulation;

    std::cout << "Выберите режим работы:\n";
    std::cout << "1. Автоматическая симуляция\n";
    std::cout << "2. Ручное управление\n";
    std::cout << "Введите номер: ";

    int mode;
    std::cin >> mode;

    if (mode == 1) {
        simulation.run();
    }
    else if (mode == 2) {
        simulation.manualControl();
    }
    else {
        std::cout << "Некорректный ввод!\n";
    }

    return 0;
}

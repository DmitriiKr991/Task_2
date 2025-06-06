#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "plant.h"
#include "dinosaur.h"

class Simulation {
private:
    std::vector<Creature*> creatures;
public:
    Simulation();
    ~Simulation();
    void run();
    void manualControl(); // ����� ����� ��� ����������
};

#endif // SIMULATION_H

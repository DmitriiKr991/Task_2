#ifndef CREATURE_H
#define CREATURE_H

class Creature {
protected:
    double weight;
    double nutritionValue;

public:
    Creature(double w, double nv);
    virtual ~Creature() = default;
    virtual void act() = 0;
    double getWeight() const;
    double getNutritionValue() const;
};

#endif // CREATURE_H

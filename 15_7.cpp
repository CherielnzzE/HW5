#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <ctime>

class Dice {
public:
    Dice();
    Dice(int numSides);
    virtual int rollDice() const;

protected:
    int numSides;
};

#endif // DICE_H
#include "Dice.h"

Dice::Dice() {
    numSides = 6;
    srand(time(NULL)); // Seed random number generator
}

Dice::Dice(int numSides) {
    this->numSides = numSides;
    srand(time(NULL)); // Seed random number generator
}

int Dice::rollDice() const {
    return (rand() % numSides) + 1;
}
#include <iostream>
#include "Dice.h"

using namespace std;

int rollTwoDice(const Dice& die1, const Dice& die2) {
    return die1.rollDice() + die2.rollDice();
}

int main() {
    // Create two Dice objects with 6 sides each
    Dice die1(6);
    Dice die2(6);

    // Roll the two dice and print the sum
    for (int i = 0; i < 10; ++i) {
        int sum = rollTwoDice(die1, die2);
        cout << "Roll " << i + 1 << ": " << sum << endl;
    }

    return 0;
}
#ifndef LOADEDDICE_H
#define LOADEDDICE_H

#include "Dice.h"

class LoadedDice : public Dice {
public:
    LoadedDice();
    LoadedDice(int numSides);
    virtual int rollDice() const override;
};

#endif // LOADEDDICE_H
#include "LoadedDice.h"

LoadedDice::LoadedDice() : Dice() {}

LoadedDice::LoadedDice(int numSides) : Dice(numSides) {}

int LoadedDice::rollDice() const {
    if (rand() % 2 == 0) { // 50% chance to return maximum value
        return numSides;
    }
    else {
        return Dice::rollDice(); // Call base class rollDice()
    }
}
#include <iostream>
#include "Dice.h"
#include "LoadedDice.h"

using namespace std;

int rollTwoDice(const Dice& die1, const Dice& die2) {
    return die1.rollDice() + die2.rollDice();
}

int main() {
    // Create two LoadedDice objects with 6 sides each
    LoadedDice die1(6);
    LoadedDice die2(6);

    // Roll the two dice and print the sum
    for (int i = 0; i < 10; ++i) {
        int sum = rollTwoDice(die1, die2);
        cout << "Roll " << i + 1 << ": " << sum << endl;
    }

    return 0;
}
#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
using namespace std;

class Creature {
protected:
    int strength;   // 攻?力
    int hitpoints;  // 生命值

public:
    Creature();
    Creature(int newStrength, int newHitpoints);
    virtual ~Creature(); // ?析构函?

    // ??器和修改器
    int getStrength() const;
    int getHitpoints() const;
    void setStrength(int newStrength);
    void setHitpoints(int newHitpoints);

    // ??方法
    virtual string getSpecies() const;  // 返回生物种?名
    virtual int getDamage();            // ?算生物造成的?害
};

#endif // CREATURE_H
#include "Creature.h"
#include <cstdlib> // for rand function
#include <ctime>   // for time function

Creature::Creature() {
    strength = 10;
    hitpoints = 10;
}

Creature::Creature(int newStrength, int newHitpoints) {
    strength = newStrength;
    hitpoints = newHitpoints;
}

Creature::~Creature() {}

int Creature::getStrength() const {
    return strength;
}

int Creature::getHitpoints() const {
    return hitpoints;
}

void Creature::setStrength(int newStrength) {
    strength = newStrength;
}

void Creature::setHitpoints(int newHitpoints) {
    hitpoints = newHitpoints;
}

string Creature::getSpecies() const {
    return "Creature";
}

int Creature::getDamage() {
    int damage = (rand() % strength) + 1;
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    return damage;
}
#ifndef HUMAN_H
#define HUMAN_H

#include "Creature.h"

class Human : public Creature {
public:
    Human();
    virtual string getSpecies() const override;
    virtual int getDamage() override;
};

#endif // HUMAN_H
#ifndef ELF_H
#define ELF_H

#include "Creature.h"

class Elf : public Creature {
public:
    Elf();
    virtual string getSpecies() const override;
    virtual int getDamage() override;
};

#endif // ELF_H
#include "Elf.h"

Elf::Elf() : Creature(18, 15) {}

string Elf::getSpecies() const {
    return "Elf";
}

int Elf::getDamage() {
    int damage = Creature::getDamage();
    if (rand() % 10 == 0) {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        damage *= 2;
    }
    return damage;
}
#ifndef DEMON_H
#define DEMON_H

#include "Creature.h"

class Demon : public Creature {
public:
    Demon(int newStrength, int newHitpoints);
    virtual string getSpecies() const override;
    virtual int getDamage() override = 0; // ??函?
};

#endif // DEMON_H
#include "Demon.h"

Demon::Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

string Demon::getSpecies() const {
    return "Demon";
}
#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include "Demon.h"

class Cyberdemon : public Demon {
public:
    Cyberdemon();
    virtual string getSpecies() const override;
    virtual int getDamage() override;
};

#endif // CYBERDEMON_H
#include "Cyberdemon.h"

Cyberdemon::Cyberdemon() : Demon(25, 30) {}

string Cyberdemon::getSpecies() const {
    return "Cyberdemon";
}

int Cyberdemon::getDamage() {
    int damage = Creature::getDamage();
    if (rand() % 100 < 5) {
        cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        damage += 50;
    }
    return damage;
}
#ifndef BALROG_H
#define BALROG_H

#include "Demon.h"

class Balrog : public Demon {
public:
    Balrog();
    virtual string getSpecies() const override;
    virtual int getDamage() override;
};

#endif // BALROG_H
#include "Balrog.h"

Balrog::Balrog() : Demon(20, 40) {}

string Balrog::getSpecies() const {
    return "Balrog";
}

int Balrog::getDamage() {
    int damage = Demon::getDamage(); // Balrog attacks twice due to its speed
    int damage2 = Creature::getDamage();
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    damage += damage2;
    return damage;
}
#include "Creature.h"
#include "Human.h"
#include "Elf.h"
#include "Cyberdemon.h"
#include "Balrog.h"
#include <iostream>
#include <ctime>
using namespace std;

void battleArena(Creature& creature1, Creature& creature2) {
    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        int damage1 = creature1.getDamage();
        creature2.setHitpoints(creature2.getHitpoints() - damage1);

        if (creature2.getHitpoints() <= 0)
            break;

        int damage2 = creature2.getDamage();
        creature1.setHitpoints(creature1.getHitpoints() - damage2);
    }

    if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0)
        cout << "The battle ends in a tie!\n";
    else if (creature1.getHitpoints() <= 0)
        cout << creature2.getSpecies() << " wins!\n";
    else
        cout << creature1.getSpecies() << " wins!\n";
}

int main() {
    srand(time(nullptr)); // Seed for random number generation

    Human human;
    Elf elf;
    Cyberdemon cyberdemon;
    Balrog balrog;

    battleArena(human, elf);
    battleArena(cyberdemon, balrog);

    return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

class Creature {
protected:
    int strength;   // How much damage we can inflict
    int hitpoints;  // How much damage we can sustain

public:
    Creature();
    Creature(int newStrength, int newHitpoints);
    virtual ~Creature();

    virtual string getSpecies() const;
    virtual int getDamage();

    // Accessors
    int getStrength() const;
    int getHitpoints() const;

    // Mutators
    void setStrength(int newStrength);
    void setHitpoints(int newHitpoints);
};

Creature::Creature() : strength(10), hitpoints(10) {
    srand(time(0));  // Seed for random number generation
}

Creature::Creature(int newStrength, int newHitpoints)
    : strength(newStrength), hitpoints(newHitpoints) {
    srand(time(0));  // Seed for random number generation
}

Creature::~Creature() {}

string Creature::getSpecies() const {
    return "Unknown";
}

int Creature::getDamage() {
    int damage = (rand() % strength) + 1;
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    return damage;
}

// Accessors
int Creature::getStrength() const {
    return strength;
}

int Creature::getHitpoints() const {
    return hitpoints;
}

// Mutators
void Creature::setStrength(int newStrength) {
    strength = newStrength;
}

void Creature::setHitpoints(int newHitpoints) {
    hitpoints = newHitpoints;
}
class Human : public Creature {
public:
    Human();
    virtual string getSpecies() const override;
};

Human::Human() : Creature(10, 10) {}

string Human::getSpecies() const {
    return "Human";
}
class Elf : public Creature {
public:
    Elf();
    virtual string getSpecies() const override;
    virtual int getDamage() override;
};

Elf::Elf() : Creature(10, 10) {}

string Elf::getSpecies() const {
    return "Elf";
}

int Elf::getDamage() {
    int damage = (rand() % strength) + 1;
    if ((rand() % 10) == 0) {  // 10% chance for magical attack
        damage *= 2;
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
    }
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    return damage;
}
class Demon : public Creature {
public:
    Demon(int newStrength, int newHitpoints);
    virtual string getSpecies() const override;
    virtual int getDamage() override;
};

Demon::Demon(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints) {}

string Demon::getSpecies() const {
    return "Demon";
}

int Demon::getDamage() {
    int damage = (rand() % strength) + 1;
    if ((rand() % 100) < 5) {  // 5% chance for demonic attack
        damage += 50;
        cout << "Demonic attack inflicts 50 additional damage points!" << endl;
    }
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    return damage;
}
class Cyberdemon : public Demon {
public:
    Cyberdemon();
    virtual string getSpecies() const override;
};

Cyberdemon::Cyberdemon() : Demon(10, 10) {}

string Cyberdemon::getSpecies() const {
    return "Cyberdemon";
}
class Balrog : public Demon {
public:
    Balrog();
    virtual string getSpecies() const override;
    virtual int getDamage() override;
};

Balrog::Balrog() : Demon(10, 10) {}

string Balrog::getSpecies() const {
    return "Balrog";
}

int Balrog::getDamage() {
    int damage = Demon::getDamage();
    int damage2 = (rand() % strength) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    damage += damage2;
    return damage;
}
int main() {
    Human human;
    Elf elf;
    Cyberdemon cyberdemon;
    Balrog balrog;

    for (int i = 0; i < 3; ++i) {
        cout << "\nRound " << (i + 1) << ":\n";
        human.getDamage();
        elf.getDamage();
        cyberdemon.getDamage();
        balrog.getDamage();
    }

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#ifndef PLAYER_H 
#define PLAYER_H

//class player
class Player {
//player attributes
private:
    int health;
    int baseDamage;
    int additionalDamageMin;
    int additionalDamageMax;
    int healMin;
    int healMax;
    int maxHealth;

public:
    Player(int h, int d, int damMin, int damMax, int healMin, int healMax)
        : health(h), baseDamage(d), additionalDamageMin(damMin),
          additionalDamageMax(damMax), healMin(healMin), healMax(healMax),
          maxHealth(h) {}

    
    //take damage 
    virtual void takeDamage(int damage) {
        health = health - damage;
        if (health < 0)
            health = 0;
        std::cout << "Player took " << damage << " damage. Current health is: " << health << std::endl;
    }

//player gives damage
    virtual int giveDamage() {
        int additionalDamage = rand() % (additionalDamageMax - additionalDamageMin + 1) + additionalDamageMin;
        return baseDamage + additionalDamage;
    }

//player heals
    virtual void heal() {
        if (health == maxHealth) {
            std::cout << "Health is already full." << std::endl;
        } else {
            int healAmount = rand() % (healMax - healMin + 1) + healMin;
            health += healAmount;
            if (health > maxHealth)
                health = maxHealth;
            std::cout << "Player healed by " << healAmount << ". Current health: " << health << std::endl;
        }
    }

    bool isAlive() const { return health > 0; }

    int getHealth() const { return health; }
};

//players are defined based on types
class TypeA : public Player {
public:
    TypeA() : Player(150, 10, 2, 5, 5, 10) {
        std::cout << "HAHAHA I am A the best of the rest I am the Greatest!!! " << std::endl;
    }
};

class TypeB : public Player {
public:
    TypeB() : Player(100, 15, 5, 10, 10, 15) {
        std::cout << "HAHAHA I am B!! I am the mightiest of all!!!" << std::endl;
    }
};

class TypeC : public Player {
public:
    TypeC() : Player(80, 20, 8, 15, 8, 12) {
        std::cout << "YEEEHAW I am C!! Kneel before me loserss!!!" << std::endl;
    }
};

#endif
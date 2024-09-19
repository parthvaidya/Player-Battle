#include <iostream>
#include "Player.h"

Player* createPlayer() {
    char choice;
    int attempts = 5;  

    while (attempts > 0) {
        std::cout << "Choose player type: A, B, C: ";
        std::cin >> choice;

        if (choice == 'A' || choice == 'a') {
            return new TypeA();
        } else if (choice == 'B' || choice == 'b') {
            return new TypeB();
        } else if (choice == 'C' || choice == 'c') {
            return new TypeC();
        } else {
            std::cout << "Invalid choice. Try again. Attempts left: " << --attempts << std::endl;
        }
    }

    std::cout << "Too many invalid attempts.You did not obey the rules. Exiting the game." << std::endl;
    exit(1);
}

void playerTurn(Player* currentPlayer, Player* opponent) {
    char action;
    int attempts = 5;  

    while (attempts > 0) {
        std::cout << "Choose action: (A/a) to attack or (H/h) to heal: ";
        std::cin >> action;

        if (action == 'A' || action == 'a') {
            int damage = currentPlayer->giveDamage();
            std::cout << "Attacking opponent!" << std::endl;
            opponent->takeDamage(damage);
            return;
        } else if (action == 'H' || action == 'h') {
            currentPlayer->heal();
            return;
        } else {
            std::cout << "Invalid action. Try again. Attempts left: " << --attempts << std::endl;
        }
    }

    std::cout << "Too many invalid attempts. You did not obey the rules. Exiting the game" << std::endl;
    exit(1);
}

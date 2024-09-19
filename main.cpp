#include <iostream>
#include <ctime>
#include "Player.h"
#include "GameFunctions.h"

int main() {
    std::cout << "Welcome to the Player Battle Adventure!!!" << std::endl;

    char choice;
    int attempts = 0;
    const int maxAttempts = 5; 

    // Input loop for the initial choice with attempts limit
    while (attempts < maxAttempts) {
        std::cout << "Press S to start the game or E to exit: ";
        std::cin >> choice;

        if (choice == 'S' || choice == 's') {
            srand(static_cast<unsigned int>(time(0)));
            std::cout << "Ready Players!!!!!!!!!!!" << std::endl;
            std::cout << "Let the fun BEGINNNNNNNNNNNN !!!!!!!!!!!!!!!!" << std::endl;

            std::cout << "Player 1, choose your player type:" << std::endl;
            Player* player1 = createPlayer();

            std::cout << "Player 2, choose your player type:" << std::endl;
            Player* player2 = createPlayer();

            // Turn-based game loop
            while (player1->isAlive() && player2->isAlive()) {
                std::cout << "\nPlayer 1's turn: " << std::endl;
                playerTurn(player1, player2);
                if (!player2->isAlive()) {
                    std::cout << "Player 2 is dead!" << std::endl;
                    break;
                }

                std::cout << "\nPlayer 2's turn: " << std::endl;
                playerTurn(player2, player1);
                if (!player1->isAlive()) {
                    std::cout << "Player 1 is dead!" << std::endl;
                    break;
                }
            }

            delete player1;
            delete player2;
            
        } else if (choice == 'E' || choice == 'e') {
            std::cout << "Exiting the game. Goodbye!\n";
            exit(1);
        } else {
            attempts++;
            std::cout << "Invalid input(Remember you only have 5 invalid). Please enter 'S' to start or 'E' to exit." << std::endl;

            // Check if max attempts have been reached
            if (attempts >= maxAttempts) {
                std::cout << " Invalid attempts exahusted .You did not obey rules. Exiting the game.\n";
                
            }
            exit(1);
        }
    }

    return 0;
}
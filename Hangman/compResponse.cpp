// Draw the hangman after each attempt
#include <iostream>
#include <string>
#include "compResponse.h"

// function to progressively draw the hangman
void drawHangman(int attemptsLeft) { 
    // Add your hangman drawing logic here 
    // For simplicity, you can print a static hangman 
    // ASCII art Modify this function to display the 
    // hangman as you like 
    if (attemptsLeft == 6) { 
        std::cout << "   _____" << std::endl; 
        std::cout << "  |     " << std::endl; 
        std::cout << "  |     " << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  ______" << std::endl;
    } 
    else if (attemptsLeft == 5) { 
        std::cout << "   _____" << std::endl; 
        std::cout << "  |     |" << std::endl; 
        std::cout << "  |     O" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  ______" << std::endl;
    } 
    else if (attemptsLeft == 4) { 
        std::cout << "   _____" << std::endl; 
        std::cout << "  |     |" << std::endl; 
        std::cout << "  |     O" << std::endl; 
        std::cout << "  |     |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  ______" << std::endl;
    } 
    else if (attemptsLeft == 3) { 
        std::cout << "   _____" << std::endl; 
        std::cout << "  |     |" << std::endl; 
        std::cout << "  |     O" << std::endl; 
        std::cout << "  |    /|" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  ______" << std::endl;
    } 
    else if (attemptsLeft == 2) { 
        std::cout << "   _____" << std::endl; 
        std::cout << "  |     |" << std::endl; 
        std::cout << "  |     O" << std::endl; 
        std::cout << "  |    /|\\" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  ______" << std::endl;
    } 
    else if (attemptsLeft == 1) { 
        std::cout << "   _____" << std::endl; 
        std::cout << "  |     |" << std::endl; 
        std::cout << "  |     O" << std::endl; 
        std::cout << "  |    /|\\" << std::endl; 
        std::cout << "  |    /" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  ______" << std::endl;
    } 
    else if (attemptsLeft == 0) { 
        std::cout << "   _____" << std::endl; 
        std::cout << "  |     |" << std::endl; 
        std::cout << "  |     O" << std::endl; 
        std::cout << "  |    /|\\" << std::endl; 
        std::cout << "  |    / \\" << std::endl; 
        std::cout << "  |" << std::endl; 
        std::cout << "  |" << std::endl;
        std::cout << "  ______" << std::endl;
    } 
    std::cout.put('\n');
}

void guessResult(std::list<std::string> guessList) {
    drawHangman(6 - falseGuessAmount);
    std::cout << "Guessed letters: ";
    for (auto currentGuess : guessList) {
        std::cout << currentGuess << ", ";
    }
    std::cout.put('\n');
}
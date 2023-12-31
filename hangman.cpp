// Hangman Game
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <list>
#include <ctype.h>


std::string randomWordGenerator(std::mt19937 prng) {
    std::string wordLine;
    std::ifstream wordList ("WordList.txt");
    std::string result;

    for(std::size_t n = 0; std::getline(wordList, wordLine); n++) {
        std::uniform_int_distribution<> dist(0, n);
        if (dist(prng) < 1) {
            result = wordLine;
        }
    }
    return result;
}
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

void guessResult(int falseGuessAmount, std::list<std::string> guessList) {
    drawHangman(6 - falseGuessAmount);
    std::cout << "Guessed letters: ";
    for (auto currentGuess : guessList) {
        if (falseGuessAmount < 6) {
            std::cout << currentGuess << ", ";
        }
        else {
            std::cout << currentGuess;
        }
    }
    std::cout.put('\n');
}

std::string guessValidator(std::list<std::string> guessList) {
    std::string guess;
    bool valid = false;
    do {
        valid = true;
        std::cin >> guess;
        std::cout << "Checking Validity: ";
        for (int i=0; i<guess.length(); i++) {
            if (! isalpha(guess[i])){
                std::cout << "Only letters are valid.\nRetry: ";
                valid = false;
                break;
            }
        }

        for (auto item: guessList) {
            if (guess == item) {
                std::cout << "Guess already made.\nRetry: ";
                valid = false;
                break;
            }
        }
    } while (! valid);
    std::cout << guess << " is valid\n";
    return guess;
}

int main () {
    std::string guess;
    std::list<std::string> guessList;
    int falseGuessAmount = 0;
    std::random_device seed;
    std::mt19937 prng(seed());
    std::string hangmanWord = randomWordGenerator(prng);
    std::string discoveredWord;
    for (int i=0; i<hangmanWord.length(); i++) {
        discoveredWord.append("_");
    }
    std::cout << "Welcome to the Hangman Game" << std::endl;
    std::cout << "Guess one letter at a time or the full word: ";
    while((6 - falseGuessAmount) > 0) {
        bool correctGuess = false;
        guess = guessValidator(guessList);
        guessList.push_back(guess);
        if (guess.length() > 1) {
            if (guess == hangmanWord) {
                std::cout << "You win the game";
            }
            else {
                falseGuessAmount++;
                std::cout << "Incorrect Guess" << std::endl;
                guessResult(falseGuessAmount,guessList);
                std::cout << discoveredWord;
            }
        }
        else {
            for (int i=0; i<hangmanWord.length(); i++) {
                if (hangmanWord[i] == guess[0]){
                    discoveredWord[i] = guess[0];
                    correctGuess = true;
                }
            }
            if (correctGuess) {
                std::cout << "Correct Guess" << std::endl;
                guessResult(falseGuessAmount,guessList);
            }
            else{
                falseGuessAmount++;
                std::cout << "Incorrect Guess" << std::endl;
                guessResult(falseGuessAmount,guessList);
            }

            std::cout << discoveredWord;
        }
        std::cout.put('\n');
        if (discoveredWord == hangmanWord) {
            std::cout << "You win the game. The word is " << hangmanWord << std::endl;
            break;
        }
        if (falseGuessAmount < 6) {
            std::cout << "Guess again: ";
        }
        else {
            if (discoveredWord == hangmanWord) {
                std::cout << "You win the game. The word is " << hangmanWord << std::endl;
            }
            else {
                std::cout << "You lost the game. The word is " << hangmanWord << std::endl;
            }
        }
    }
    return 0;
}
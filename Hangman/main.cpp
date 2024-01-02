// Hangman Game
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <list>
#include <ctype.h>
#include "compResponse.h"
#include "validator.h"

std::string discoveredWord;
int falseGuessAmount;

std::string randomWordGenerator() {
    std::random_device seed;
    std::mt19937 prng(seed());
    std::string wordLine, result;
    std::ifstream wordList ("WordList.txt");

    for(std::size_t n = 0; std::getline(wordList, wordLine); n++) {
        std::uniform_int_distribution<> dist(0, n);
        if (dist(prng) < 1) {
            result = wordLine;
        }
    }
    return result;
} 

void start_game () {
    std::string guess;
    std::list<std::string> guessList;
    falseGuessAmount = 0;
    discoveredWord = "";
    std::string hangmanWord = randomWordGenerator();
    for (int i=0; i<hangmanWord.length(); i++) {
        discoveredWord.append("_");
    }
    std::cout << "Welcome to the Hangman Game" << std::endl;
    std::cout << "Guess one letter at a time or the full word: ";
    while((6 - falseGuessAmount) > 0) {
        guess = guessValidator(guessList);
        guessList.push_back(guess);
        guessChecker(guessList, guess, hangmanWord);
        if (discoveredWord == hangmanWord) {
            hangmanWord[0] = toupper(hangmanWord[0]);
            std::cout << "You win the game. The word is " << hangmanWord << std::endl;
            break;
        }
        if (falseGuessAmount < 6) {
            std::cout << "Guess again: ";
        }
        else {
            if (discoveredWord != hangmanWord) {
                hangmanWord[0] = toupper(hangmanWord[0]);
                std::cout << "You lost the game. The word is " << hangmanWord << std::endl;
                break;
            }
        }
    }
    
}

int main() {
    char replay = 'y';
    do {
        start_game();
        std::cout << "Replay(y/n)? ";
        std::cin >> replay;
    } while (replay == 'y' || replay == 'Y');
    exit(0);
}

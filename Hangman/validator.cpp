#include <string>
#include <list>
#include <iostream>
#include "compResponse.h"

std::string guessValidator(std::list<std::string> guessList) {
    std::string guess;
    bool valid = false;
    do {
        valid = true;
        std::cin >> guess;
        for (int i=0; i<guess.length(); i++) {
            guess[i] = tolower(guess[i]); 
        } 
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

void guessChecker(std::list<std::string> guessList, std::string guess, std::string hangmanWord) {
    bool correctGuess = false;
    if (guess.length() > 1) {
        if (guess == hangmanWord) {
            discoveredWord = guess;
        }
        else {
            falseGuessAmount++;
            std::cout << "Incorrect Guess" << std::endl;
            guessResult(guessList);
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
            guessResult(guessList);
        }
        else{
            falseGuessAmount++;
            std::cout << "Incorrect Guess" << std::endl;
            guessResult(guessList);
        }

        std::cout << discoveredWord << '\n';
    }
}
#include <string>
#include <list>

extern std::string discoveredWord;
extern int falseGuessAmount;
// function to progressively draw the hangman
void drawHangman(int x);

// print out previous guesses
void guessResult(std::list<std::string> guessList);
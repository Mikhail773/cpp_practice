#include <string>
#include <list>

extern std::string discoveredWord;
extern int falseGuessAmount;
std::string guessValidator(std::list<std::string> guessList);
void guessChecker(std::list<std::string> guessList, std::string guess, std::string hangmanWord);
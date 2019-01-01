#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void displayGameIntro();
void playGame();
void displayGameSummary();

bool askToPlayAgain(); 

FBullCowGame BCGame; // new game instance


/***********************************************************
*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
* ++         Main implementations - Client side          ++
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
*
************************************************************/

int main(){

    bool bplayAgain = false;
    displayGameIntro();
    
    do{
        
        playGame();
        displayGameSummary();
        bplayAgain = askToPlayAgain();
    } while(bplayAgain);

    return 0;
}

void displayGameIntro(){
    std::cout <<"      Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "        ,           ,          " << std::endl;
	std::cout << "       /             \\                /) (\\ " << std::endl;
	std::cout << "      ((__-^^-,-^^-__))          .-._((,~~.))_.-, " << std::endl;
	std::cout << "       `-_---' `---_-'            `-.   @@   ,-'" << std::endl;
	std::cout << "        <__|o` 'o|__>               / ,n--n. \\ " << std::endl;
	std::cout << "           \\  `  /                 ( ( .__. ) )" << std::endl;
	std::cout << "            ): :(                   ) `----' (" << std::endl;
	std::cout << "            (o_o)                  /`-. __ .-'\\ " << std::endl;
	std::cout << "             ' '   " << std::endl;
	std::cout << "\nCan you guess the " << BCGame.getWordLength();
	std::cout << " letter isogram I'm thinking of?";
	std::cout << std::endl;
	return;
};


void playGame(){
    
    int maxAttempt = BCGame.getMaxAttempt(); // maximum attempt
    int wordLength = BCGame.getWordLength(); // length of hidden word
    int currentTry = BCGame.getCurrentTry(); // counter
    bool isWon = false;

    BCGame.reset();
    
    FText playerGuess;
    FResponse response;

    while(currentTry < maxAttempt && !isWon) {
        std::cout << "Your guess: ";
        getline(std::cin, playerGuess);
        
        response = BCGame.submitPlayerGuess(playerGuess); // immediately get the response

        switch(response.guessStatus){
            
            case(EGuessStatus::Win):
                std::cout << "Congratulations! You guess it right" << std::endl;
                isWon = true;
                break;
            
            case(EGuessStatus::Valid):
                std::cout << "Bulls: " << response.bulls << std::endl;
                std::cout << "Cows: " << response.cows << std::endl;
                std::cout << "Your guess is: " <<  std::endl;
                break;

            case(EGuessStatus::Not_Alphabet):
                std::cout << "Invalid answer. " << "The input should be strictly alphabet." << std::endl;
                std::cout << "Please check your answer again before your submit." << std::endl;        
                break;

            case(EGuessStatus::Incorrect_Length):
                std::cout << "Incorrect length. " << "The hidden word should be strictly of length " << wordLength << std::endl;
                std::cout << "Please check your answer again before your submit." << std::endl;        
                break;

            default:
                break;
        }   

        currentTry = BCGame.getCurrentTry();
    }
    return ;
};

bool askToPlayAgain(){
    return true;
}

void displayGameSummary(){
    std::cout << "Summary: " << std::endl;
}


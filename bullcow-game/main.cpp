#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using uint32 = int;

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

    bool bplayAgain = False;
    displayGameIntro();
    
    do{
        playGame();
        displayGameSummary();

        bplayAgain = askToPlayAgain();

    } while(bplayAgain)

    return 0
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
	std::cout << "\nCan you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?";
	std::cout << std::endl;
	return;
};

void playGames(){
    
    int maxTries = BCGame.getMaxTry();
    int currentTry = 1;
    bool isWin = False;

    BCGame.reset();
    
    FText playerGuess, errorMsg;
    FResponse response;

    while(currentTry < maxTries && !isWin) {
        std::cout << "Your guess: ";
        getline(std:cin, playerGuess);
        
        response = BCGame.submitPlayerGuess();
        
        switch(response.guessStatus){
            case(eGuessStatus::Win):
                std::cout << "Congratulations! You guess it right" << std::endl;
                isWin = True;
                break;
            
            case(eGuessStatus::Valid):
                std::cout << "Bulls: " << response.bulls << std::endl;
                std::cout << "Cows: " << response.cows << std::endl;
                std::cout << "Your guess is: " <<  std::endl;
                break;

            case(eGuessStatus::Invalid):
                errorMsg = ""; //TODO: fill in error message

                std::cout << "Invalid answer" << std::endl;
                std::cout << "Please check your answer again before your submit." << std::endl;        
        
            default:
                break;
        }   

        return
        
    }
};


void displayGameSummary(){
    std::cout << "Summary: " << std:endl;
}


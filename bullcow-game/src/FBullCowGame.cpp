
#include <iostream>
#include <string>

#include "FBullCowGame.h"
#include <map>

// Unreal syntax
#define TMap std::map
using int32 = int;

bool isAlphabetText(FText);

FBullCowGame::FBullCowGame() { reset(); } // default constructor

int32 FBullCowGame::getCurrentTry() const { return currentTry; }

int32 FBullCowGame::getMaxAttempt() const { return maxAttempt; }

int32 FBullCowGame::getWordLength() const { return HIDDEN_WORD.length(); } // TODO: use mapping: difficulty-word length

int32 FBullCowGame::setDifficultyLevel() const { std::cout << "Difficulty level: hard" << std::endl; }

int32 setDifficultyLevel(){ return 0; }

void FBullCowGame::reset(){

    const FText hiddenWord = getHiddenWord();
    HIDDEN_WORD = hiddenWord;

    currentTry = 1;
    maxAttempt = 10;
    isWon = false;
}

FText FBullCowGame::getHiddenWord(){
    const FText hiddenWord = "bookish";
    return hiddenWord;
}

EGuessStatus FBullCowGame::checkValidity(FText playerGuess){
    EGuessStatus guessStatus;

    if(!isAlphabetText(playerGuess)){
        return EGuessStatus::Not_Alphabet;

    } else if(playerGuess.length() != HIDDEN_WORD.length()){
        return EGuessStatus::Incorrect_Length;
    
    }else{
        return EGuessStatus::Valid;
    }
}

FResponse FBullCowGame::submitPlayerGuess(FText playerGuess){
    FResponse response;

    EGuessStatus guessStatus = checkValidity(playerGuess);
    if(guessStatus== EGuessStatus::Valid){ // if answer/guess is valid, proceed
        // Counting bulls and cows
        for(int i=0; i<HIDDEN_WORD.length(); i++){
            if (playerGuess[i] == HIDDEN_WORD[i]){
                response.bulls++;
            }
        //TODO: count cows
        }
        // check Win condition
        if (response.bulls == HIDDEN_WORD.length()){ 
            response.guessStatus = EGuessStatus::Win;
            isWon = true;            
        }
    }

    response.guessStatus = guessStatus; 
    currentTry++;

    return response;
}

bool isAlphabetText(FText playerGuess){
    return true;
}

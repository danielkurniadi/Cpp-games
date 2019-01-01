
#include <iostream>
#include <string>

#include "FBullCowGame.h"
#include <map>

// Unreal syntax
#define TMap std::map
using int32 = int;


FBullCowGame::FBullCowGame() { reset(); } // default constructor

int32 FBullCowGame::getCurrentTry() const { return currentTry; }

int32 FBullCowGame::getMaxAttempt() const { return maxAttempt; }

int32 FBullCowGame::getWordLength() const { return wordLength; } // TODO: use mapping: difficulty-word length

int32 FBullCowGame::setDifficultyLevel() const { std::cout << "Difficulty level: hard" << std::endl; }

void FBullCowGame::reset(){

    const FText hiddenWord = "bookish";
    HIDDEN_WORD = hiddenWord;

    currentTry = 1;
    wordLength = 7;
    maxAttempt = 10;
    isWon = false;
}

FText FBullCowGame::getHiddenWord(){
    const FText hiddenWord = "bookish";
    return hiddenWord;
}

EGuessStatus FBullCowGame::checkValidity(FText playerGuess){
    return EGuessStatus::Valid;
}

FResponse FBullCowGame::submitPlayerGuess(FText playerGuess){
    FResponse response;
    response.bulls = 2;
    response.cows = 3;
    response.guessStatus = checkValidity(playerGuess);

    return response;
}



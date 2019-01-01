#include <iostream>
#include <string>

using FText = std::string;
using int32 = int;

enum class EGuessStatus {
    Not_Alphabet,
    Incorrect_Length,
    Valid,
    Win
};

struct FResponse {
    int32 bulls;
    int32 cows;
    EGuessStatus guessStatus;
};

class FBullCowGame {
    public:
        FBullCowGame(); // contructor
    
    public: 
        void reset();

        int32 getMaxAttempt() const;
        int32 getCurrentTry() const;
        int32 getWordLength() const;
        int32 setDifficultyLevel() const;

        FResponse submitPlayerGuess(FText);
    
    private:
        int currentTry=1;
        int wordLength=7;
        int maxAttempt=10;
        bool isWon=false;

    private:
        FText HIDDEN_WORD = "bookish";

    private:
        FText getHiddenWord();
        EGuessStatus checkValidity(FText);


}  ;
#include <iostream>
#include <string>

using Ftext = std::string;
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
}

class FBullCowGame {
    public:
        FBullCowGame(); // contructor
    
    public: 
        void reset();

        int32 getMaxTries() const;
        int32 getCurrentTry() const;
        int32 getHiddenWordLength() const;
        int32 setDifficultyLevel() const;

        FResponse submitPlayerGuess(FText playerGuess);
    
    private:
        FText getHiddenWord();
        EGuessStatus checkValidity(FText playerGuess);


}   
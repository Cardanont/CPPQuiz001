#include <iostream>

void PrintIntrodiction(int Difficulty)
{
    // Intro message
    
    std::cout << "\\n////////////////////////////////////////////////////////////////////////////\n";
    std::cout << "You are a secret agent breaking into a level " << Difficulty;  
    std::cout << " secure server room... \nYou need to enter the correct codes to continue...\n";
    std::cout << "//////////////////////////////////////////////////////////////////////////////\n\n";

}

bool PlayGame(int Difficulty)
{
    PrintIntrodiction(Difficulty);
    
    // Declare numbers codes
    const int CodeA = rand();
    const int CodeB = rand();
    const int CodeC = rand();

    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Printing the sum an product 

    std:: cout << "+ There are 3 numbers in the code";
    std:: cout << "\n+ The code add to " << CodeSum;
    std:: cout << "\n+ The codes multiply to give: " << CodeProduct;

    int GuessA, GuessB, GuessC;

    std:: cout << "\n\nGuess a number please: ";
    std:: cin >> GuessA >> GuessB >> GuessC;

    // Store player guess
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\nYou  Win! you are a champion man!\n\n";
        return true;
    }
    else
    {
        std::cout << "\nYou are wrong man, you lose \n\n";
        return false;
    }
}


int main()
{
    int LevelDifficulty = 1;
    int const MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty) // Loop game untill all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    return 0;
}
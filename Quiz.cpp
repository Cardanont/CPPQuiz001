#include <iostream>
#include <ctime>

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
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Printing the sum an product 

    std:: cout << "+ There are 3 numbers in the code";
    std:: cout << "\n+ The code add to " << CodeSum;
    std:: cout << "\n+ The codes multiply to give: " << CodeProduct;

    int GuessA, GuessB, GuessC;

    std:: cout << "\n\nGuess the codes, hurry!: ";
    std:: cin >> GuessA >> GuessB >> GuessC;

    // Store player guess
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n*** You  did it man! you have that file, keep going! ***\n\n";
        return true;
    }
    else
    {
        std::cout << "\n*** You are wrong man, you can try again... for now ***\n\n";
        return false;
    }
}


int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

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

    std::cout << "\n*** Congratulations you have all the files you need! I recommend you to get out of there. ***\n";
    
    return 0;
}
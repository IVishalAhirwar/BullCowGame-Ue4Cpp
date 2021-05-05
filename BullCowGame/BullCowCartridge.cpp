// Copyright© 2021 (Vishal Choudhary)VCGames Crop.
#include "BullCowCartridge.h"
#include<string.h>

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    int32 val=120;
    std::string Val=(std::string)val;






    
    FString vall=static_cast<FString>(TEXT(Val));

    PrintLine(TEXT("Val is: %s"),*vall);
    A = 0;
    B = 0;
    C = 0;
    DifficultyLevel=1;
    Init();
    //Init();
    INDEX = 0;
};

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (!bGameOver)
    {
        if (INDEX < 3)
        {

            Inout[INDEX] = Input;
            INDEX++;
            if (INDEX == 3)
            {
                PrintLine(TEXT("Conformed!"));
            };
        }
        else
        {
            PrintLine(TEXT("No Space Left in Array!"));
            for (int32 i = 0; i < 3; i++)
            {
                PrintLine(TEXT("You Entered:\nat INDEX %i = %s\n"), i, *Inout[i]);
                PrintLine(TEXT("Numbers were:\n%i\n%i\n%i"), A, B, C);
            };
            INDEX = 0;
            bGameOver=true;
        };
    }
    else
    {
        Init();
    }
};
void UBullCowCartridge::MakeGuess(int32&a, int32&b, int32&c)
{
    a = FMath::RandRange(0, 1+DifficultyLevel);
    b = FMath::RandRange(0, 1+DifficultyLevel);
    c = FMath::RandRange(0, 1+DifficultyLevel);
    int32 sum=a+b+c;
    int32 mult= a*b*c;
    PrintLine(TEXT("ENTER THREE NUMBERS\nTHAT Adds up to =%i\n Multiply will be = %i"),sum,mult);
};
void UBullCowCartridge::Init()
{
    ClearScreen();
    bGameOver = false;
    MakeGuess(A, B, C);
};
void UBullCowCartridge::CheckGuess()const
{

    
};


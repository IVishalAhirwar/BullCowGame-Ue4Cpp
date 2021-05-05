// Copyright© 2021 (Vishal Choudhary)VCGames Crop. 
#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
//#include<string>
#include "BullCowCartridge.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString &Input) override;
	void MakeGuess(int32&a,int32&b,int32&c);
	void Init();
	void CheckGuess()const;

	

private:
	int32 Lives;
	bool bGameOver;
	int32 INDEX;
	FString Inout[3];
	int32 A,B,C,DifficultyLevel;
};

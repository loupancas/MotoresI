// Fill out your copyright notice in the Description page of Project Settings.


#include "TDGameInstance.h"
#include <kismet/GameplayStatics.h>
#include "TDSaveGame.h"

const FString MainSaveSlotName = TEXT("MainSave");
UTDGameInstance::UTDGameInstance()
{
	SaveSlotIndex = 0;
	SaveSlotNames.Add(0, TEXT("SaveSlotOne"));
	SaveSlotNames.Add(1, TEXT("SaveSlotTwo"));
	SaveSlotNames.Add(2, TEXT("SaveSlotThree"));
	SaveSlotNames.Add(3, TEXT("SaveSlotFour"));
	SaveSlotNames.Add(4, TEXT("SaveSlotFive"));
}

void UTDGameInstance :: Init()
{
	LoadMain();
	Super::Init();
	
}

int32 UTDGameInstance::GetSaveSlot()
{
	return SaveSlotIndex;
}

FString UTDGameInstance::GetSaveSlotName(int32 Index) const
{
	return SaveSlotNames.FindRef(Index);
}

void UTDGameInstance::LoadMain()
{
	UTDSaveGame * MainSaveGame = Cast<UTDSaveGame>(UGameplayStatics::LoadGameFromSlot(MainSaveSlotName, 0));
	if (MainSaveGame)
	{
		SaveSlotIndex = MainSaveGame->SaveSlotIndex;

	}
}

void UTDGameInstance::SaveMain()
{
	UTDSaveGame* MainSaveGame = Cast<UTDSaveGame>(UGameplayStatics::CreateSaveGameObject(UTDSaveGame::StaticClass()));
	if (!MainSaveGame)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create SaveGame"));
		return;
	}

	MainSaveGame->SaveSlotIndex = SaveSlotIndex;
	if (!UGameplayStatics::SaveGameToSlot(MainSaveGame, MainSaveSlotName, 0))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to Save Game"));

	}

	LoadMain();

}

void UTDGameInstance::SetSaveSlot(int32 Index)
{
	SaveSlotIndex = Index;
	SaveMain();
}


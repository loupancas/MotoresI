// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TDGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MOTORESI_API UTDGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		int32 SaveSlotIndex;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TMap <int32, FString> SaveSlotNames;

    public:
		UTDGameInstance();
		virtual void Init() override;
		virtual void LoadMain();
		virtual void SaveMain();
		UFUNCTION(BlueprintPure)
		virtual int32 GetSaveSlot();
		UFUNCTION(BlueprintCallable)
		virtual void SetSaveSlot(int32 Index);
		UFUNCTION(BlueprintPure)
		virtual FString GetSaveSlotName(int32 Index) const;

};

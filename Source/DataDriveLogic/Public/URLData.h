// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "URLData.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVELOGIC_API UURLData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="URLData")
	void GetURLMap(TMap<FName,FString>& Receiver) const;

	UFUNCTION(BlueprintCallable,Category="URLData")
	void GetDefaultName(FName& Receiver) const;
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="URLData")
	TMap<FName,FString> NameToURLMap;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="URLData")
	FName DefaultURLName;
};

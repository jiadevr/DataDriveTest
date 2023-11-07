// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Logging/LogMacros.h"
#include "URLData.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(URLDataAsset, Log, All);
/**
 * 
 */
UCLASS(Config="GGameUserSettingsIni")
class DATADRIVELOGIC_API UURLData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UURLData();
	
	virtual void PostInitProperties() override;
	
	UFUNCTION(BlueprintCallable,Category="URLData")
	void GetURLMap(TMap<FName,FString>& Receiver);

	UFUNCTION(BlueprintCallable,Category="URLData")
	void GetDefaultName(FName& Receiver) const;

	UFUNCTION(Category="CustomURL")
	bool SetCustomURLAndSaveToIni(const FString& InCustomURL);

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Config,Category="URLData",meta=(ConfigRestartRequired = true))
	TMap<FName,FString> NameToURLMap;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Config,Category="URLData",meta=(ConfigRestartRequired = true))
	FName DefaultURLName;
	
};

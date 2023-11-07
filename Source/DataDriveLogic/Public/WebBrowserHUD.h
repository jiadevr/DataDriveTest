// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Logging/LogMacros.h"
#include "WebBrowserHUD.generated.h"

class UURLData;

DECLARE_LOG_CATEGORY_EXTERN(URLHUD, Log, All);
/**
 * 
 */
UCLASS()
class DATADRIVELOGIC_API AWebBrowserHUD : public AHUD
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable,Category="WebURL")
	void InitialURL();

	UFUNCTION(BlueprintCallable,Category="CustomURL")
	bool SetCustomURL(const FString& NewCustomURL);

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WebURL")
	TMap<FName,FString> URLMap;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WebURL")
	FName DefaultURLName;

	UPROPERTY()
	UURLData* CurrentURLDataAsset;

	UFUNCTION(BlueprintCallable,Category="WebURL")
	void RefreshURLData();
	
};

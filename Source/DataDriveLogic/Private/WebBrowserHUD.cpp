// Fill out your copyright notice in the Description page of Project Settings.


#include "DataDriveLogic/Public/WebBrowserHUD.h"

#include "URLData.h"
#include "WebBrowserWorldData.h"

DEFINE_LOG_CATEGORY(URLHUD)

void AWebBrowserHUD::BeginPlay()
{
	Super::BeginPlay();
	InitialURL();
}

void AWebBrowserHUD::InitialURL()
{
	AWorldSettings* CustomWorldSetting = GetWorldSettings();
	if (nullptr == CustomWorldSetting)
	{
		UE_LOG(URLHUD, Error, TEXT("Get NUll World Settings"));
		return;
	}
	AWebBrowserWorldData* URLSettings = Cast<AWebBrowserWorldData>(CustomWorldSetting);
	if (nullptr == URLSettings)
	{
		UE_LOG(URLHUD, Error, TEXT("Get World Settings,But Not Match AWebBrowserWorldData"));
		return;
	}
	if (!URLSettings->URLDataForCurrentWorld)
	{
		UE_LOG(URLHUD, Error, TEXT("AWebBrowserWorldData Define None URLData"));
	}
	CurrentURLDataAsset = URLSettings->URLDataForCurrentWorld;
	RefreshURLData();
	if (!URLMap.Contains(DefaultURLName))
	{
		UE_LOG(URLHUD, Error, TEXT("Find Null URL Data Named:%s"), *DefaultURLName.ToString());
		return;
	}
	UE_LOG(URLHUD,Display,TEXT("Initial URL Finished!"))
}

bool AWebBrowserHUD::SetCustomURL(const FString& NewCustomURL)
{
	if (!CurrentURLDataAsset)
	{
		return false;
	}
	const bool bSetSuccess = CurrentURLDataAsset->SetCustomURLAndSaveToIni(NewCustomURL);
	RefreshURLData();
	return bSetSuccess;
}

void AWebBrowserHUD::RefreshURLData()
{
	if (!CurrentURLDataAsset)
	{
		UE_LOG(URLHUD, Error, TEXT("Find Null URLData"))
		return;
	}
	CurrentURLDataAsset->GetURLMap(URLMap);
//debug
	for (auto Element : URLMap)
	{
		UE_LOG(URLHUD,Display,TEXT("Load URL Named: %s,Value:%s"), *Element.Key.ToString(), *Element.Value);
	}
	
	CurrentURLDataAsset->GetDefaultName(DefaultURLName);
	UE_LOG(URLHUD,Display,TEXT("Load Default Named: %s"), *DefaultURLName.ToString());
	return;
}

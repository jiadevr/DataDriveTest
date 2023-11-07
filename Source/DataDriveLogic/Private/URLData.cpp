// Fill out your copyright notice in the Description page of Project Settings.


#include "DataDriveLogic/Public/URLData.h"
DEFINE_LOG_CATEGORY(URLDataAsset)

UURLData::UURLData()
{
	LoadConfig();
}

void UURLData::PostInitProperties()
{
	Super::PostInitProperties();
	LoadConfig();
}

void UURLData::GetURLMap(TMap<FName, FString>& Receiver)
{
	//GConfig->Flush(true,GGameUserSettingsIni);
	LoadConfig(this->StaticClass(),*GGameUserSettingsIni);
	//ReloadConfig(this->StaticClass(),*GGameUserSettingsIni);
	Receiver=NameToURLMap;
	UE_LOG(URLDataAsset,Display,TEXT("Reload URL From: %s, Value Below:"),*GGameUserSettingsIni);
	for (const auto& Element : NameToURLMap)
	{
		UE_LOG(URLDataAsset,Display,TEXT("URL Name:%s, Value:%s"),*Element.Key.ToString(),*Element.Value);
	}
}

void UURLData::GetDefaultName(FName& Receiver) const
{
	Receiver=DefaultURLName;
}

bool UURLData::SetCustomURLAndSaveToIni(const FString& InCustomURL)
{
	NameToURLMap.Add(FName("custom"),InCustomURL);
	UE_LOG(URLDataAsset,Display,TEXT("Set Custom URL: %s"),*InCustomURL);
	SaveConfig();
	GConfig->Flush(false,GGameUserSettingsIni);
	return true;
}


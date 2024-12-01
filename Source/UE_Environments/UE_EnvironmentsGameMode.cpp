// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_EnvironmentsGameMode.h"
#include "UE_EnvironmentsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_EnvironmentsGameMode::AUE_EnvironmentsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

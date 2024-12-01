// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_EnvironmentsPickUpComponent.h"

UUE_EnvironmentsPickUpComponent::UUE_EnvironmentsPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UUE_EnvironmentsPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UUE_EnvironmentsPickUpComponent::OnSphereBeginOverlap);
}

void UUE_EnvironmentsPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AUE_EnvironmentsCharacter* Character = Cast<AUE_EnvironmentsCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}

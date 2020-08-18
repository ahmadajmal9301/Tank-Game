// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController Can't find Player"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController Found Player"))
	}
}

ATank* ATankAIController::GetPlayerTank() const 
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) {
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
	
}
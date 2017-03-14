// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;
	
	ATank* GetControlledTank() const;

public:
	ATankPlayerController();

	virtual void Tick(float DeltaTime) override;

private:
	float Range = 100.f;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333f;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;


	FVector2D ScreenLocation();
	FVector GetSightLineStart();
	FVector GetSightLineEnd();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, category = "Combat")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere, category = "Movement")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, category = "Combat")
	class UParticleSystem* HitParticles;

	UPROPERTY(VisibleAnywhere, category = "Combat")
	class UParticleSystemComponent* TrailParticles;

	UPROPERTY(EditAnywhere, category = "Combat")
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, category = "Combat")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, category = "Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
};

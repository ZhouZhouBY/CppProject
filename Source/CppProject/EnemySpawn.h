// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "EnemySpawn.generated.h"

UCLASS()
class CPPPROJECT_API AEnemySpawn : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* SpawnArea;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AEnemy> EnemyType;

	UPROPERTY(EditAnywhere)
	float spawnSpan = 1.0f;

	UFUNCTION()
	void SpawnEnemy();

public:	
	// Sets default values for this actor's properties
	AEnemySpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle SpawnHandle;

};

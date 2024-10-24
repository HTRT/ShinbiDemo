// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayEffectTypes.h"
#include "BaseCharacter.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHPChangeEvent, float, NewValue);

UCLASS()
class SHINBIDEMO_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties 
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 通过委托进行广播
	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHPChangeEvent HPChangeEvent;

	// 角色生命值改变时调用
	void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);
};

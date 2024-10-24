// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
// #include "Materials/MaterialInstance.h"
#include "BaseGameplayAbility.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ECostType : uint8
{
	HP,
	MP,
	Strength
};


USTRUCT(BlueprintType) 
struct FGameplayAbilityInfoClass
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	float CD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	ECostType CostType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	float CostValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	UMaterialInstance* IconMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TSubclassOf<UBaseGameplayAbility> AbilityClass;

	FGameplayAbilityInfoClass() {}

	FGameplayAbilityInfoClass(
		float CD,
		ECostType CostType,
		float CostValue,
		UMaterialInstance* IconMaterial,
		TSubclassOf<UBaseGameplayAbility> Ability)
		: CD(CD), CostType(CostType), CostValue(CostValue), IconMaterial(IconMaterial), AbilityClass(Ability) {} 

};


UCLASS()
class SHINBIDEMO_API UBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
	UMaterialInstance* IconMaterial;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	FGameplayAbilityInfoClass GetAbilityInfo(int level);

};

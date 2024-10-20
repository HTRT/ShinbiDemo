// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BasicAttributeSet.generated.h"

/**
 * 
 */

// ͨ�������������Ե�Getter��Setter��Initter����
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

// ʹ�ø�ʽ:  ATTRIBUTE_ACCESSORS(UMyHealthSet, Health)

UCLASS()
class SHINBIDEMO_API UBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Set")
	FGameplayAttributeData HP;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, HP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Set")
	FGameplayAttributeData MaxHP;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxHP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Set")
	FGameplayAttributeData MP;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Set")
	FGameplayAttributeData MaxMP;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxMP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Set")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Strength);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Set")
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxStrength);
};

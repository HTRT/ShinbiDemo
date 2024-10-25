// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/BaseGameplayAbility.h"

FGameplayAbilityInfoClass::FGameplayAbilityInfoClass() : 
    CD(0),
    CostValue(0),
    CostType(ECostType::HP),
    IconMaterial(nullptr),
    AbilityClass(nullptr)
{
}

FGameplayAbilityInfoClass::FGameplayAbilityInfoClass(float CD, ECostType CostType, float CostValue, UMaterialInstance* IconMaterial, TSubclassOf<UBaseGameplayAbility> Ability):
    CD(CD),
    CostType(CostType),
    CostValue(CostValue),
    IconMaterial(IconMaterial),
    AbilityClass(Ability)
{
}

FGameplayAbilityInfoClass UBaseGameplayAbility::GetAbilityInfo(int level)
{
    UGameplayEffect* CDEffect = GetCooldownGameplayEffect();
    UGameplayEffect* CostEffect = GetCostGameplayEffect();
    float CD = 0;
    float CostValue = 0;
    ECostType CostType = ECostType::HP;

    if (CostEffect && CDEffect)
    {
        CDEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(level, CD);
        if (CostEffect->Modifiers.Num() > 0)
        {
            FGameplayModifierInfo CostEffectModifierInfo = CostEffect->Modifiers[0];
            CostEffectModifierInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(level, CostValue);
            FString CostTypeName = CostEffectModifierInfo.Attribute.AttributeName;

            if (CostTypeName == "HP")
            {
                CostType = ECostType::HP;
            }

            if (CostTypeName == "MP")
            {
                CostType = ECostType::MP;
            }

            if (CostTypeName == "Strength")
            {
                CostType = ECostType::Strength;
            }
            return FGameplayAbilityInfoClass(CD, CostType, CostValue, IconMaterial, GetClass());
        }
    }

    return FGameplayAbilityInfoClass();
}
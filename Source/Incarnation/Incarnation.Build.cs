// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Incarnation : ModuleRules
{
	public Incarnation(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "GameplayTags",
            "GameplayTasks",
            "GameplayAbilities"
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		
	}
}

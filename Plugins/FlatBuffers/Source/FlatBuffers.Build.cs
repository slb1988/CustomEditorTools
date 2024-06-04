// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using System.Reflection;
using UnrealBuildTool;

public class FlatBuffers : ModuleRules
{
	public FlatBuffers(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//OptimizeCode = CodeOptimization.Never;
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				"Includes",
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core", 
				"Engine",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine",
				"Projects",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}

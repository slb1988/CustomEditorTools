namespace UnrealBuildTool.Rules
{
    public class NamingConventionValidation : ModuleRules
    {
        public NamingConventionValidation( ReadOnlyTargetRules Target )
            : base( Target )
        {
            PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

            PrivateIncludePaths.Add("NamingConventionValidation/Private");

            PublicDependencyModuleNames.AddRange(
                new string[] { 
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "TargetPlatform",
                    "AssetRegistry",
                    "EditorSubsystem",
                    "DeveloperSettings",
                    "MessageLog"
                }
            );

            PrivateDependencyModuleNames.AddRange(
                new string[] {
                    "Slate",
                    "SlateCore",
                    "UnrealEd",
                    "AssetRegistry",
                    "EditorStyle",
                    "Blutility"
                }
            );
        }
    }
}

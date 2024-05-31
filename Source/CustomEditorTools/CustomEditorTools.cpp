// Copyright Epic Games, Inc. All Rights Reserved.

#include "CustomEditorTools.h"
#include "Modules/ModuleManager.h"

#include "GameDelegates.h"

#if UE_EDITOR
#include "ISourceControlModule.h"
#include "ISourceControlProvider.h"
#include "MySourceControlSettings.h"

FDelegateHandle FCustomEditorToolModule::ModifyCookDelegateHandle;

#endif


void FCustomEditorToolModule::StartupModule()
{

#if UE_EDITOR
	if (!ModifyCookDelegateHandle.IsValid())
	{
		ModifyCookDelegateHandle = FGameDelegates::Get().GetModifyCookDelegate().AddRaw(this, &FCustomEditorToolModule::OnModifyCook);
	}
	SourceControlRegisterStateBranches();
#endif

}

void FCustomEditorToolModule::ShutdownModule()
{
#if UE_EDITOR

	if (ModifyCookDelegateHandle.IsValid())
	{
		FGameDelegates::Get().GetModifyCookDelegate().Remove(ModifyCookDelegateHandle);
		ModifyCookDelegateHandle.Reset();
	}
#endif
}

bool FCustomEditorToolModule::IsGameModule() const
{
	return true;
}

#if UE_EDITOR
void FCustomEditorToolModule::OnModifyCook(TArrayView<const ITargetPlatform* const> InTargetPlatforms, TArray<FName>& InOutPackagesToCook, TArray<FName>& InOutPackagesToNeverCook)
{
	//USQLiteQuerySubsystem::QueryDataWindow(nullptr,
	//	[this, &InOutPackagesToCook](TUniquePtr<FSQLiteQuery>& SqlQuery) {
	//		if (!SqlQuery.IsValid())
	//		{
	//			return;
	//		}

	//		FString SqlState = FString(TEXT("SELECT * FROM AssetPath"));

	//		FSQLiteResultWrapper Result;
	//		SqlQuery->ExecuteSQL(SqlState, Result);
	//		while (Result.StepAndCheckRow())
	//		{
	//			FString TempFullPath;
	//			if (Result.GetColumnStringValueByName(TEXT("FullPath"), TempFullPath))
	//			{
	//				TempFullPath = TempFullPath.Replace(TEXT("/Game/"), TEXT("../../../TRing/Content/"));
	//				int32 LastDotIndex = -1;
	//				if (TempFullPath.FindLastChar('.', LastDotIndex))
	//				{
	//					TempFullPath.RemoveAt(LastDotIndex, TempFullPath.Len() - LastDotIndex);
	//					TempFullPath += ".uasset";
	//					InOutPackagesToCook.Add(FName(TempFullPath));
	//				}
	//			}
	//		}
	//	});
}

void FCustomEditorToolModule::SourceControlRegisterStateBranches()
{
	const ISourceControlModule& SourceControlModule = ISourceControlModule::Get();
	if (SourceControlModule.IsEnabled())
	{
		ISourceControlProvider& SourceControlProvider = SourceControlModule.GetProvider();
		if (SourceControlProvider.GetName() == "Perforce")
		{
			if (const UMySourceControlSettings* MySourceControlSettings = GetDefault<UMySourceControlSettings>())
			{
				SourceControlProvider.RegisterStateBranches(MySourceControlSettings->BranchNames, MySourceControlSettings->ContentRootIn);
			}
		}
	}
}
#endif

IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, CustomEditorTools, "CustomEditorTools");
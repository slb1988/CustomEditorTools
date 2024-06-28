// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "IPlatformFilePak.h"
#include "Engine/StaticMeshActor.h"

UE_DISABLE_OPTIMIZATION


void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	// 获取当前使用的平台
	InnerPlatformFile = &FPlatformFileManager::Get().GetPlatformFile();
	UE_LOG(LogTemp, Warning, TEXT("InnerPlatformFile: %s"), InnerPlatformFile->GetName());

	// 初始化PakPlatformFile
	PakPlatformFile = MakeShareable(new FPakPlatformFile());
	PakPlatformFile.Get()->Initialize(InnerPlatformFile, TEXT(""));

	
	// auto LoadedObj = StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/DLC/SM_Cube.SM_Cube"));

}

FString ConvertToGamePath(const FString& InPath)
{
	// 将输入路径标准化
	FString NewPath = InPath;
	NewPath.RemoveFromEnd(TEXT(".uasset"));
	NewPath.ReplaceInline(TEXT("\\"), TEXT("/"), ESearchCase::CaseSensitive);

	// 移除/Content/相对路径前缀
	int32 Pos = NewPath.Find("/Content/");
	NewPath.RightChopInline(Pos + 8);
	int32 LastSlashIndex;
	if (!NewPath.FindLastChar('/', LastSlashIndex))
	{
		UE_LOG(LogTemp, Warning, TEXT("cannot find / in string : %s"), *NewPath);
		NewPath = TEXT("/Game") + NewPath;
	}
	else
	{
		FString FileName = NewPath.Right(NewPath.Len() - LastSlashIndex - 1);
		NewPath = TEXT("/Game") + NewPath + TEXT(".") + FileName;
	}

	return NewPath;
	
}

void AMyPlayerController::TestLoadPak(FString InPakFullPath)
{
	FString PakFileFullPath = InPakFullPath;

	FPakFile* TmpPak = new FPakFile(PakPlatformFile.Get(), *PakFileFullPath, false);
	FString PakMountPoint = TmpPak->GetMountPoint();
	int32 Pos = PakMountPoint.Find("Content/");
	FString NewMountPoint = PakMountPoint.RightChop(Pos);
	NewMountPoint = FPaths::ProjectDir() + NewMountPoint;

	// 将MountPoint转为相对路径，和内置的统一
	TmpPak->SetMountPoint(*NewMountPoint);
	
	if (PakPlatformFile->Mount(*PakFileFullPath, 1, *NewMountPoint))
	{
		FPlatformFileManager::Get().SetPlatformFile(*PakPlatformFile.Get());

		TArray<FString> FoundFileNames;
		int32 FileNum = TmpPak->GetNumFiles();
		const FPakInfo& PakInfo = TmpPak->GetInfo();

		// Solution 1 L"../../../CustomEditorTools/Content/DLC/SM_Cube.uasset"
		FString FilePath = FPaths::ProjectContentDir() / TEXT("DLC/SM_Cube.uasset");
		if (PakPlatformFile->FileExists(*FilePath))
		{
			IFileHandle* FileHandle = PakPlatformFile->OpenRead(*FilePath);
			if (FileHandle)
			{
				int64 FileSize = FileHandle->Size();

				TArray<uint8> FileData;
				FileData.SetNumUninitialized(FileSize);
				FileHandle->Read(FileData.GetData(), FileSize);
				delete FileHandle;

				UE_LOG(LogTemp, Log, TEXT("Successfully read file: %s"), *FilePath);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to open file : %s"), *FilePath);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("File does not exist : %s"), *FilePath);
		}

		// Solution 2
		FPakEntry PakEntry;
		const FPakFile::EFindResult FindResult = TmpPak->Find(FilePath, &PakEntry);
		if (FindResult == FPakFile::EFindResult::Found)
		{
			FSharedPakReader PakReader = TmpPak->GetSharedReader(NULL);
			PakReader->Seek(PakEntry.Offset);
			uint8* FileData = new uint8[PakEntry.Size];
			PakReader->Serialize(FileData, PakEntry.Size);

			delete[] FileData;
		}

		// Solution3 FPakPlatformFile & PakFileSystem
		

		FString GamePath = ConvertToGamePath(FilePath);

		UObject* LoadedObj = StaticLoadObject(UObject::StaticClass(), NULL, *GamePath);
		if (!IsValid(LoadedObj))
		{
			UE_LOG(LogTemp, Error, TEXT("StaticLoadObject error : %s"), *GamePath);
		}
		// LoadedObj = StaticLoadObject(UObject::StaticClass(), NULL, TEXT("../../../CustomEditorTools/Content/DLC/SM_Cube.uasset"));
		//
		// LoadedObj = StaticLoadObject(UObject::StaticClass(), NULL, TEXT("../../../CustomEditorTools/Content/DLC/SM_Cube"));
		//
		// LoadedObj = StaticLoadObject(UObject::StaticClass(), NULL, TEXT("../../../CustomEditorTools/Content/DLC/SM_Cube.SM_Cube"));
		//
		// LoadedObj = StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/DLC/SM_Cube.uasset"));

		
		UStaticMesh* SM = Cast<UStaticMesh>(LoadedObj);
		if (SM)
		{
			AStaticMeshActor* MeshActor = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), FVector(0,0,460), FRotator(0,0,0) );
			MeshActor->SetMobility(EComponentMobility::Movable);
			MeshActor->GetStaticMeshComponent()->SetStaticMesh(SM);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Cast<UStaticMesh> error : %s"), *FilePath);
		}
	}

	FPlatformFileManager::Get().SetPlatformFile(*InnerPlatformFile);
}
UE_ENABLE_OPTIMIZATION
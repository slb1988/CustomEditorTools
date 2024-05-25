//
//  DebugHeader.h
//  CustomEditorToolsEditor (Mac)
//
//  Created by sun on 2024/5/25.
//  Copyright © 2024 Epic Games, Inc. All rights reserved.
//

#ifndef DebugHeader_h
#define DebugHeader_h

void Print(const FString& Message, const FColor& Color)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 8.f, Color, Message);
    }
}

void PrintLog(const FString& Message)
{
    UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}

#endif /* DebugHeader_h */

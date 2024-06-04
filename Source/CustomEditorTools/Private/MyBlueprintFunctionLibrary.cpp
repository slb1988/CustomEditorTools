// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::PrintObjectProperties(UObject* Object, int32 Indent)
{
    if (!Object)
    {
        UE_LOG(LogTemp, Warning, TEXT("Object is null"));
        return;
    }

    // Get the class of the object
    UClass* ObjectClass = Object->GetClass();

    // Print object class name with indentation
    FString IndentString = FString::ChrN(Indent, TEXT(' '));
    UE_LOG(LogTemp, Log, TEXT("%sClass: %s"), *IndentString, *ObjectClass->GetName());

    // Iterate over properties
    for (TFieldIterator<FProperty> PropIt(ObjectClass); PropIt; ++PropIt)
    {
        FProperty* Property = *PropIt;

        // Print the property
        PrintProperty(Property, Property->ContainerPtrToValuePtr<void>(Object), Indent + 2);
    }
}

void UMyBlueprintFunctionLibrary::PrintProperty(FProperty* Property, void* PropertyValue, int32 Indent)
{
    // Get the property name
    FString PropertyName = Property->GetName();

    // Create an indentation string
    FString IndentString = FString::ChrN(Indent, TEXT(' '));

    // Check if the property is an object or a primitive type
    if (FObjectProperty* ObjectProperty = CastField<FObjectProperty>(Property))
    {
        // It's an object property, print the object class name
        UObject* SubObject = ObjectProperty->GetObjectPropertyValue(PropertyValue);
        if (SubObject)
        {
            UE_LOG(LogTemp, Log, TEXT("%s%s:"), *IndentString, *PropertyName);
            PrintObjectProperties(SubObject, Indent + 2);
        }
        else
        {
            UE_LOG(LogTemp, Log, TEXT("%s%s: null"), *IndentString, *PropertyName);
        }
    }
    else
    {
        // It's a primitive type, print the value
        FString PropertyValueString;
        Property->ExportTextItem(PropertyValueString, PropertyValue, nullptr, nullptr, 0);
        UE_LOG(LogTemp, Log, TEXT("%s%s: %s"), *IndentString, *PropertyName, *PropertyValueString);
    }
}

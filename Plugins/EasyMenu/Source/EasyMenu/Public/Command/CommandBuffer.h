#pragma once
#include "EasyMenuCommand.h"

class EASYMENU_API FEMCommandBuffer
{
	public:
	void Reset()
	{
		Buffer.Reset();
		Idx = 0;
	}

	template<typename TCmd>
	void Write(TCmd& InCmd)
	{
		InCmd.CommandType = TCmd::Type;
		uint32 CurrentIdx = Buffer.AddUninitialized(sizeof(TCmd));
		TCmd* Cmd = reinterpret_cast<TCmd*>(Buffer.GetData() + CurrentIdx);
		new (Cmd)TCmd(InCmd);
	}

	EEMCommandType Peek()
	{
		if (Idx >= Buffer.Num()) return EEMCommandType::Unknown;
		return reinterpret_cast<FEMCommand*>(Buffer.GetData() + Idx)->CommandType;
	}

	template<typename TCmd>
	TCmd Read()
	{
		check(TCmd::Type == Peek());
		check(Idx + sizeof(TCmd) <= Buffer.Num());

		TCmd* Cmd = reinterpret_cast<TCmd*>(Buffer.GetData() + Idx);
		Idx += sizeof(TCmd);
		return MoveTemp(*Cmd);
	}
private:
	TArray<uint8> Buffer;
	int32 Idx = 0;
};

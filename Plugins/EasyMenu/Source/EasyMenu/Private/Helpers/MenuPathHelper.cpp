#include "Helpers/MenuPathHelper.h"

#include "ContentBrowserModule.h"
#include "EasyMenuGlobal.h"
#include "EasyMenuSubSystem.h"
#include "Editor.h"
#include "EMMultiPopupMenu.h"
#include "EMSinglePopupMenu.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Textures/SlateIcon.h"


FMenuPathHelper::FMenuPathHelper()
{
}
//根据路径添加menu
void FMenuPathHelper::AddMenu(const FString& InPath, UFunction* InFunction, UClass* InTargetClass, bool AddToFunctionInfos)
{
	check(InFunction);
	check(InTargetClass);
	TArray<FString> MenuItems;
	InPath.ParseIntoArray(MenuItems, TEXT("/"));

	FMenuNode* CurNode = nullptr;
	for(int i = 0; i < MenuItems.Num(); i++)
	{
		FString NameTmp = MenuItems[i];
		FString MenuItemName, SectionName;
		TSharedPtr<FMenuNode> Node = nullptr;
		//格式“TitleName.MenuName”
		if(!NameTmp.Split(TEXT("."), &SectionName, &MenuItemName))
		{
			MenuItemName = NameTmp;
		}
		if(i == 0)
		{
			Node = FindMenuNodeByNodeName(MenuNodes, MenuItemName);
		}
		else if (i > 0 && CurNode != nullptr)
		{
			Node = FindMenuNodeByNodeName(CurNode->ChildNodes, MenuItemName);
		}
		if(Node == nullptr)
		{
			TSharedPtr<FMenuNode> NewNode = MakeShareable(new FMenuNode());
			NewNode->MenuName = MenuItemName;
			NewNode->SectionName = SectionName;
			Node = NewNode;
			if(i == 0)//最高层级
			{
				MenuNodes.Add(NewNode);
			}
			else//子菜单
			{
				NewNode->Parent = CurNode;
				CurNode->ChildNodes.Add(NewNode);
			}
			if(InFunction->HasMetaData("EMEnumSinglePopupMenu"))
			{
				NewNode->MenuType = SingleEnumPopup;
			}
			else if(InFunction->HasMetaData("EMEnumMultiPopupMenu"))
			{
				NewNode->MenuType = MultiEnumPopup;
			}
			else
			{
				NewNode->MenuType = Normal;
			}
		}
		CurNode = Node.Get();
		//最后一层逻辑
		if(i == MenuItems.Num() - 1)
		{
			CurNode->BoundFunction = InFunction;
			CurNode->TargetEnum = InFunction->GetMetaData(TEXT(TEXT_EM_ENUM));
			FString StyleSet, StyleName;
			if (InFunction->HasMetaData(TEXT(TEXT_EM_ICON)))
			{
				FString IconPath = InFunction->GetMetaData(TEXT(TEXT_EM_ICON));
				if (!IconPath.Split(TEXT("::"), &StyleSet, &StyleName))
				{
					StyleSet = TEXT(TEXT_EM_STYLE);
					StyleName = InFunction->GetOuter()->GetName() + TEXT(".") + InFunction->GetName();
					CurNode->StyleSet = StyleSet;
					CurNode->StyleName = StyleName;
				}
			}
			
			if(AddToFunctionInfos)
			{
				FMenuFunctionInfo Info;
				Info.Path = InPath;
				Info.TargetClass = InTargetClass;
				Info.ToolTip = InFunction->GetMetaData("ToolTip");
				FunctionInfos.Add(InFunction, MoveTemp(Info));
			}
		}
	}
}

void FMenuPathHelper::SortPath()
{
	SortPath(MenuNodes);
}

void FMenuPathHelper::SortPath(TArray<TSharedPtr<FMenuNode>>& ListNodes)
{
	ListNodes.Sort([](const TSharedPtr<FMenuNode> a, const TSharedPtr<FMenuNode> b)
	{
		if (a->SectionName == b->SectionName)
		{
			return a->MenuName < b->MenuName;
		}
		return a->SectionName < b->SectionName;
	});
	for(TSharedPtr<FMenuNode> node : ListNodes)
	{
		SortPath(node->ChildNodes);
	}
}


void FMenuPathHelper::SetPathIcon(const FString& InPath, const FString& InIconPath)
{
	FString Path = InPath;
	FString NodeName;
	TSharedPtr<FMenuNode> CurNode = nullptr;
	TArray<TSharedPtr<FMenuNode>>* NodeArray = &MenuNodes;
	
	if (!Path.Split(TEXT("/"), &NodeName, &Path))
	{
		NodeName = MoveTemp(Path);
	}

	do
	{
		NodeName.Split(TEXT("."), nullptr, &NodeName);
		for(TSharedPtr<FMenuNode> Node : *NodeArray)
		{
			if(Node->MenuName == NodeName)
			{
				CurNode = Node;
				break;
			}
		}
		if (!CurNode)
			return;
		NodeArray = &CurNode->ChildNodes;
	} while (Path.Split(TEXT("/"), &NodeName, &Path));

	if (!Path.IsEmpty())
	{
		NodeName = MoveTemp(Path);
		NodeName.Split(TEXT("."), nullptr, &NodeName);
		for(TSharedPtr<FMenuNode> Node : *NodeArray)
		{
			if(Node->MenuName == NodeName)
			{
				CurNode = Node;
				break;
			}
		}
		if (!CurNode)
			return;
	}
	if (!InIconPath.Split(TEXT("::"), &CurNode->StyleSet, &CurNode->StyleName))
	{
		CurNode->StyleSet = TEXT(TEXT_EM_STYLE);
		CurNode->StyleName = TEXT("Path.")+ InPath;
		UEasyMenuSubSystem::Instance()->AddIcon(CurNode->StyleName, InIconPath);
	}
}


TSharedPtr<FMenuNode> FMenuPathHelper::FindMenuNodeByNodeName(TArray<TSharedPtr<FMenuNode>> MenuList, FString MenuName)
{
	for(int i = 0; i < MenuList.Num(); i++)
	{
		if(MenuList[i]->MenuName == MenuName)
		{
			return MenuList[i];
		}
	}
	return nullptr;
}

//获取UE菜单栏并向菜单栏添加新的菜单项
TSharedPtr<FExtender> FMenuPathHelper::GetMenuBarExtender(FName InHookName, EExtensionHook::Position InPosition)
{
	TSharedPtr<FExtender> Extender = MakeShared<FExtender>();

	for (TSharedPtr<FMenuNode> Node : MenuNodes)
	{
		Extender->AddMenuBarExtension(
			InHookName,
			InPosition,
			nullptr,
			FMenuBarExtensionDelegate::CreateRaw(this, &FMenuPathHelper::BuildMenuBar, Node));
	}

	return Extender;
}


TSharedPtr<FExtender> FMenuPathHelper::GetMenuExtender(FName InHookName, EExtensionHook::Position InPosition)
{
	TSharedPtr<FExtender> Extender = MakeShared<FExtender>();
	
	Extender->AddMenuExtension(
		InHookName,
		InPosition,
		nullptr,
		FMenuExtensionDelegate::CreateRaw(this, &FMenuPathHelper::ExtendRootMenu, &MenuNodes));

	return Extender;
}

TSharedPtr<FExtender> FMenuPathHelper::GetToolbarExtender(FName InHookName, EExtensionHook::Position InPosition)
{
	TSharedPtr<FExtender> Extender = MakeShared<FExtender>();

	Extender->AddToolBarExtension(
		InHookName,
		InPosition,
		nullptr,
		FToolBarExtensionDelegate::CreateRaw(this, &FMenuPathHelper::BuildToolBar));
	
	return Extender;
}

void FMenuPathHelper::Reset(bool ResetFunctionInfos)
{
	MenuNodes.Reset();
	if (ResetFunctionInfos)
		FunctionInfos.Reset();	
}

void FMenuPathHelper::BuildToolBar(FToolBarBuilder& InBuilder)
{
	for (TSharedPtr<FMenuNode>& Node : MenuNodes)
	{
		if(Node->MenuType == EMenuType::Normal)
		{
			if (Node->BoundFunction)
			{
				FMenuFunctionInfo& FuncInfo = FunctionInfos[Node->BoundFunction];
				InBuilder.AddToolBarButton(
										FUIAction(FExecuteAction::CreateLambda([this, &Node]()
										{
											OnEntryCallBegin();
											FFrame Stack(nullptr, Node->BoundFunction, nullptr);
											Node->BoundFunction->Invoke(nullptr, Stack, nullptr);
											OnEntryCallEnd();
										})),
										NAME_None,
										FText::FromString(Node->MenuName),
										FText::FromString(FuncInfo.ToolTip),
										FSlateIcon(*Node->StyleSet, *Node->StyleName));	
				
			}
			else
			{
				
				
				InBuilder.AddComboButton(
					FUIAction(),
					FOnGetContent::CreateLambda([this, &Node]()
					{
						FMenuBuilder MenuBuilder(true, nullptr);
						ExtendRootMenu(MenuBuilder, &Node->ChildNodes);
						return MenuBuilder.MakeWidget();
					}),
					FText::FromString(Node->MenuName),
					FText::GetEmpty(),
					FSlateIcon(*Node->StyleSet, *Node->StyleName));
				
			}
		}
		else if(Node->MenuType == EMenuType::SingleEnumPopup)
		{
			InBuilder.AddComboButton(
						FUIAction(),
						FOnGetContent::CreateLambda([this, &Node]()
						{
							if (UEnum* EnumClass = FindObject<UEnum>(ANY_PACKAGE,*Node->TargetEnum, true))
							{
								if(Node->PopupMenu == nullptr)
								{
									Node->PopupMenu = MakeShareable
									(
										new FEMEnumSingleSelectPopupMenu
										(
											EnumClass,
											FText::FromString(Node->MenuName),
											Node
										)
									);
								}
								
								return Node->PopupMenu->FillMenu();
							}
							return SNullWidget::NullWidget; 
						}),
						FText::FromString(Node->MenuName),
						FText::GetEmpty(),
						FSlateIcon(*Node->StyleSet, *Node->StyleName));
		}
		else if(Node->MenuType == EMenuType::MultiEnumPopup)
		{
			InBuilder.AddComboButton(
						FUIAction(),
						FOnGetContent::CreateLambda([this, &Node]()
						{
							if (UEnum* EnumClass = FindObject<UEnum>(ANY_PACKAGE, *Node->TargetEnum, true))
							{
								if(Node->PopupMenu == nullptr)
								{
									Node->PopupMenu = MakeShareable
									(
										new FEMEnumMultiSelectPopupMenu
										(
											EnumClass,
											FText::FromString(Node->MenuName),
											Node
										)
									);
								}
								
								return Node->PopupMenu->FillMenu();
							}
							return SNullWidget::NullWidget; 
						}),
						FText::FromString(Node->MenuName),
						FText::GetEmpty(),
						FSlateIcon(*Node->StyleSet, *Node->StyleName));
		}
	}
}


void FMenuPathHelper::ExtendRootMenu(FMenuBuilder& InBuilder, TArray<TSharedPtr<FMenuNode>>* InEntryNodes)
{
	if (!InEntryNodes->Num()) return;

	FString Section = (*InEntryNodes)[0]->SectionName;
	if (!Section.IsEmpty())
	{
		InBuilder.BeginSection(FName(*Section), FText::FromString(Section));
	}

	for (auto& ChildMenu : *InEntryNodes)
	{
		// change section 
		if (ChildMenu->SectionName != Section)
		{
			if (!Section.IsEmpty())
			{
				InBuilder.EndSection();
			}                			
			Section = ChildMenu->SectionName;
			if (!Section.IsEmpty())
			{
				InBuilder.BeginSection(FName(*Section), FText::FromString(Section));
			}
		}

		BuildMenu(InBuilder, ChildMenu);
	}
}


//根据MenuNodes构建菜单
void FMenuPathHelper::BuildMenuBar(FMenuBarBuilder& MenuBarBuilder, TSharedPtr<FMenuNode> InNode)
{
	//创建菜单栏主按钮
	if(InNode->BoundFunction)
	{
		AddMenuEntry(MenuBarBuilder, InNode);
	}
	else
	{
		auto Hanlde = FNewMenuDelegate::CreateRaw(this, &FMenuPathHelper::CreateSection, InNode);
		MenuBarBuilder.AddPullDownMenu(
			FText::FromString(InNode->MenuName),
			FText::GetEmpty(), Hanlde);			
	}
}

void FMenuPathHelper::BuildMenu(FMenuBuilder& InBuilder, const TSharedPtr<FMenuNode> InNode)
{
	if (InNode->BoundFunction == nullptr)
	{
		auto Hanlde = FNewMenuDelegate::CreateRaw(this, &FMenuPathHelper::CreateSection, InNode);
		InBuilder.AddSubMenu(
			FText::FromString(InNode->MenuName),
			FText::GetEmpty(),Hanlde,false, FSlateIcon(*InNode->StyleSet, *InNode->StyleName));
	}
	else
	{
		AddMenuEntry(InBuilder, InNode);
	}
}


void FMenuPathHelper::CreateSection(FMenuBuilder& InBuilder, TSharedPtr<FMenuNode> InNode)
{
	if (!InNode->ChildNodes.Num()) return;

	FString Section = InNode->ChildNodes[0]->SectionName;
	if (!Section.IsEmpty())
	{
		InBuilder.BeginSection(FName(*Section), FText::FromString(Section));
	}

	for (TSharedPtr<FMenuNode>  Child: InNode->ChildNodes)
	{
		if (Child->SectionName != Section)
		{
			if (!Section.IsEmpty())
			{
				InBuilder.EndSection();
			}                			
			Section = Child->SectionName;
			if (!Section.IsEmpty())
			{
				InBuilder.BeginSection(FName(*Section), FText::FromString(Section));
			}
		}

		BuildMenu(InBuilder, Child);
	}
}

void FMenuPathHelper::AddMenuEntry(FBaseMenuBuilder& InBuilder, const TSharedPtr<FMenuNode> InNode)
{
	FMenuFunctionInfo& FuncInfo = FunctionInfos[InNode->BoundFunction];
	InBuilder.AddMenuEntry(
			FText::FromString(InNode->MenuName),
			FText::FromString(FuncInfo.ToolTip),
			FSlateIcon(*InNode->StyleSet, *InNode->StyleName),
			FUIAction(FExecuteAction::CreateLambda([this, InNode]
			{
				OnEntryCallBegin();
				FFrame Stack(nullptr, InNode->BoundFunction, nullptr);
				InNode->BoundFunction->Invoke(nullptr, Stack, nullptr);
				OnEntryCallEnd();
			})));
}



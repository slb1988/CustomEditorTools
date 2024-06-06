import unreal

def listAssetPaths():
    #print paths of all assets under project root directory

    EAL = unreal.EditorAssetLibrary

    assetPaths = EAL.list_assets('/Game')

    for assetPath in assetPaths:
        print(assetPath)

def getSelectionContentBrowser():
    EUL = unreal.EditorUtilityLibrary
    selectedAssets = EUL.get_selected_assets()

    for selectedAsset in selectedAssets:
        print(selectedAsset)

def getAllActors():
    EAS = unreal.EditorActorSubsystem()
    actors = EAS.get_all_level_actors()
    for actor in actors:
        print(actor)

def getSelectedActors():
    EAS = unreal.EditorActorSubsystem
    selectedActors = EAS.get_selected_level_actors()
    for selectedActor in selectedActors:
        print(selectedActor)

# 你的其他 Python 脚本内容
print("Script executed successfully.")

listAssetPaths()
getSelectionContentBrowser()
getAllActors()
getSelectedActors()
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


# 你的其他 Python 脚本内容
print("Script executed successfully.")

listAssetPaths()
getSelectionContentBrowser()

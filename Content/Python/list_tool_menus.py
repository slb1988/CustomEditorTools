import unreal

def list_menu(num=1000):
    menu_list = set()
    for i in range(num):
        obj = unreal.find_object(None, "/Engine/Transient.ToolMenus_0:RegisteredMenu_%s" % i)
        if not obj:
            obj = unreal.find_object(None,
                                     f"/Engine/Transient.ToolMenus_0:ToolMenu_{i}") # for backward compatibility
            if not obj:
                continue

        menu_name = str(obj.menu_name)
        if menu_name == "None":
            continue

        menu_list.add(menu_name)

    return list(menu_list)

for item in list_menu():
    print(item)
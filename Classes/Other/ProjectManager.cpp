#include "ProjectManager.h"
#include "Util/Toolbox.h"
#include <stdio.h>

USING_NS_CC;

// What?
std::vector<std::string> ProjectManager::GetAllFoldersInDir(std::string dir)
{
    WIN32_FIND_DATAA data;
    HANDLE hFind = FindFirstFileA(std::string(dir + "\\*").c_str(), &data);

    std::vector<std::string> ret;

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if(std::string(data.cFileName).find(".") == std::string::npos)
                ret.push_back(std::string(data.cFileName));
        } while (FindNextFileA(hFind, &data));
        FindClose(hFind);
    }

    return ret;
}

static ProjectManager* s_sharedProjectManager = nullptr;
ProjectManager* ProjectManager::sharedManager()
{
    if (s_sharedProjectManager == nullptr)
    {
        s_sharedProjectManager = new (std::nothrow) ProjectManager();
        
        // TODO: add option to change this
        s_sharedProjectManager->setSearchDirectory("D:\\Documents\\Programming\\Mods");
    }

	return s_sharedProjectManager;
}

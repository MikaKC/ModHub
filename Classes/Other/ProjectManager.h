#pragma once

#include <cocos2d.h>
#include <string>
#include <Windows.h>

class ProjectManager : public cocos2d::CCNode
{
CC_SYNTHESIZE(std::string, pSearchDir, SearchDirectory)
public:
	std::vector<std::string> GetAllFoldersInDir(std::string dir);
	static ProjectManager* sharedManager();
};
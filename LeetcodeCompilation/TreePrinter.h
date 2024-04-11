#pragma once

#include "TreeNode.h"

#include <cmath>
#include <sstream>
#include <utility>
#include <vector>
#include <string>


class TreePrinter 
{
public:
    static std::string drawTree(TreeNode* root);

private:
    static int getHeight(TreeNode* node);
    static void fillLevels(TreeNode* node, std::vector<std::vector<std::string>>& levels, int level, int left, int right);

    static std::stringstream ss;
};


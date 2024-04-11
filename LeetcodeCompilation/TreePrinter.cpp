#include "TreePrinter.h"


std::stringstream TreePrinter::ss;

std::string TreePrinter::drawTree(TreeNode* root)
{
    ss.clear();
    ss.str("");
    int height = getHeight(root);
    // Adjust the printWidth if necessary to make the tree look more balanced
    int printWidth = static_cast<int>(std::pow(2, height)) - 1;
    std::vector<std::vector<std::string>> levels(height, std::vector<std::string>(printWidth, " "));

    fillLevels(root, levels, 0, 0, printWidth - 1);
    for (const auto& row : levels) {
        for (const auto& val : row) ss << val;
        ss << std::endl;
    }
    std::string drawnTree = ss.str();

    return drawnTree;
}

int TreePrinter::getHeight(TreeNode* node)
{
    if (!node) return 0;
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

void TreePrinter::fillLevels(TreeNode* node, std::vector<std::vector<std::string>>& levels, int level, int left, int right)
{
    if (!node) return;
    int mid = left + (right - left) / 2;
    levels[level][mid] = std::to_string(node->val);

    fillLevels(node->left, levels, level + 1, left, mid - 1);
    fillLevels(node->right, levels, level + 1, mid + 1, right);
}

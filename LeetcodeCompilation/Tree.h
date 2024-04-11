#pragma once

#include "Solution.h"
#include "TreeNode.h"

#include <unordered_map>
#include <vector>


class Tree : public Solution
{
public:
    Tree() : Solution("Tree", "Common challenge problems involving binary trees and related algorithms.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<Tree>(*this); }
    
    static TreeNode* constructBinaryTreeBasic(const std::vector<int>& inorder);
    static void destroyBinaryTree(TreeNode* root);
    static std::vector<int> preorderTraversal(TreeNode* root);
    static std::vector<int> inorderTraversal(TreeNode* root);
    static std::vector<int> postorderTraversal(TreeNode* root);

    TreeNode* invertBinaryTree(TreeNode* root);
    int maxDepthBinaryTree(TreeNode* root);
    int diameterOfBinaryTree(TreeNode* root);
    bool isBalanced(TreeNode* root);
    bool isSameBinaryTree(TreeNode* p, TreeNode* q);
    bool isSubTreeOfAnotherTree(TreeNode* root, TreeNode* subRoot);
    TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q);
    std::vector<std::vector<int>> levelOrderTraversal(TreeNode* root);
    std::vector<int> rightSideView(TreeNode* root);
    int countGoodNodes(TreeNode* root);
    bool isValidBST(TreeNode* root);
    int kthSmallestInBST(TreeNode* root, int k);
    static TreeNode* constructBinaryTree(std::vector<int> preorder, std::vector<int> inorder);
    int maximumPathSum(TreeNode* root);
    
    // Symmetric Tree
    // Construct Binary Tree Inorder Postorder
    // Populating Next Right Pointers in Each Node 2
    // Flatten Binary Tree to Linked List
    // Path Sum
    // Sum Root To Leaf Numbers
    // BST Iterator
    // Count Complete Tree Nodes
    // Average Levels in Binary Tree
    // Zigzag Level order Traversal
    // Minimum Absolute Difference in BST
    // Construct Quad Tree
    // Leaf-Similar Trees
    // Path Sum 3
    // Longest Zigzag Path
    // Maximum Level Sum
    // Delete Node BST

    class CodecRecursive
    {
    public:
        std::string serialize(TreeNode* root);
        TreeNode* deserialize(const std::string& data);

    private:
        TreeNode* preorderDeserialize(TreeNode*& root, const std::vector<std::string>& vals, int& index);
    };

    class CodecBFS
    {
    public:
        std::string serialize(TreeNode* root);
        TreeNode* deserialize(const std::string& data);
    };

private:
    static TreeNode* constructBinaryTreeBasicRecursive(const std::vector<int>& preorder, int left, int right);
    static TreeNode* constructBinaryTreeRecursive(std::vector<int>::iterator preBegin, std::vector<int>::iterator preEnd,
        std::unordered_map<int, int> inMap, int inStart, int inEnd);
    static void preorderTraversalRecursive(TreeNode* root, std::vector<int>& pre);
    static void inorderTraversalRecursive(TreeNode* root, std::vector<int>& in);
    static void postorderTraversalRecursive(TreeNode* root, std::vector<int>& post);

    int diameterOfBinaryTreeRecursive(TreeNode* root, int& diameter);
    int checkBalanced(TreeNode* node);
    int goodPreorder(TreeNode* node, int maxValue);
    bool inorderValidateBST(TreeNode* node, TreeNode* prev);
    void inorderKthSmallest(TreeNode* node, int k, int& count, int& kthsmallest);
    int postOrderMaximumPathDown(TreeNode* node, int& maxSum);
};
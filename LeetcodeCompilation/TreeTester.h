#pragma once

#include "Tree.h"
#include "Tester.h"


class TreeTester : public Tester
{
public:
    TreeTester() : Tester { "Binary Tree" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<TreeTester>(*this); }

private:
    bool testInvertBinaryTree(TreeNode* root, TreeNode* expected);
    bool testMaximumDepthBinaryTree(TreeNode* root, int expected);
    bool testDiameterOfBinaryTree(TreeNode* root, int expected);
    bool testIsBalanced(TreeNode* root, bool expected);
    bool testIsSameBinaryTree(TreeNode* p, TreeNode* q, bool expected);
    bool testIsSubTreeOfAnotherTree(TreeNode* root, TreeNode* subRoot, bool expected);
    bool testLowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q, int expected);
    bool testLevelOrderTraversal(TreeNode* root, std::vector<std::vector<int>> expected);
    bool testRightSideView(TreeNode* root, std::vector<int> expected);
    bool testCountGoodNodes(TreeNode* root, int expected);
    bool testValidateBST(TreeNode* root, bool expected);
    bool testKthSmallestBST(TreeNode* root, int k, int expected);
    bool testMaximumPathSum(TreeNode* root, int expected);
    bool testSerializeRecursive(TreeNode* root);
    bool testSerializeBFS(TreeNode* root);

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

    Tree t;
};
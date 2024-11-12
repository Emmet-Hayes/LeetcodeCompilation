#include "TreeTester.h"
#include "TreePrinter.h"


bool TreeTester::testAllProblems()
{
    TreeNode* tree1 = Tree::constructBinaryTreeBasic({ 1, 2, 3, 4, 6, 7, 9});
    TreeNode* invertTree1 = Tree::constructBinaryTreeBasic({ 9, 7, 6, 4, 3, 2, 1 });
    addTestCase(testInvertBinaryTree(tree1, invertTree1));
    Tree::destroyBinaryTree(tree1);
    Tree::destroyBinaryTree(invertTree1);
    
    TreeNode* tree2 = Tree::constructBinaryTreeBasic({ 2, 1, 3 });
    TreeNode* invertTree2 = Tree::constructBinaryTreeBasic({ 3, 1, 2 });
    addTestCase(testInvertBinaryTree(tree2, invertTree2));
    Tree::destroyBinaryTree(tree2);
    Tree::destroyBinaryTree(invertTree2);
    
    TreeNode* tree3 = Tree::constructBinaryTreeBasic({ 9, 3, 20, 15, 7 });
    addTestCase(testMaximumDepthBinaryTree(tree3, 3));
    Tree::destroyBinaryTree(tree3);

    TreeNode* tree4 = Tree::constructBinaryTreeBasic({ 1, 2 });
    addTestCase(testMaximumDepthBinaryTree(tree4, 2));
    Tree::destroyBinaryTree(tree4);

    TreeNode* tree5 = Tree::constructBinaryTreeBasic({ 4, 2, 5, 1, 3 });
    addTestCase(testDiameterOfBinaryTree(tree5, 4));
    Tree::destroyBinaryTree(tree5);

    TreeNode* tree6 = Tree::constructBinaryTreeBasic({ 1, 2 });
    addTestCase(testDiameterOfBinaryTree(tree6, 1));
    Tree::destroyBinaryTree(tree6);

    TreeNode* tree7 = Tree::constructBinaryTreeBasic({ 9, 3, 15, 20, 7 });
    addTestCase(testIsBalanced(tree7, true));
    Tree::destroyBinaryTree(tree7);

    // hard-coded unbalanced tree since basic tree constructor is always balanced
    TreeNode* tree8 = Tree::constructBinaryTree({ 6, 4, 2, 1, 3, 5, 7 }, { 1, 2, 3, 4, 5, 6, 7 });
    addTestCase(testIsBalanced(tree8, false));
    Tree::destroyBinaryTree(tree8);

    TreeNode* tree9 = Tree::constructBinaryTreeBasic({ 1, 2, 3 });
    TreeNode* tree10 = Tree::constructBinaryTreeBasic({ 1, 2, 3 });
    addTestCase(testIsSameBinaryTree(tree9, tree10, true));
    Tree::destroyBinaryTree(tree9);
    Tree::destroyBinaryTree(tree10);

    TreeNode* tree11 = Tree::constructBinaryTreeBasic({ 1, 2 });
    TreeNode* tree12 = Tree::constructBinaryTreeBasic({ 1, 0, 2 });
    addTestCase(testIsSameBinaryTree(tree11, tree12, false));
    Tree::destroyBinaryTree(tree11);
    Tree::destroyBinaryTree(tree12);

    TreeNode* tree13 = Tree::constructBinaryTreeBasic({ 1, 4, 2, 3, 5, 6, 7 });
    TreeNode* tree14 = Tree::constructBinaryTreeBasic({ 1, 4, 2 });
    addTestCase(testIsSubTreeOfAnotherTree(tree13, tree14, true));
    Tree::destroyBinaryTree(tree13);
    Tree::destroyBinaryTree(tree14);

    TreeNode* tree15 = Tree::constructBinaryTreeBasic({ 1, 4, 2, 3, 5 });
    TreeNode* tree16 = Tree::constructBinaryTreeBasic({ 1, 4, 2 });
    addTestCase(testIsSubTreeOfAnotherTree(tree15, tree16, false));
    Tree::destroyBinaryTree(tree15);
    Tree::destroyBinaryTree(tree16);

    TreeNode* tree17 = Tree::constructBinaryTreeBasic({ 0, 2, 3, 4, 5, 6, 7, 8, 9 });
    TreeNode* p = tree17->left->left;
    TreeNode* q = tree17->left->right;
    addTestCase(testLowestCommonAncestorBST(tree17, p, q, 2));
    Tree::destroyBinaryTree(tree17);

    TreeNode* tree18 = Tree::constructBinaryTreeBasic({ 0, 2, 3, 4, 5, 6, 7, 8, 9 });
    TreeNode* p2 = tree18->left->right;
    TreeNode* q2 = tree18->right;
    addTestCase(testLowestCommonAncestorBST(tree18, p2, q2, 5));
    Tree::destroyBinaryTree(tree18);

    TreeNode* tree19 = Tree::constructBinaryTreeBasic({ 1, 2, 3, 4, 5, 6, 7 });
    addTestCase(testLevelOrderTraversal(tree19, { { 4 }, { 2, 6 }, { 1, 3, 5, 7 } }));
    Tree::destroyBinaryTree(tree19);

    TreeNode* tree20 = Tree::constructBinaryTreeBasic({ 1 });
    addTestCase(testLevelOrderTraversal(tree20, { { 1 } }));
    Tree::destroyBinaryTree(tree20);

    TreeNode* tree21 = Tree::constructBinaryTreeBasic({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    addTestCase(testRightSideView(tree21, { 5, 7, 8, 9 }));
    Tree::destroyBinaryTree(tree21);

    TreeNode* tree22 = Tree::constructBinaryTreeBasic({ 1, 3 });
    addTestCase(testRightSideView(tree22, { 1, 3 }));
    Tree::destroyBinaryTree(tree22);

    TreeNode* tree23 = Tree::constructBinaryTreeBasic({ 3, 1, 3, 1, 4, 5 });
    addTestCase(testCountGoodNodes(tree23, 4));
    Tree::destroyBinaryTree(tree23);

    TreeNode* tree24 = Tree::constructBinaryTreeBasic({ 3, 3, 4, 2 });
    addTestCase(testCountGoodNodes(tree24, 3));
    Tree::destroyBinaryTree(tree24);

    TreeNode* tree25 = Tree::constructBinaryTreeBasic({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    addTestCase(testValidateBST(tree25, true));
    Tree::destroyBinaryTree(tree25);

    TreeNode* tree26 = Tree::constructBinaryTreeBasic({ 1, 2, 3, 7, 5, 4, 6, 8, 9 });
    addTestCase(testValidateBST(tree26, false));
    Tree::destroyBinaryTree(tree26);

    TreeNode* tree27 = Tree::constructBinaryTreeBasic({ 1, 3, 6, 20, 62, 153, 627 });
    addTestCase(testKthSmallestBST(tree27, 3, 6));
    Tree::destroyBinaryTree(tree27);

    TreeNode* tree28 = Tree::constructBinaryTreeBasic({ 1, 2, 3, 4, 5, 6 });
    addTestCase(testKthSmallestBST(tree28, 2, 2));
    Tree::destroyBinaryTree(tree28);

    // test the more complex tree construction 
    TreeNode* tree33 = Tree::constructBinaryTree({ 3, 9, 20, 15, 7 }, { 9, 3, 15, 20, 7 });
    Tree::destroyBinaryTree(tree33);

    TreeNode* tree29 = Tree::constructBinaryTreeBasic({ 1, 2, 3 });
    addTestCase(testMaximumPathSum(tree29, 6));
    Tree::destroyBinaryTree(tree29);

    TreeNode* tree30 = Tree::constructBinaryTreeBasic({ 10, -3, 52, 15, 31 });
    addTestCase(testMaximumPathSum(tree30, 108));
    Tree::destroyBinaryTree(tree30);

    TreeNode* tree31 = Tree::constructBinaryTreeBasic({ 1, 3, 5, 7, 9, 11, 13 });
    addTestCase(testSerializeRecursive(tree31));
    Tree::destroyBinaryTree(tree31);

    TreeNode* tree32 = Tree::constructBinaryTreeBasic({ 1, 3, 5, 7, 9, 11, 13 });
    addTestCase(testSerializeBFS(tree32));
    Tree::destroyBinaryTree(tree32);

    return runAllTests();
}

bool TreeTester::testInvertBinaryTree(TreeNode* root, TreeNode* expected)
{
    if (getVerbose())
        ss << "\nInvert Binary Tree Test Run on Given Tree:\n" << TreePrinter::drawTree(root);
    TreeNode* actual = t.invertBinaryTree(root);
    std::vector<int> preactual = Tree::preorderTraversal(actual);
    std::vector<int> preexpected = Tree::preorderTraversal(expected);
    std::vector<int> inactual = Tree::inorderTraversal(actual);
    std::vector<int> inexpected = Tree::inorderTraversal(expected);
    if (getVerbose())
        ss << "\nResult:\n"   << TreePrinter::drawTree(root)
           << "\nExpected:\n" << TreePrinter::drawTree(root);
    if (preactual.size() != preexpected.size())
        return false;
    for (unsigned i = 0; i < preexpected.size(); ++i)
        if (preactual[i] != preexpected[i])
            return false;

    if (inactual.size() != inexpected.size())
        return false;
    for (unsigned i = 0; i < inexpected.size(); ++i)
        if (inactual[i] != inexpected[i])
            return false;

    return true;
}

bool TreeTester::testMaximumDepthBinaryTree(TreeNode* root, int expected)
{
    if (getVerbose())
        ss << "\nMaximum Depth Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root);
    int actual = t.maxDepthBinaryTree(root);
    if (getVerbose())
        ss << "\nActual: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testDiameterOfBinaryTree(TreeNode* root, int expected)
{
    if (getVerbose())
        ss << "\nDiameter of Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root);
    int actual = t.diameterOfBinaryTree(root);
    if (getVerbose())
        ss << "\nActual: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testIsBalanced(TreeNode* root, bool expected)
{
    if (getVerbose())
        ss << "\nCheck Balanced Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root);
    bool actual = t.isBalanced(root);
    if (getVerbose())
        ss << "\nActual: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testIsSameBinaryTree(TreeNode* p, TreeNode* q, bool expected)
{
    if (getVerbose())
        ss << "\nCheck Is Same Binary Tree Test Run on Given Trees:\nTree1:\n"
            << TreePrinter::drawTree(p) << "\nTree2:\n" << TreePrinter::drawTree(q);
    bool actual = t.isSameBinaryTree(p, q);
    if (getVerbose())
        ss << "\nActual: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testIsSubTreeOfAnotherTree(TreeNode* root, TreeNode* subRoot, bool expected)
{
    if (getVerbose())
        ss << "\nCheck Is Subtree of Another Binary Tree Test Run on Given Trees:\nTree1:\n"
            << TreePrinter::drawTree(root) << "\nTree2:\n" << TreePrinter::drawTree(subRoot);
    bool actual = t.isSubTreeOfAnotherTree(root, subRoot);
    if (getVerbose())
        ss << "\nActual: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testLowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q, int expected)
{
    if (getVerbose())
        ss << "\nLowest Common Ancestor Binary Tree Test Run on Given Tree Traversals:\n"
           << TreePrinter::drawTree(root) << "\np: " << p->val << ", q: " << q->val;
    int actual = t.lowestCommonAncestorBST(root, p, q)->val;
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testLevelOrderTraversal(TreeNode* root, std::vector<std::vector<int>> expected)
{
    if (getVerbose())
        ss << "\nLevel Order Traversal Binary Tree Test Run on Given Tree Traversals:\n"
           << TreePrinter::drawTree(root);
    std::vector<std::vector<int>> actual = t.levelOrderTraversal(root);
    if (getVerbose())
    {
        ss << "\nResult:\n";
        for (unsigned i = 0; i < actual.size(); ++i)
        {
            ss << "[ ";
            for (int val : actual[i])
                ss << val << " ";
            ss << "] ";
            if (i + 1 < actual.size())
                ss << "\n";
        }
        ss << "\nExpected:\n";
        for (unsigned i = 0; i < expected.size(); ++i)
        {
            ss << "[ ";
            for (int val : expected[i])
                ss << val << " ";
            ss << "]";
            if (i + 1 < expected.size())
                ss << "\n";
        }
        ss << "\n";
    }
    if (actual.size() != expected.size()) return false;
    for (unsigned i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size()) return false;
        for (unsigned j = 0; j < expected[i].size(); ++j)
            if (actual[i][j] != expected[i][j])
                return false;
    }

    return true;
}

bool TreeTester::testRightSideView(TreeNode* root, std::vector<int> expected)
{
    if (getVerbose())
        ss << "\nRight Side View Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root);
    std::vector<int> actual = t.rightSideView(root);
    if (getVerbose())
    {
        ss << "\nResult:   [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "]\nExpected: [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (unsigned i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool TreeTester::testCountGoodNodes(TreeNode* root, int expected)
{
    if (getVerbose())
        ss << "\nCount Good Nodes Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root);
    int actual = t.countGoodNodes(root);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testValidateBST(TreeNode* root, bool expected)
{
    if (getVerbose())
        ss << "\nValidate Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root);
    bool actual = t.isValidBST(root);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testKthSmallestBST(TreeNode* root, int k, int expected)
{
    if (getVerbose())
        ss << "\nKth Smallest Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root) << "\nk: " << k;
    int actual = t.kthSmallestInBST(root, k);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testMaximumPathSum(TreeNode* root, int expected)
{
    if (getVerbose())
        ss << "\nMaximum Path Sum Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root);
    int actual = t.maximumPathSum(root);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TreeTester::testSerializeRecursive(TreeNode* root)
{
    if (getVerbose())
        ss << "\nSerialize (Recursive) Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root) << "\n";
    Tree::CodecRecursive codec;
    std::string data = codec.serialize(root);
    TreeNode* actual = codec.deserialize(data);
    return t.isSameBinaryTree(root, actual);
}

bool TreeTester::testSerializeBFS(TreeNode* root)
{
    if (getVerbose())
        ss << "\nSerialize (BFS) Binary Tree Test Run on Given Tree:\n"
           << TreePrinter::drawTree(root) << "\n";
    Tree::CodecBFS codec;
    std::string data = codec.serialize(root);
    TreeNode* actual = codec.deserialize(data);
    return t.isSameBinaryTree(root, actual);
}

#include "Tree.h"

#include <algorithm>
#include <climits>
#include <queue>
#include <sstream>

/**
* 
* Complexity:
* Time: O(n)
* Space: O(n)
*/
TreeNode* Tree::constructBinaryTreeBasic(const std::vector<int>& inorder)
{
    int index = 0;
    return constructBinaryTreeBasicRecursive(inorder, 0, static_cast<int>(inorder.size()) - 1);
}

TreeNode* Tree::constructBinaryTreeBasicRecursive(const std::vector<int>& inorder, int left, int right)
{
    if (left > right) return nullptr;

    // Choose the middle element as the root to ensure the tree is balanced
    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(inorder[mid]);

    // Build the left and right subtrees recursively
    node->left = constructBinaryTreeBasicRecursive(inorder, left, mid - 1);
    node->right = constructBinaryTreeBasicRecursive(inorder, mid + 1, right);

    return node;
}

/**
*
* Complexity:
* Time: O(n)
* Space: O(h)
*/
void Tree::destroyBinaryTree(TreeNode* root)
{
    if (!root) return;

    // delete any children that may exist first (postorder)
    destroyBinaryTree(root->left);
    destroyBinaryTree(root->right);

    delete root;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
std::vector<int> Tree::preorderTraversal(TreeNode* root)
{
    std::vector<int> pre;
    preorderTraversalRecursive(root, pre);
    return pre;
}

void Tree::preorderTraversalRecursive(TreeNode* root, std::vector<int>& pre)
{
    if (!root) return;
    pre.push_back(root->val);
    if (root->left)
        preorderTraversalRecursive(root->left, pre);
    if (root->right)
        preorderTraversalRecursive(root->right, pre);
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
std::vector<int> Tree::inorderTraversal(TreeNode* root)
{
    std::vector<int> in;
    inorderTraversalRecursive(root, in);
    return in;
}

void Tree::inorderTraversalRecursive(TreeNode* root, std::vector<int>& in)
{
    if (!root) return;
    if (root->left)
        inorderTraversalRecursive(root->left, in);
    in.push_back(root->val);
    if (root->right)
        inorderTraversalRecursive(root->right, in);
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
std::vector<int> Tree::postorderTraversal(TreeNode* root)
{
    std::vector<int> post;
    postorderTraversalRecursive(root, post);
    return post;
}

void Tree::postorderTraversalRecursive(TreeNode* root, std::vector<int>& post)
{
    if (!root) return;
    if (root->left)
        inorderTraversalRecursive(root->left, post);
    if (root->right)
        inorderTraversalRecursive(root->right, post);
    post.push_back(root->val);

}


/** Invert Binary Tree (Google - Easy)
* Given the root of a binary tree, invert the tree, and return its root.
*
* Complexity:
* Time: O(n)
* Space: O(h)
*/
TreeNode* Tree::invertBinaryTree(TreeNode* root)
{
    if (!root) return nullptr;

    std::swap(root->left, root->right);
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);

    return root;
}


/** Maximum Depth of Binary Tree (Amazon - Easy)
* Given the root of a binary tree, return its maximum depth.
*
* A binary tree's maximum depth is the number of nodes along 
* the longest path from the root node down to the farthest leaf node.
*/
int Tree::maxDepthBinaryTree(TreeNode* root)
{
    if (!root) return 0;
    int leftDepth = maxDepthBinaryTree(root->left);
    int rightDepth = maxDepthBinaryTree(root->right);
    return std::max(leftDepth, rightDepth) + 1;
}


/** Diameter of Binary Tree (Easy)
* Given the root of a binary tree, return the length of the diameter of the tree.
*
* The diameter of a binary tree is the length of the longest path between 
* any two nodes in a tree. This path may or may not pass through the root.
*
* The length of a path between two nodes is represented by the number of edges 
* between them.
*/
int Tree::diameterOfBinaryTree(TreeNode* root)
{
    int diameter = 0;
    diameterOfBinaryTreeRecursive(root, diameter);
    return diameter;
}

int Tree::diameterOfBinaryTreeRecursive(TreeNode* root, int& diameter)
{
    if (!root) return 0;

    int lh = diameterOfBinaryTreeRecursive(root->left, diameter);
    int rh = diameterOfBinaryTreeRecursive(root->right, diameter);
    diameter = std::max(diameter, lh + rh);

    return std::max(lh, rh) + 1;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(h)
*/
bool Tree::isBalanced(TreeNode* root)
{
    return checkBalanced(root) != -1;
}

int Tree::checkBalanced(TreeNode* node)
{
    if (!node) return 0;

    int leftHeight = checkBalanced(node->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkBalanced(node->right);
    if (rightHeight == -1) return -1;

    if (std::abs(leftHeight - rightHeight) > 1) return -1;

    return std::max(leftHeight, rightHeight) + 1;
}


/**
* 
* Complexity:
* Time: O(n)
* Space: O(h)
*/
bool Tree::isSameBinaryTree(TreeNode* p, TreeNode* q)
{
    if (!p && !q) return true;
    if (!p || !q || p->val != q->val) return false;

    return isSameBinaryTree(p->left, q->left) &&
           isSameBinaryTree(p->right, q->right);
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(h)
*/
bool Tree::isSubTreeOfAnotherTree(TreeNode* root, TreeNode* subRoot)
{
    if (!root && !subRoot) return true;

    if (root && subRoot)
    {
        if (isSameBinaryTree(root, subRoot)) return true;
        if (isSubTreeOfAnotherTree(root->left, subRoot)) return true;
        if (isSubTreeOfAnotherTree(root->right, subRoot)) return true;
    }
    return false;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(h)
*/
TreeNode* Tree::lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode* curr = root;

    while (curr)
    {
        if (p->val > curr->val && q->val > curr->val)
            curr = curr->right;
        else if (p->val < curr->val && q->val < curr->val)
            curr = curr->left;
        else
            return curr;
    }

    return nullptr;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
std::vector<std::vector<int>> Tree::levelOrderTraversal(TreeNode* root)
{
    std::vector<std::vector<int>> result;
    if (!root) return result;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        std::vector<int> currentLevel;
        int levelSize = static_cast<int>(q.size()); // copy the size since we use the same queue to push for the next layer.

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(currentLevel);
    }

    return result;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(w)
*/
std::vector<int> Tree::rightSideView(TreeNode* root)
{
    std::vector<int> arr;
    if (!root) return arr;

    std::queue<TreeNode*> q;
    q.push(root);

    int level = 0;
    while (!q.empty())
    {
        int qsize = static_cast<int>(q.size());
        for (int i = 0; i < qsize; ++i)
        {
            TreeNode* v = q.front();
            q.pop();
            // if the queue is empty after pop, this is rightmost
            if (i == qsize - 1)
                arr.push_back(v->val);

            // left and right edges
            if (v->left)
                q.push(v->left);
            if (v->right)
                q.push(v->right);
        }
        level++;
    }
    return arr;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(h)
*/
int Tree::countGoodNodes(TreeNode* root)
{
    if (!root) return 0;
    return goodPreorder(root, root->val);
}


int Tree::goodPreorder(TreeNode* node, int maxValue)
{
    if (!node) return 0;
    int goodcount = 0;
    if (node->val >= maxValue)
    {
        goodcount = 1;
        maxValue = node->val;
    }

    goodcount += goodPreorder(node->left, maxValue);
    goodcount += goodPreorder(node->right, maxValue);
    return goodcount;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(h)
*/
bool Tree::isValidBST(TreeNode* root)
{
    TreeNode* prev = nullptr;
    return inorderValidateBST(root, prev);
}


bool Tree::inorderValidateBST(TreeNode* node, TreeNode* prev)
{
    if (!node) return true;

    if (!inorderValidateBST(node->left, prev)) return false;
    if (prev && node->val <= prev->val) return false;
    prev = node; // use prev from inorder to ensure BST is valid
    return inorderValidateBST(node->right, prev);
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(h)
*/
int Tree::kthSmallestInBST(TreeNode* root, int k)
{
    int count = 0;
    int kthsmallest = INT_MIN;
    inorderKthSmallest(root, k, count, kthsmallest);
    return kthsmallest;
}


void Tree::inorderKthSmallest(TreeNode* node, int k, int& count, int& kthsmallest)
{
    if (!node || count >= k) return;

    if (node->left)
        inorderKthSmallest(node->left, k, count, kthsmallest);

    if (++count == k)
    {
        kthsmallest = node->val;
        return;
    }

    if (node->right)
        inorderKthSmallest(node->right, k, count, kthsmallest);
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(h)
*/
int Tree::maximumPathSum(TreeNode* root)
{
    int maxSum = INT_MIN;
    postOrderMaximumPathDown(root, maxSum);
    return maxSum;
}


int Tree::postOrderMaximumPathDown(TreeNode* node, int& maxSum)
{
    if (!node) return 0;

    int left = std::max(0, postOrderMaximumPathDown(node->left, maxSum));
    int right = std::max(0, postOrderMaximumPathDown(node->right, maxSum));

    maxSum = std::max(maxSum, left + right + node->val);

    return std::max(left, right) + node->val;
}


/** Construct Binary Tree from Preorder and Inorder Traversal (Amazon - Medium)
* Given two integer arrays preorder and inorder where preorder is the
* preorder traversal of a binary tree and inorder is the inorder traversal
* of the same tree, construct and return the binary tree.
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
TreeNode* Tree::constructBinaryTree(std::vector<int> preorder, std::vector<int> inorder)
{
    std::unordered_map<int, int> indexMap;
    for (int i = 0; i < inorder.size(); ++i)
        indexMap[inorder[i]] = i;

    return constructBinaryTreeRecursive(preorder.begin(), preorder.end(), indexMap, 0, static_cast<int>(inorder.size()) - 1);
}

TreeNode* Tree::constructBinaryTreeRecursive(std::vector<int>::iterator preBegin, std::vector<int>::iterator preEnd,
    std::unordered_map<int, int> inMap, int inStart, int inEnd)
{
    if (preBegin == preEnd || inStart > inEnd) return nullptr;

    TreeNode* root = new TreeNode(*preBegin);
    int inRootIndex = inMap[*preBegin];
    int leftSize = inRootIndex - inStart;

    root->left = constructBinaryTreeRecursive(preBegin + 1, preBegin + 1 + leftSize, inMap, inStart, inRootIndex - 1);
    root->right = constructBinaryTreeRecursive(preBegin + 1 + leftSize, preEnd, inMap, inRootIndex + 1, inEnd);

    return root;
}


std::string Tree::CodecRecursive::serialize(TreeNode* root)
{
    // encode the data based on a preorder traversal
    if (!root) return "N";
    std::string stree_left = serialize(root->left);
    std::string stree_right = serialize(root->right);
    return std::to_string(root->val) + "," + stree_left + "," + stree_right;
}


TreeNode* Tree::CodecRecursive::deserialize(const std::string& data)
{
    // split the data by "," in C++, we can use getline for that
    std::vector<std::string> vals;
    std::istringstream iss(data);
    std::string s;
    while (std::getline(iss, s, ','))
        vals.push_back(s);
    TreeNode* root = nullptr;
    int index = 0;
    preorderDeserialize(root, vals, index);
    return root;
}


TreeNode* Tree::CodecRecursive::preorderDeserialize(TreeNode*& root, const std::vector<std::string>& vals, int& index)
{
    if (index >= vals.size())
        return nullptr;

    std::string snode = vals[index];

    TreeNode* node;
    if (snode.compare("N") == 0)
        node = nullptr;
    else
        node = new TreeNode(std::stoi(snode));
    if (index++ == 0) // keep track of the root for the final output
        root = node;

    if (node)
    {
        node->left = preorderDeserialize(root, vals, index);
        node->right = preorderDeserialize(root, vals, index);
    }
    return node;
}

std::string Tree::CodecBFS::serialize(TreeNode* root)
{
    if (!root) return "";

    std::string s;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* curNode = q.front();
        q.pop();
        if (!curNode)
            s.append("N,");
        else
            s.append(std::to_string(curNode->val) + ',');
        if (curNode)
        {
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return s;
}

TreeNode* Tree::CodecBFS::deserialize(const std::string& data)
{
    if (data.size() == 0)
        return nullptr;

    std::stringstream s(data);
    std::string str;
    std::getline(s, str, ',');

    TreeNode* root = new TreeNode(stoi(str));
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        std::getline(s, str, ',');
        if (str == "N")
            node->left = nullptr;
        else
        {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        std::getline(s, str, ',');
        if (str == "N")
            node->right = nullptr;
        else
        {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

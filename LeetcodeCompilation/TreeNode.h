#pragma once


struct TreeNode
{
    TreeNode(int _val = 0, TreeNode* _left = nullptr, TreeNode* _right = nullptr) 
    :   val   { _val }
    ,   left  { _left }
    ,   right { _right } 
    {}

    int val;
    TreeNode* left;
    TreeNode* right;
};
/*
 * 1372. Longest ZigZag Path in a Binary Tree
 *
 * Q: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
 * A: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/discuss/538986/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

//class Solution {
//public:
//    int longestZigZag(TreeNode* root, int max = 0) {
//        go(max, root);
//        return max;
//    }
//private:
//    int left = 0xABC, right = 0xDEF;
//    void go(int& max, TreeNode* root, int from = 0, int len = 0) {
//        max = std::max(max, len);
//        if (root->left) {
//            if (from == right)
//                go(max, root->left, left, 1 + len); // case 1: (from 👉) -> (to 👈)
//            else
//                go(max, root->left, left, 1);
//        }
//        if (root->right) {
//            if (from == left)
//                go(max, root->right, right, 1 + len); // case 2: (to 👉) <- (from 👈)
//            else
//                go(max, root->right, right, 1);
//        }
//    }
//};

class Solution {
public:
    int longestZigZag(TreeNode* root, int max = 0) {
        go(max, root);
        return max;
    }
private:
    int L = 0xABC, R = 0xDEF;
    void go(int& max, TreeNode* root, int from = 0, int len = 0) {
        if (!root) return;
        max = std::max(max, len);
        go(max, root->left,  L, 1 + (from == R ? len : 0)); // case 1: (from 👉) -> (to 👈)
        go(max, root->right, R, 1 + (from == L ? len : 0)); // case 2: (to 👉) <- (from 👈)
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*
 * 530. Minimum Absolute Difference in BST
 *
 * Q: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 * A: https://leetcode.com/problems/minimum-absolute-difference-in-bst/discuss/595803/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <deque>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using Deque = deque<int>;
    int getMinimumDifference(TreeNode* root, Deque A = {}, Deque D = {}) {
        go(root, A);
        adjacent_difference(A.begin(), A.end(), back_inserter(D)), D.pop_front();
        return *min_element(D.begin(), D.end());
    }
private:
    void go(TreeNode* root, Deque& A) {
        if (!root)
            return;
        go(root->left, A);
        A.push_back(root->val);
        go(root->right, A);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

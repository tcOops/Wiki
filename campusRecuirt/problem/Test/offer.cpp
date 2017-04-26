#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b < b + a;
}

class Solution {
public:
    bool isSymmetrical(TreeNode *pRoot) {
        if(pRoot == NULL) return true;
        return comRoot(pRoot->left, pRoot->right);
    }
    
    bool comRoot(TreeNode *left, TreeNode *right) {
        if(left == NULL) return right == NULL;
        if(right == NULL) return false;
        if(left.val != right.val) return false;
        return comRoot(left->right, right->left) && comRoot(left->left, right->right);
    }
};


int main() {
    vector<int> a;
    a.push_back(12);
    a.push_back(1234);
    //cout << Solution().PrintMinNumber(a);
    return 0;
}
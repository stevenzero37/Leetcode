#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int check (TreeNode* root) {
        if (!root)
            return 0;
        int left = check (root->left);
        int right = check (root->right);
        
        if (left == -1 || right == -1 || abs(left-right) > 1)
            return -1;

        return 1 + std::max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {      
        return (check(root) == -1) ? false:true;
    }
};

class Tree {
private:
    TreeNode* root;
public:
    Tree (int val) {root = new TreeNode (val);}
    ~Tree () {delete root;}
    
    TreeNode* buildTree (std::vector<int> &data) {
        int leftNode = 1, rightNode = 0, nodeAmount = data.size() -1;
        TreeNode* current;
        
        std::queue<TreeNode*> QueueList;
        QueueList.push(root);
        
        
        while (!QueueList.empty()) {
            current = QueueList.front();
            rightNode = leftNode;
            if(data[leftNode] != -1) {
                TreeNode* newNode = new TreeNode (data[leftNode]);
                current->left = newNode;
                QueueList.push(newNode);
            }
            
            rightNode = leftNode + 1;
            
            if (rightNode > nodeAmount)
                break;
            
            if(data[rightNode] != -1) {
                TreeNode* newNode = new TreeNode (data[rightNode]);
                current->right = newNode;
                QueueList.push(newNode);
            }
            
            leftNode+=2;
            QueueList.pop();
        }
        
        return root;
    }

};

int main() {
    std::vector<int> data1 {1,2,2,3,3,-1,-1,4,4};
    Tree* Tree1 = new Tree (data1[0]);
    Solution* example = new Solution ();
    
    TreeNode* temp1;

    temp1 = Tree1->buildTree (data1);
    
    std::cout << example->isBalanced(temp1);
    
    delete Tree1;
    delete example;
}

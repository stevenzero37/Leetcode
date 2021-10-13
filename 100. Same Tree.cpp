#include <iostream>
#include <vector>
#include <queue>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) 
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        else
            return (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
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
    std::vector<int> data1 {1,2,-1,4,5,6};
    std::vector<int> data2 {1,2,-1,4,5,6};
    Tree* Tree1 = new Tree (data1[0]);
    Tree* Tree2 = new Tree (data2[0]);
    Solution* example = new Solution ();
    
    TreeNode* temp1;
    TreeNode* temp2;
    
    temp1 = Tree1->buildTree (data1);
    temp2 = Tree2->buildTree (data2);
    
    std::cout << example->isSameTree (temp1, temp2);
    
    delete Tree1;
    delete Tree2;
}
#include <iostream>
#include <vector>
#include <queue>
#include <memory>

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
    TreeNode* searchBSTRecursion (TreeNode* root, int val) {
        if (root == nullptr)
            return root;
        
        if (root->val == val)
            return root;
        else if (root->val > val)
            root = searchBSTRecursion (root->left, val);
        else if (root->val < val)
            root = searchBSTRecursion (root->right, val);

        return root;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->val == val)
                return current;
            else if (current->val > val) {
                current = current->left; 
            }
            else if (current->val < val) {
                current = current->right;
            }
        }

        return current;
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
    std::vector<int> data1 {4,2,7,1,3};
    std::unique_ptr<Tree> Tree1 = std::make_unique<Tree> (data1[0]);
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();
    TreeNode* result;
    
    TreeNode* temp1;

    temp1 = Tree1->buildTree (data1);

    result = example->searchBSTRecursion (temp1, 3);
    
    if (result != nullptr)
        std::cout << result->val;
}
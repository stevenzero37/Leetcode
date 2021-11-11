#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <stack>

/*
A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

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
private:
    std::vector<int> temp;
public:
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        
        inorder(root->left);
        temp.push_back(root->val);
        inorder(root->right);
    }
    
    void inorderIterator(TreeNode* root) {
        if (root == nullptr)
            return;
        std::stack<TreeNode*> addList;
        TreeNode* current = root;
        
        while (current != nullptr || !addList.empty()) {
            while (current != nullptr) {
                addList.push(current);
                current = current->left;
            }
            
            current = addList.top();
            addList.pop();            
            temp.push_back(current->val);
            
            current = current->right;
        }
        
        for (int i=0;i<temp.size();++i)
            std::cout << temp[i] << std::endl;
    }

    bool isValidBSTRecurssion(TreeNode* root) {
        if (root == nullptr)
            return true;
            
        inorder(root);
        
        for (int i=1;i<temp.size();++i) {
            if (temp[i] <= temp[i-1])
                return false;
        }
        
        return true;
    }
    
    bool isValidBSTIteration(TreeNode* root) {
        if (root == nullptr)
            return true;
            
        TreeNode* prev = nullptr;
        TreeNode* current;
        std::stack<TreeNode*> stackList;
        current = root;

        while (current != nullptr || !stackList.empty()) {
            //push left node in the stack
            while (current != nullptr) {
                stackList.push(current);
                current = current->left;
            }
            current = stackList.top();
            stackList.pop();

            if (prev != nullptr && prev->val >= current->val)
                return false;
            
            prev = current;
            current = current->right;
        }

        return true;
    }
    
    bool isValidBSTIteration2(TreeNode* root) {
        
        inorderIterator(root);
        
        for (int i=1; i<temp.size();++i)
            if (temp[i] <= temp[i-1])
                return false;
        
        return true;
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
    std::vector<int> data1 {1,2,3,4,5,6,7};
    std::unique_ptr<Tree> Tree1 = std::make_unique<Tree> (data1[0]);
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();
    TreeNode* result;
    
    TreeNode* temp1;

    temp1 = Tree1->buildTree (data1);

    std::cout << example->isValidBSTIteration2 (temp1);
    
}
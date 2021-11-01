#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <stack>

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
    std::vector<int> res;
public:
    std::vector<int> inorderTraversalRecursion(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversalRecursion(root->left);
            res.push_back(root->val);
            inorderTraversalRecursion(root->right);
        }
        
        return res;
    }
    
    std::vector<int> inorderTraversalIterator(TreeNode* root) {
        std::stack<TreeNode*> nodeStack;
        TreeNode* currentNode;
        
        if (root != nullptr)
            currentNode = root;
        else
            return res;
        
        while (!nodeStack.empty() || currentNode != nullptr) {
            while(currentNode != nullptr) {
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            }
            
            currentNode = nodeStack.top();
            nodeStack.pop();
            res.push_back(currentNode->val);
            currentNode = currentNode->right;
        }

        return res;
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
    std::vector<int> data1 {1,-1,2,3};
    std::unique_ptr<Tree> Tree1 = std::make_unique<Tree> (data1[0]);
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();
    std::vector<int> result;
    std::vector<int>::iterator it;
    
    TreeNode* temp1;

    temp1 = Tree1->buildTree (data1);

    //result = example->inorderTraversalRecursion(temp1);
    result = example->inorderTraversalIterator(temp1);
    
    for (it=result.begin();it!=result.end();++it)
        std::cout<< *it << " ";
}
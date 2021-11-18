#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <memory>
#include <algorithm>

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> temp;
        std::vector<int> level;
        std::deque<TreeNode*> nodeQue;
        TreeNode* current;    
        int size = 0;
        
        if (root == nullptr)
            return temp;
        
        nodeQue.push_back(root);
        
        while (!nodeQue.empty()) {
            size = nodeQue.size();
            for (int i=0;i<size;++i) {
                current = nodeQue.front();
                if (current->left != nullptr)
                    nodeQue.push_back(current->left);
                if (current->right != nullptr)
                    nodeQue.push_back(current->right);
                level.push_back(current->val);
                nodeQue.pop_front();
            }
            
            temp.push_back(level);
            level.clear();
        }
        
        std::reverse(temp.begin(), temp.end());
        
        return temp;
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
    std::vector<int> data1 {3,9,20,8,6,15,7};
    std::unique_ptr<Tree> Tree1 = std::make_unique<Tree> (data1[0]);
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();
    std::vector<std::vector<int>> result;
    
    TreeNode* temp1;

    temp1 = Tree1->buildTree (data1);

    result = example->levelOrderBottom(temp1);
    
    for (int i=0;i<result.size();++i) {
        for (int j=0;j<result[i].size();++j)
            std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }
}
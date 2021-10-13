#include <iostream>
#include <vector>
/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        ListNode* temp;
        while (current != nullptr) {
            temp = current;

            while (temp->next != nullptr && temp->next->val == temp->val)
                temp = temp->next;

            current->next = temp->next;
            current = current->next;
        }
        
        return head;
    }
};

ListNode* create_list (std::vector<int> &data) {
    
    ListNode* firstNode = new ListNode (data[0]);
    ListNode* temp = firstNode;

    for (int i =1;i<data.size();++i) {
        ListNode* newNode = new ListNode (data[i]);
        
        firstNode->next = newNode;
        firstNode = newNode;
    }
    
    return temp;
}

int main() {
    std::vector<int> data = {1, 1, 1, 2, 3, 3};
    Solution* example = new Solution ();
    
    ListNode* temp = create_list(data);
    
    temp = example->deleteDuplicates(temp);
    
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}
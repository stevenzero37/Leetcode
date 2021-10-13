#include <iostream>
#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dumpNode = new ListNode();
        ListNode* temp = dumpNode;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else if (l1->val > l2->val) {
                temp->next = l2;
                l2 = l2->next;
            }

            temp = temp->next;
        }

        if (l1 == nullptr)
            temp->next = l2;
        else
            temp->next = l1;

        return dumpNode->next;
    }
};

ListNode* create_list(std::vector<int> data) {
    
    if (data.empty())
        return nullptr;
    
    ListNode* headNode = new ListNode (data[0]);
    ListNode* temp = headNode;
    
    for (int i=1; i<data.size();++i) {
        ListNode* newNode = new ListNode (data[i]);
        
        temp->next = newNode;
        temp = newNode;
    }
    
    return headNode;
}

int main() {
    std::vector<int> data1 = {1,2,3};
    std::vector<int> data2 = {1,2,3};
    
    Solution* example = new Solution();
    
    ListNode* List1 = create_list(data1);
    ListNode* List2 = create_list(data2);
    ListNode* answer = example->mergeTwoLists(List1, List2);
    
    std::cout<< "List1: ";
    
    while (List1 != nullptr) {
        std::cout<< List1->val<< " ";
        List1 = List1->next;
    }
    
    std::cout << std::endl;
    std::cout<< "List2: ";
    
    while (List2 != nullptr) {
        std::cout<< List2->val<< " ";
        List2 = List2->next;
    }

    std::cout << std::endl;
    std::cout<< "answer: ";
    while (answer != nullptr) {
        std::cout<< answer->val<< " ";
        answer = answer->next;
    }

    delete example;
    
}
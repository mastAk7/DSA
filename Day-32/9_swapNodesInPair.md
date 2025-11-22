```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define l ListNode
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head; 
        if(!head->next) return head;
        l *temp = head->next;
        head->next = head->next->next;
        temp->next = head;
        while(head->next && head->next->next){
            l *temp1 = head->next;
            l *temp2 = temp1->next->next;
            head->next = temp1->next;
            head->next->next = temp1;
            temp1->next = temp2;
            head = head->next->next;
        }
        return temp;
    }
};
```
## sol 1: not optimized
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = 1;
        ListNode* temp = head;
        while(temp->next){
            c++;
            temp = temp->next;
        }
        c -= n;
        if(c==0){
            temp = head;
            head = head->next;
            return head;
        }
        if(n==1){
            temp = head;
            while(temp->next->next) temp = temp->next;
            ListNode* nw = temp;
            nw = nw->next;
            temp->next = nullptr;
            return head;
        }
        temp = head;
        for(int i=1; i<c; i++) temp = temp->next;
        ListNode* nw = temp;
        nw = nw->next;
        temp->next = nw->next;
        return head;
    }
};
```

## sol 2: optimized, fast and slow pointer approach used

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0; i<=n; i++){ 
            if(!fast){
                head = head->next;
                delete slow;
                return head;
            }
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
        return head;
    }
};
```
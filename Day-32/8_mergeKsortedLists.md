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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==nullptr && list2==nullptr){
            return nullptr;
        }
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        
        ListNode* cur=nullptr, *temp=nullptr;

        if(list1->val<list2->val){
            cur=list1;
            list1=list1->next;
            cur->next=nullptr;
        }
        else{
            cur=list2;
            list2=list2->next;
            cur->next=nullptr;
        }

        ListNode* newHead=mergeTwoLists(list1,list2);
        cur->next=newHead;

        return cur;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        for(int i=1; i<lists.size(); i++){
            lists[i] = mergeTwoLists(lists[i-1],lists[i]);
        }
        return lists[lists.size()-1];
    }
};
```
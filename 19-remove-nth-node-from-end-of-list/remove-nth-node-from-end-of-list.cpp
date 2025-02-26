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
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr && n>0){
            return nullptr;
        }
        ListNode* curr=head,*end=head;
        for(int i=0;i<n;i++){
            end=end->next;
        }
        while(end!=nullptr && end->next!=nullptr){
            curr=curr->next; end = end->next;
        }
        if(end==nullptr){
            return head->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};
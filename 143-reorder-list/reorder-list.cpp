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
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* prev=nullptr,*curr=head,*next=head->next;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* reversed=reverse(slow);
        ListNode* straight = head;
        while (reversed && straight) {
            ListNode* temp1 = straight->next;
            ListNode* temp2 = reversed->next;

            straight->next = reversed;
            reversed->next = temp1;

            straight = temp1;
            reversed = temp2;
        }
        if (straight) straight->next = nullptr; 
        //else last node points to previous node and cycle will be there
    }
};
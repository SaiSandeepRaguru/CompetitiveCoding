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
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        ListNode* head=nullptr, *curr=nullptr;
        ListNode* head1=list1, *head2=list2;
        while(head1!=nullptr && head2!=nullptr){
            if(head1->val<head2->val){
                if(head==nullptr){
                    head=curr=head1;
                }
                else{
                    curr->next=head1;
                    curr=curr->next;
                }
                head1=head1->next;
            }
            else{
                if(head==nullptr){
                    head=curr=head2;
                }
                else{
                    curr->next=head2;
                    curr=curr->next;
                }
                head2=head2->next;
            }
        }
        if(head1==nullptr){
            curr->next=head2;
        }
        else if(head2==nullptr){
            curr->next=head1;
        }
        return head;
    }
};
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        int carry =0;
        ListNode* res=nullptr,*fwd=nullptr;
        while(l1!=nullptr && l2!=nullptr){
            int sum=l1->val + l2->val + carry;
            ListNode* temp=new ListNode(sum%10);
            if(res==nullptr){
                res=temp; fwd=temp;
            }
            else{
                fwd->next = temp;
                fwd=fwd->next;
            }
            l1=l1->next;
            l2=l2->next;
            carry=sum/10;
        }
        while(l1!=nullptr){
            int sum=l1->val + carry;
            ListNode* temp=new ListNode(sum%10);
            fwd->next = temp;
            fwd=fwd->next; l1=l1->next;
            carry=sum/10;
        }
        while(l2!=nullptr){
            int sum=l2->val + carry;
            ListNode* temp=new ListNode(sum%10);
            fwd->next = temp;
            fwd=fwd->next; l2=l2->next;
            carry=sum/10;
        }
        while(carry!=0){
            int sum=carry;
            ListNode* temp=new ListNode(sum%10);
            fwd->next = temp;
            fwd=fwd->next; 
            carry=sum/10;
        }
        return res;
    }
};
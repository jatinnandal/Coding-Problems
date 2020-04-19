/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* L1, ListNode* L2) {
        ListNode* l1 = L1;
        ListNode* l2 = L2;
        ListNode* prev1 = L1;
        ListNode* prev2 = L2;
        ListNode* ans = L1;
        if(l1==NULL)
            return L2;
        if(l2==NULL)
            return L1;
        int carry = 0;
        while(l1!=NULL && l2!= NULL){
            //cout<<l1->val + l2->val + carry<<endl;
            int temp = l1->val + l2->val + carry;
            l1->val = (temp)%10;
            l2->val = (temp)%10;
            carry = (temp)/10;
            //cout<<l1->val<<" "<<l2->val<<endl;
            prev1 = l1;
            prev2 = l2;
            l1=l1->next;
            l2=l2->next;
            //cout<<carry<<endl;
        }
        while(l1!=NULL){
            cout<<carry<<endl;
            ans = L1;
            int x = l1->val + carry;
            l1->val = (x)%10;
            carry = (x)/10;
            prev1 = l1;
            l1=l1->next;
            cout<<carry<<endl;
        }
        while(l2!=NULL){
            ans = L2;
            int x = l2->val + carry;
            l2->val = (x)%10;
            carry = (x)/10;
            prev2 = l2;
            l2=l2->next;
        }
        if(carry>0){
            ListNode *temp;
            temp = new ListNode(carry);
            if(ans == L1){
                prev1->next = temp;
            }else{
                prev2->next = temp;
            }
        }
        return ans;
    }
};

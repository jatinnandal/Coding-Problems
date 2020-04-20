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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)   //if one of the list is empty return other
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* head; //head of the merged list;
        if(l1->val>l2->val){
            head = new ListNode(l2->val);
            l2 = l2->next;
        }else{
            head = new ListNode(l1->val);
            l1 = l1->next;
        }
        ListNode* temp = head;  
        while(l1&&l2){
            if(l1->val > l2->val){
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            }else{
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }    
            temp = temp->next;
        }
        if(l1){
            temp->next = l1;
        }if(l2){
            temp->next = l2;
        }
        return head;
    }
};

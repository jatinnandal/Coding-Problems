/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    int pow_fast(int a,int b){
	if(b==0)
	return 1;
	else if(b%2==0)
	return pow_fast(a*a,b/2);
	else
	return a*pow_fast(a*a,b/2);
}
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
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0)         //no list to merge
            return NULL;
        if(k==1)        // only one list
            return lists[0];
        int l = k;
        while(k){      // pair list and merge each pair. no. of lists == k-->k/2-->k/4---
            for(int i=0;i<l/2;i++){
                    lists[i] = mergeTwoLists(lists[i],lists[l-1-i]);  //function to merge two lists
            }
            k = k/2;
            l = (l+1)/2; 
        }
        return lists[0];  //final list will be stored at lists[0]
    }
};

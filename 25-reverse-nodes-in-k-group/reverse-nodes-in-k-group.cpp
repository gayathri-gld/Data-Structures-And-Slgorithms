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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i = 0; i<k; i++){
            if(!temp)
                return head; //if current list len is < k return from there
            temp = temp->next;
        }
        ListNode *prev = NULL, *curr = head, *n;
        for(int i = 0; i<k; i++){ //reverse only k nodes
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        head->next = reverseKGroup(curr,k); //kth node becomes the head (or prev in this case) after reversal
        //so the next k nodes needs to be reversed now, and head is prev so curr is next
        return prev; //since its recursion, final reversal will be the first k nodes, so we return the  prev of that
        
    }
};
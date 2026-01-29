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
        ListNode* fast = head, *slow = head;
        while(fast && fast->next && n--)
            fast = fast->next;
        if(n>0)
            return slow->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next? slow->next->next: NULL;
        return fast? head: NULL;

    }
};
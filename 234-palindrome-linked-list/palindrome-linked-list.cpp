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
    bool isPalindrome(ListNode* head) {
        ListNode* prev = NULL, *slow = head, *n, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            n = slow->next;
            slow->next = prev;
            prev = slow;
            slow = n;
        }
        //if len is odd fast is not NULL
        //if len is even fast is NULL
        slow = fast? slow->next : slow;
        while(slow){
            if(slow->val != prev->val)
                return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};
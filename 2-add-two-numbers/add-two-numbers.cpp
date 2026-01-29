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
        ListNode dummy (0);
        ListNode* node = &dummy;
        int carry = 0;
        while(l1||l2){
            int l1_val = l1? l1->val : 0;
            int l2_val = l2? l2->val : 0;
            int val = l1_val + l2_val + carry;
            carry = val/10;
            int sum = val%10;
            node->next = new ListNode(sum);
            node = node->next;
            l1 = l1? l1->next:NULL;
            l2 = l2? l2->next:NULL;
        }
        if(carry > 0)
            node->next = new ListNode(carry);
        return dummy.next;
    }
};
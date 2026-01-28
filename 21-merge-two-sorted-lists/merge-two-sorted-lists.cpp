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
        ListNode dummy(0);
        ListNode* node = &dummy;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        while(l1 && l2){
            node->next = l1->val < l2->val? l1 : l2;
            if(l1->val <= l2->val){
                node->next = l1;
                l1 = l1->next? l1->next: NULL;
            }
            else{
                node->next = l2;
                l2 = l2->next? l2->next: NULL;
            }
            node = node->next;
        }
        if(!l1 && l2)
            node->next = l2;
        if(!l2 && l1)
            node->next = l1;
        return dummy.next;
    }
};
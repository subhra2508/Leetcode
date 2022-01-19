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
    ListNode *detectCycle(ListNode *head) {
        ListNode*fast_ptr = head;
        ListNode*slow_ptr = head;
        while(fast_ptr && fast_ptr->next && fast_ptr->next->next){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if(slow_ptr == fast_ptr)break;
        }
        if(!(fast_ptr && fast_ptr->next && fast_ptr->next->next))return NULL;
        while(slow_ptr != head){
            head = head->next;
            slow_ptr = slow_ptr->next;
        }
        return head;
    }
};
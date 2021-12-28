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
    ListNode* middleNode(ListNode* head) {
        ListNode*first_ptr=head;
        ListNode*last_ptr = head;
        while(first_ptr->next && first_ptr->next->next){
            first_ptr = first_ptr->next->next;
            last_ptr = last_ptr->next;
        }
        if(first_ptr->next!=NULL)return last_ptr->next;
        return last_ptr;
    }
};
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

/*
--------------------------------------------------
MY SOLUTION :
--------------------------------------------------
*/
class Solution {
public:
    int length(ListNode*head){
        ListNode*temp = head;
        int count = 0;
        while(temp != NULL){
            temp=temp->next;
            count++;
        }
        return count ;
    }
    ListNode*rotateRightHelper(ListNode*head){
        ListNode*curr = head;
        ListNode*prev = NULL;
        if(curr->next == NULL)return curr;
        while(curr->next != NULL){
            prev = curr ;
            curr = curr->next;
        }
        curr->next = head;
        prev->next = NULL;
        return curr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return NULL;
        int n = length(head);
        if(k > n){
            k = k%n;
        }
        int count = 0;
        ListNode*temp = head;
        while(count < k){
             count++;
            temp = rotateRightHelper(temp);
            // cout<<temp->val<<endl;
           
        }
        return temp;

};


/*
--------------------
OPTIMAL SOLUTION : (BETTER)
--------------------
*/
ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int size = 1;
        ListNode* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
            size++;
        }
        k = size - k % size;
        tmp->next = head;
        while(k--)tmp = tmp->next;
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};




















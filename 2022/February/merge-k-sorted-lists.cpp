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
    ListNode*mergeSortedList(ListNode*first,ListNode*second){
        ListNode*result = NULL;
        if(first==NULL)return second;
        if(second == NULL)return first;
        if(first->val < second->val){
            result = first;
            result->next = mergeSortedList(first->next,second);
        }
        else{
            result = second->val;
            result->next = mergeSortedList(first,second->next);
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       int k = lists.size();
        if(k==0)return NULL;
        int start = 0;
        int last = k-1;
        int temp;
        while(last != 0){
            start = 0;
            temp = last;
            while(start<temp){
                lists[start]=mergeSortedList(lists[start],lists[temp]);
                start++;
                temp--;
                if(start>=temp){
                    last = temp;
                }
            }
        }
        return lists[0];
        
    }
};
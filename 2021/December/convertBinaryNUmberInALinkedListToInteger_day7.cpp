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
    int getDecimalValue(ListNode* head) {
      vector<int>v;
        traversal(head,v);
        reverse(v.begin(),v.end());
        return binaryToDecimal(v);
    }
    
    void traversal(ListNode*root,vector<int>&v){
        ListNode*temp = root;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
    }
    int binaryToDecimal(vector<int>v){
        int dec_value = 0;
        int base = 1;
        for(auto i:v){
            dec_value +=i*base;
            base = base*2;
        }
        return dec_value;
    }
    
};
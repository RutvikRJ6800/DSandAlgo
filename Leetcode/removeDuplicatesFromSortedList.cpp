/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        
//         time O(n) & space O(N);
//         unordered_set<int> s;
//         ListNode* curr,*prev;
//         prev=NULL;
//         curr=head;
        
//         while(curr){
            
//             int data = curr->val;
//             if(s.size()!=0 && s.find(data)!=s.end()){
//                 prev->next=curr->next;
//                 curr=curr->next;
//                 continue;
//             }
//             s.insert(data);
//             prev=curr;
//             curr=curr->next;
//         }
//         return head;
        
        
        
//         time -O(N) & space- O(1)
        ListNode* curr,*prev;
        curr=head->next;
        prev=head;
        int prevData = prev->val;
        
        while(curr){
            if(prevData == curr->val){
                prev->next=curr->next;
                // delete curr;
            }
            else{
                prev=curr;
                prevData=curr->val;
            }
            curr=curr->next;
        }
        return head;
        
    }
};
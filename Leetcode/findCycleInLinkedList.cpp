/**
 * https://leetcode.com/problems/linked-list-cycle/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
//         using set -T & S-O(n)
//         unordered_set <ListNode *> s;
        
//         ListNode* curr = head;
//         while(curr){
//             if(!s.empty() && s.find(curr)!=s.end()){
//                 return true;
//             }
//             s.insert(curr);
//             curr = curr->next;
//         }
//         return false;
        
//         using rabit tertle approch - T-O(n) and S-O(1)
        ListNode* slow;
        ListNode* fast;
        slow = head;
        fast = head;
        while(slow != NULL && fast!=NULL){
            
            slow = slow->next;
            if(fast->next!=NULL){
                fast = fast->next->next;
            }
            else{
                break;
            }
            
            if(slow == fast){
                return true;
            }
            
        }
        return false;
        
        
        
        
    }
};
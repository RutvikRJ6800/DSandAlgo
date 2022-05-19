/**
 * https://leetcode.com/problems/linked-list-cycle-ii/
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
//         unordered_set <ListNode*> s;
        
//         while(head){
//             if(!s.empty() && s.find(head->next)!=s.end()){
//                 return head->next;
//             }
//             s.insert(head);
//             head=head->next;
//         }
//         return NULL;
        
        ListNode *slow, *fast;
        slow=head;
        fast=head;
        
        while(slow != NULL && fast!=NULL){
            
            slow = slow->next;
            if(fast->next!=NULL){
                fast = fast->next->next;
            }
            else{
                break;
            }
            
            if(slow == fast){
                return slow;
            }
            
        }
        return NULL;
        
    }
};
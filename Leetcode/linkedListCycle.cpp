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
        // O(N) time, O(N) space
//         unordered_set <ListNode*> s;
        
//         while(head){
//             if(!s.empty() && s.find(head->next)!=s.end()){
//                 return head->next;
//             }
//             s.insert(head);
//             head=head->next;
//         }
//         return NULL;
        

// O(N) time, O(1) space
        // cycle not possible case;
        if(!head || !head->next){
            return NULL;
        }

        ListNode *slow, *fast, *entry;
        slow=head;
        fast=head;
        entry=head;

         while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){

                while(entry!=slow){
                    entry=entry->next;
                    slow = slow->next;
                }
                return entry;
            }            
        }
        return NULL;
        
    }
};
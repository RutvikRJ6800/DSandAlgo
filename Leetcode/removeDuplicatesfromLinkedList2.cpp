/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/
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
        
        ListNode* dummy,*prev;
        dummy = new ListNode(0,head);
        prev=dummy;
        
        while(head){
            if(head->next && head->val == head->next->val){
                while(head->next && head->val == head->next->val){
                    head=head->next;
                }
                prev->next=head->next;
            }
            else{
                prev=prev->next;
            }
            head=head->next;
        }
        return dummy->next;
        
        
        
        
        
        // if(!head || !head->next){
        //     return head;
        // }
        
//         while(curr && curr->next){
            
//             if(curr->val  == curr->next->val){
//                 while(curr && curr->next && (curr->val  == curr->next->val)){
//                     curr= curr->next;
//                 }
//                 curr=curr->next;
//                 continue;
//                 // delete curr;
//             }
//             else{
//                 if(prev==NULL){
//                     head=curr;
//                     prev = curr;
//                     curr=curr->next;
//                 }
//                 else{
//                     prev->next=curr;
//                     prev=curr;
//                     curr=curr->next;   
//                 }
//             }
//         }
//         if(curr!=NULL){
           
//             if(prev==NULL){
//                 head=curr;
//             }
//             else
//                  prev->next=curr;
//             // prev->next=NULL;
                
//         }
//         else{
//             if(prev==NULL){
//                 return NULL;
//             }
//             else
//             prev->next=NULL;
//         }
//         return head;
        
           
    }
};
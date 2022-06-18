/**
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * https://www.youtube.com/watch?v=Lhu3MsXZy-Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=30
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
//         1 - pass(two pointer methd)
        ListNode* back=head,*forward=head->next;
        if(!forward && n==1){
            return NULL;
        }
        while(n && forward){
            forward=forward->next;
            n--;
        }
        if(n==1){
            back=back->next;
            return back;
        }
        
        while(forward){
            forward = forward->next;
            back = back->next;
        }
        back->next = back->next->next;
        return head;
        
        
        
        
        // 2 pass - count nodes method
//         if(head==NULL) return head;
//         size_t size=0;
//         ListNode * temp=head;
        
// //         find the size of linked list
//         while(temp){
//             temp= temp->next;
//             size++;
//         }
        
// //         if there is only one element in linkedlist and that need to be deleted
// //         then just return NULL
//         if(size==1&&n==1){
//             return NULL;
//         }
        
// //  find element to be skipped to reach one element ahead of the element we want to delete        
//         int elementNeedToSkipped = size-n-1;   
//         temp = head;
        
// // if it is -1 that means we want to delete first element(pointed by head)         
        
//         if(elementNeedToSkipped==-1){
//             head=head->next;
//             return head;
//         }

// //  else
        
//         while(elementNeedToSkipped>0){
//             temp=temp->next;
//             elementNeedToSkipped--;
            
//         }
        
// // point the element we want to delete        
//         ListNode* NodeD=temp->next;
        
// // change the next of element ahead of the element we want to delete
//         temp->next=temp->next->next;
        
//         // free()
//         return head;
    }
};
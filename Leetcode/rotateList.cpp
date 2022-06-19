/**
 * https://leetcode.com/problems/rotate-list/
 * https://www.youtube.com/watch?v=9VPm6nEbVPA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=39
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        int len=1;
        ListNode* curr = head;
        
        while(curr->next && ++len){
            curr=curr->next;
        }
        
        curr->next=head;
        k = k%len;
        k = len-k;
        
        while(k--) curr=curr->next;
        
        head=curr->next;
        curr->next=NULL;
        
        return head;
        
        
        
        
//         two pointer approcah -O(N) time but bad code look
//         ListNode* front,*rear;
//         if(!head)return NULL;
        
//         ListNode* temp,*temp2;
        
// //         count nodes in list
//         temp=head;
//         int cnt=0;
        
//         while(temp){
//             cnt++;
//             temp=temp->next;
//         }
        
//         k = k%cnt;  // make k lie within 0 to n-1
//         if(k==0)return head;
        
        
//         rear=head;
//         front=head->next;
        
//         while(k--)front=front->next;    // take front pointer k nodes ahead than rear
        
//         while(front){
//             //simultaneously go ahead in both pointers till front becomes null
//             front=front->next;
//             rear=rear->next;
//         }
      
// //         Now rear points the last node of the resultat list
//         temp=rear->next;
//         temp2=temp;
    
//         rear->next=NULL;
        
//         while(temp2->next){
//             temp2=temp2->next;
//         }
//         temp2->next=head;
//         head=temp;
        
//         return head;
    }
};
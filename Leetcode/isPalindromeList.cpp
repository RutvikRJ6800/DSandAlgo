/**
 * https://leetcode.com/problems/palindrome-linked-list/
 * https://www.youtube.com/watch?v=-DtNInqFUXs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=36
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
    bool isPalindrome(ListNode* head) {
        if(!head)return head;
        
//         aproach-1: time & space-O(N);
//         ListNode* curr1 = head,*newHead=NULL;
//         int num=0;

//         while(curr1){
//             ListNode* curr= new ListNode(curr1->val,newHead);
//             newHead=curr;
//             curr1=curr1->next;
//         }
        
//         curr1=head;
//         ListNode* curr2=newHead;
//         while(curr1){
//             if(curr1->val!=curr2->val){
//                 return false;
//             }
//             curr1=curr1->next;
//             curr2=curr2->next;
//         }
//         return true;
        
        ListNode *f,*s,*dummy,*prev,*curr,*next;
        f=head;
        s=head;
        
        while(f->next &&  f->next->next){
            s=s->next;
            f=f->next->next;
        }
        
        prev=NULL;
        next=NULL;
        curr=s->next;
        
        while(curr){
            next=curr->next;
            
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        s->next=prev;
        s=s->next;
        dummy=head;
        while(s){
            if(dummy->val != s->val)return false;
            dummy=dummy->next;
            s=s->next;
        }
        
        return true;
        
    }
};
// https://leetcode.com/problems/reverse-linked-list-ii/submissions/
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
    
    ListNode* reverse(ListNode* first,ListNode* last){
        
        ListNode* curr,*next,*prev;
        next=NULL;
        prev=NULL;
        ListNode* lastNext = last->next;
        ListNode* firstNext=first->next;
        curr = first;
        while(curr!=last&&curr!=NULL){
            
            next=curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;     
        }
        
        last->next=prev;
        first->next=lastNext;
        
        return last;
        
        
        
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* first,*last,*temp,*firstPrev;
        temp=head;
        first=head;
        firstPrev=NULL;
        last=head;
        int tleft=left-1;
        int tright=right-1;
        while(tleft){
            firstPrev=first;
            first=first->next;
            tleft--;
        }
        while(tright){
            last=last->next;
            tright--;
        }
        
        
        ListNode * rj=reverse(first,last);
        if(firstPrev!=NULL){
            firstPrev->next=rj;
            return head;
    }
        else
            return rj;
    
    
        
    }


};
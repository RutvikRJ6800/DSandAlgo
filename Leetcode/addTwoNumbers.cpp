/**
 *  https://leetcode.com/problems/add-two-numbers/submissions
 * https://www.youtube.com/watch?v=LBVsXSMOIk4&ab_channel=takeUforward
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
    ListNode* reverse(ListNode *head){
        if(!head || !head->next){
            return head;
        }
        
        ListNode *curr,*prev,*next;
        curr=head;
        prev=NULL;
        next=NULL;
        
        while(curr){
            next=curr->next;
            
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        ListNode* dummy= new ListNode(0,NULL);
        ListNode* prev =dummy;
        
        while(l1 || l2 || carry != 0){
            int sum=0;
            
            if(l1){
                sum += l1->val;
                l1=l1->next;
            }
            if(l2){
                sum += l2->val;
                l2=l2->next;
            }
            
            if(carry){
                sum += carry;
                carry=0;
            }
            
            prev->next = new ListNode(sum%10);
            prev = prev->next;
            
            carry = sum/10;
            
        }
        return dummy->next;
        
        
        
        
        
        
        
        
        
        
//         long long num1=0,num2=0,sum;
//         bool first=true;
        
//         l1=reverse(l1);
//         while(l1){
//             num1 = num1*10 + l1->val;
//             l1=l1->next;
//         }
        
//         l2=reverse(l2);
//         while(l2){
//             num2 = num2*10 + l2->val;
//             l2=l2->next;
//         }
         
//         sum=num1+num2;
        
//         first=true;
//         int count=0,rev=0;
        
//         ListNode* head=NULL,*newNode=NULL,*tail;
//         while(first||sum){
//             first=false;
//             int rem = sum%10;
//             if(!head){
//                 head=new ListNode(rem,NULL);
//                 tail=head;
//             }
//             else{
//                 newNode = new ListNode(rem);
//                 tail->next=newNode;
//                 tail=tail->next;
//             }
//             sum/=10;
//         }
//         return head;
        
    }
};
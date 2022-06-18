/**
//  https://leetcode.com/problems/merge-two-sorted-lists/submissions/ 
// 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
//         merge nodes of both list whithout creating the new Node / List(INPLACE)
        
//         Reccursive
        if(!list2)return list1;
        if(!list1)return list2;
        
        if(list1->val >= list2->val){
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
        else{
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        
        
        
        
        // Iterative
//         ListNode* dummy = new ListNode(0,NULL);
//         ListNode* prev = dummy;
        
//         while(list1 && list2){
//             if(list1->val > list2->val){
//                 prev->next = list2;
//                 list2 = list2->next;
//                 prev = prev->next;
//             }
//             else{
//                 prev->next = list1;
//                 list1=list1->next;
//                 prev=prev->next;
//             }
//         }
//         if(list1){
//             prev->next=list1;
//         }
//         if(list2){
//             prev->next=list2;
//         }
//         return dummy->next;
        
        
        
        
        
        
        
//         create List/new nodes for merging both list(OUTPLACE)

//         ListNode* temp1=list1;
//         ListNode* temp2 = list2;
//         ListNode* head =NULL;
//         ListNode* temp =NULL;
//         while(temp1!=NULL&&temp2!=NULL){
//             if(temp1->val<temp2->val){
//                 ListNode *curr = new ListNode(temp1->val);
//                 temp1 = temp1->next;
//                 if(temp==NULL){
//                     head =curr;
//                     temp=curr;
//                 }
//                 else{
//                     temp->next=curr;
//                     temp = temp->next;
//                 }
//             }
//             else{
//                 ListNode *curr = new ListNode(temp2->val);
//                 temp2 = temp2->next;
//                 if(temp==NULL){
//                     head =curr;
//                     temp=curr;
//                 }
//                 else{
//                     temp->next=curr;
//                     temp = temp->next;
//                 }
//             }
        
//         }
//             while(temp1!=NULL){
                
//                 if(temp==NULL){
//                     head = new ListNode(temp1->val);
//                     temp=head;
//                 }
//                 else{
//                     temp->next=new ListNode(temp1->val);
//                     temp = temp->next;
                   
//                 }
//                  temp1=temp1->next;                
//             }
//             while(temp2!=NULL){
                
//                 if(temp==NULL){
//                    head = new ListNode(temp2->val);
//                     temp=head;
//                 }
//                 else{
//                     temp->next=new ListNode(temp2->val);
//                     temp = temp->next;
                    
//                 }
//                 temp2=temp2->next;           
//             }        
//         return head;
    }
};
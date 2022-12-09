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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode* curr, *odd, *even;
        curr=head;
        ListNode dummyOdd = (-1), dummyEven = (-1);
        odd = &dummyOdd;
        even = &dummyEven;
        int i=0;
        while(curr){
//             check curr node value is odd
            if(i % 2==1){
                odd->next=curr;
                odd = odd->next;
            }
            else{
//                 curr node value is even
                even->next = curr;
                even = even->next;
            }
            curr = curr->next;
            i++;
        }
        
//         attach even linked list at end of odd linked list
        
        odd->next = NULL;
        even->next = dummyOdd.next;
        return dummyEven.next;
    }
};

/*
Intuition
Approach
step 1: Initiallise two pointers odd and even pointing last node of respective lists and two Node dummyOdd and dummyEven to store head of odd list and head of even list.

step 2: Start from the head of linkedlist and check if current node is at even place then append it even list, else append it to odd list.

step 3: perform step 2 untill you reach NULL.

step 4: append head of even list(dummyEven) at end of head of odd list(dummyOdd).

Complexity
Time complexity: O(n)O(n)O(n), where n is number of node in linked list.
Space complexity: O(1)O(1)O(1).
*/
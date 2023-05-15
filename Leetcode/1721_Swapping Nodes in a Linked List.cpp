// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

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
    ListNode* swapNodes(ListNode* head, int k) {
        /*
        two pass solution
        int l = 0;
        ListNode* temp = head;
        while(temp){
            l++;
            temp = temp->next;
        }

        ListNode* starting = head;
        int tempk = k;

        while(--tempk){
            starting = starting -> next;
        }

        tempk = l - k + 1;
        ListNode* ending = head;
        while(--tempk){
            ending = ending -> next;
        }

        // swap starting and ending
        int tempVal = starting -> val;
        starting -> val = ending ->val;

        ending -> val = tempVal;

        return head;
        */

        // onepass solution
        ListNode* start = nullptr, *end = nullptr;

        for(auto p=head; p!=nullptr; p = p->next){
            if(end)
                end = end-> next;
            
            if(--k == 0){
                start = p;
                end = head;
            }
        }
        
        // cout<<start<<":"<<end;
        int val = start -> val;
        start -> val = end ->val;
        end -> val = val;
        return head;
    }
};
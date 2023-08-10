// https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    ListNode* mergeTwoList(ListNode* ptr1, ListNode* ptr2){
        ListNode dummy = ListNode(-1);
        ListNode* curr = &dummy;

        while(ptr1 && ptr2){
            if(ptr1->val <= ptr2->val){
                curr->next = ptr1;
                curr = curr->next;
                ptr1 = ptr1->next;
            }
            else{
                curr->next = ptr2;
                curr = curr->next;
                ptr2 = ptr2->next;
            }
        }

        if(ptr1){
            curr -> next = ptr1;
        }

        if(ptr2){
            curr->next = ptr2;
        }

        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n==0) return nullptr;
        if(n==1) return lists[0];

        int i=n-1;
        while(i>0){
            lists[i-1] = mergeTwoList(lists[i-1], lists[i]);
            i--;
        }
        return lists[0];
    }
};

/*
Using priority queue
static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
}
ListNode* mergeKLists(vector<ListNode*>& lists) { //make_heap
    ListNode head(0);
    ListNode *curNode = &head;
    vector<ListNode*> v;   
    for(int i =0; i<lists.size(); i++){
        if(lists[i]) v.push_back(lists[i]);
    }
    make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

    while(v.size()>0){
        curNode->next=v.front();
        pop_heap(v.begin(), v.end(), heapComp); 
        v.pop_back(); 
        curNode = curNode->next;
        if(curNode->next) {
            v.push_back(curNode->next); 
            push_heap(v.begin(), v.end(), heapComp);
        }
    }
    return head.next;
}
*/
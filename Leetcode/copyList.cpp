/*
https://leetcode.com/problems/copy-list-with-random-pointer/
https://www.youtube.com/watch?v=VNf6VynfpdM
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)return NULL;
        
        Node* front,*rear,*newHead;
        
        front=head;
        rear=head->next;
        
        while(front){
//             crear deep copy of front data
            Node* curr = new Node(front->val);
//             make front's next as copy created
            front->next=curr;
//             make copy's next as next node of original list
            curr->next=rear;
            
            front=front->next->next;
            if(rear)rear=rear->next;
    
        }
        
        front=head;
        
        while(front){
//             if front random is not null than change
            if(front->random){
                front->next->random=front->random->next;
            }
            front = front->next->next;
        }
        
        front=head;
        newHead=rear=head->next;
        
//         make original list and created list separate by arranging next pointers
        while(front){
            front->next=front->next->next;
            if(rear->next)
            rear->next=rear->next->next;
            
            front = front->next;
            rear=rear->next;
        }
        
        return newHead;
        
        
        
        
        
        
//         Node* newHead=new Node(-1),*prev,*temp,*temp2;
//         temp=head;
//         temp2=newHead;
//         vector<Node*> l1;
//         vector<Node*> l2;
        
        
//         while(temp){
//             Node *curr= new Node(temp->val);
//             l1.push_back(temp);
//             l2.push_back(curr);
            
//             temp2->next=curr;
                 
//             temp2=temp2->next;
//             temp=temp->next;
//         }
        
//         temp=head;
//         temp2=newHead->next;
        
//         while(temp && temp2){
//             if(temp->random){
//                 auto it = find(l1.begin(),l1.end(),temp->random);
//                 temp2->random=l2[(it-l1.begin())];
//             }
                       
            
//             temp=temp->next;
//             temp2=temp2->next;
//         }
//         return newHead->next;
    }
};
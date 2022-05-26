// { Driver Code Starts
// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int findLength(Node* head){
    int length=0;
    while(head){
        length++;
        head=head->next;
    }
    return length;
}


int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    
    
    // time O(N) and constant space so;ution
    int l1,l2,diff;
    diff=0;
    l1=findLength(head1);
    l2=findLength(head2);
    
    if(l1>l2){
        diff=l1-l2;
        while(diff){
            diff--;
            head1=head1->next;
        }
        
    }
    else{
        diff=l2-l1;
        while(diff){
            diff--;
            head2=head2->next;
        }
    }
    
    while(head1!=head2){
        head1=head1->next;
        head2=head2->next;
    }
     if(head1==NULL){
        return -1;
    }
    return head1->data;
    
    
    
    //  time O(N) and space O(N) solution
    
    // unordered_set<Node*> s1,s2;
    
    // while(head1 || head2){
    //     if(head1){
    //         s1.insert(head1);
    //     }
    //     if(head2){
    //         s2.insert(head2);
    //     }
        
    //     if(head1 && s2.find(head1)!=s2.end()){
    //         return head1->data;
    //     }
        
    //     if(head2 && s1.find(head2)!=s1.end()){
    //         return head2->data;
    //     }
        
    //     if(head1) head1=head1->next;
    //     if(head2) head2=head2->next;
    // }
    // return -1;
}


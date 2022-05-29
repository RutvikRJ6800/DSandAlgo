/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;
 
class myStack {
    struct Node {
        int num;
        Node* next;
        Node* prev;
 
        Node(int num) { this->num = num; }
    };
 
    // Members of stack
    Node* head = NULL;
    Node* mid = NULL;
    int size = 0;
 
public:
    void push(int data)
    {
        if(!head){
            head = new Node(data);
            mid = head;
            size++; 
            return;
        }

        Node* curr = new Node(data);
        curr->next = head;
        head -> prev = curr;
        head = curr;
        if(size%2==1){
            mid = mid->prev;
        }
        size++;
    }
 
    int pop()
    {
        if(head == NULL){
            return -1;
        }
        Node* curr = head;
        int result = curr->num;
        if(!head->next && !head->prev){
            head =NULL;
            mid = NULL;
            free(curr);
            return result;
        }
        head = head->next;
        head->prev = NULL;
        if(size%2==0){
            mid=mid->next;
        }
        free(curr);
        size--;
        return result;
    }
 
    int findMiddle()
    {
        if(!mid){
            return -1;
        }
        else 
        return mid->num;
    }
 
    void deleteMiddle()
    {
        if(size==0)
        return;
        
        if(size%2==0){
            Node* curr = mid;
            if(mid->prev)
            mid->prev->next = mid->next;
            if(mid->next)
            mid->next->prev = mid->prev;
            if(mid==head)
            head = head ->next;
            mid=mid->next;
            size--;
        }
        else{
            Node* curr =mid;
            
            // if size == 1 means only one elemtnt in stack
            if(!mid->prev && !mid->next && mid == head){
                mid = NULL;
                free(head);
                head = NULL;
                size--;
                return;
            }
            if(mid->prev)
            mid->prev->next = mid->next;
            if(mid->next)
            mid->next->prev = mid->prev;
            mid=mid->prev;
            size--;
        }
    }
    void travers(){
        if(!head){
            cout<<"stack is empty";
        }
        cout<<"stack contains: ";
        Node* curr = head;
        while(curr){
            cout<<curr->num<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};
 
int main()
{
    myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    st.travers();
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}
// This code is contributed by Nikhil Goswami
// Updated by Amsavarthan LV
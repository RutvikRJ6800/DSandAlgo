// https://practice.geeksforgeeks.org/problems/median-of-bst/1c

float findMedian(struct Node *root)
{
      //Code here
      int cnt=0;
      stack<Node*> st;
      Node* temp = root;
      
      while(temp){
          st.push(temp);
          temp = temp->left;
      }
      
      while(!st.empty()){
          temp = st.top();
          st.pop();
          cnt++;
          
          temp = temp->right;
          
          while(temp){
              st.push(temp);
              temp= temp->left;
          }
      }
      
    //   cout<<cnt<<": ";
      
      int left = cnt / 2;
      float one=0, two = 0;
      int right = left + 1, oldcnt = cnt;
      cnt = 0;
      temp = root;
      
      while(temp){
          st.push(temp);
          temp = temp->left;
      }
      while(!st.empty()){
          temp = st.top();
          cnt++;
          st.pop();
          
          if(cnt == left) one = temp->data;
          else if(cnt == right) {
            two = temp -> data;
            break;
          }
          
          temp = temp->right;
          
          while(temp){
              st.push(temp);
              temp= temp->left;
          }
      }
      
    //   cout<<one<<","<<two<<left<<right<<endl;
      
      if(oldcnt % 2 == 0) return (one + two*1.0) / 2;
      else
      return (two);
      
      
      
}


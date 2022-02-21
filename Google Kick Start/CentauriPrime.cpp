// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4332/0000000000941ec5
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string GetRuler(const string& kingdom) {
  // TODO: implement this method to determine the ruler name, given the kingdom.
  string ruler = "";
  
  vector <char> vovels =  {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
  
  char last;
  last = kingdom[kingdom.size()-1];
  
//   last = last.lower();
  
  if(last == 'y' || last == 'Y'){
      ruler = "nobody";
      return ruler;
  }
  
  ruler = "Bob";
  
  bool flag = false;
  
  for(size_t i=0; i<10; i++){
    
    if(last == vovels[i]){
        flag = true;
        break;
    }
      
      
  }
  if(flag == true){
      ruler = "Alice";
      return ruler;
  }
  
  else{
      return ruler;
  }
  
  
  
  return ruler;
}

int main() {
  int testcases;
  cin >> testcases;
  string kingdom;

  for (int t = 1; t <= testcases; ++t) {
    cin >> kingdom;
    cout << "Case #" << t << ": " << kingdom << " is ruled by "
         << GetRuler(kingdom) << ".\n";
  }
  return 0;
}

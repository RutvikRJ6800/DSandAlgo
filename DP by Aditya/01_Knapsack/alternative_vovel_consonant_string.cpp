//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        int vcount = 0, ccount=0, vidx=0, cidx=0;
        vector<int> vfreq(26,0);
        vector<int> cfreq(26,0);
        string ans = "";
        
        for(int i=0; i<N; i++){ // store freq of vovel and cons in respective array
            if(S[i] == 'a'){
                 vcount++;
                 vfreq[S[i]-'a']++;
            }
            else if(S[i] == 'e'){
                vcount++;    
                vfreq[S[i]-'a']++;
            } 
            else if(S[i] == 'i'){
                vcount++;
                vfreq[S[i]-'a']++;
            } 
            else if(S[i] == 'o'){
                vcount++;
                vfreq[S[i]-'a']++;
                
            }
            else if(S[i] == 'u'){
                vcount++;
                vfreq[S[i]-'a']++;
            } 
            else{
                ccount++;
                cfreq[S[i]-'a']++;
            }
        }
        
        
        if(abs(vcount - ccount)>1) return "-1";
        
        // find first char in vovel and cons;
        while(vfreq[vidx] == 0){
            vidx++;
        }
        while(cfreq[cidx] == 0){
            cidx++;
        }
        
        // decide which char to put first 
        bool turn;
        // turn == 1 => vovel
        // turn == 0 => cons
        
        if(ccount > vcount){
            turn = 0;
        }
        else if(ccount < vcount){
            turn = 1;
        }
        else{
            if(vidx > cidx){ // vovel is bigger
                turn = 0;
            }
            else{
                turn = 1;
            }
        }
        
        while(ans.size() < N){
            if(!turn && cidx < 26){ // take consonant
                ans += (char)(cidx + 'a');
                cfreq[cidx]--;
                while(cidx<26 && cfreq[cidx] == 0){
                    cidx++;
                }
            }
            else{
                // take  vovel
                ans += (char)(vidx + 'a');
                vfreq[vidx]--;
                while(vidx<26 && vfreq[vidx] == 0){
                    vidx++;
                }
            }
            
            turn = !turn;
        }
        
        return ans;
        
    }

    /*
    string rearrange (string S, int N)
    {
        // your code here
        
        int vcount = 0, ccount=0;
        vector<int> freq(26,0);
        priority_queue<char, vector<char>, greater<char>> vovQ;
        priority_queue<char, vector<char>, greater<char>> conQ;
        string ans = "";
        
        for(int i=0; i<N; i++){
            if(S[i] == 'a'){
                 vcount++;
                 vovQ.push(S[i]);
            }
            else if(S[i] == 'e'){
                vcount++;    
                vovQ.push(S[i]);
            } 
            else if(S[i] == 'i'){
                vcount++;
                vovQ.push(S[i]);
            } 
            else if(S[i] == 'o'){
                vcount++;
                vovQ.push(S[i]);
                
            }
            else if(S[i] == 'u'){
                vcount++;
                vovQ.push(S[i]);
            } 
            else{
                ccount++;
                conQ.push(S[i]);
            }
            
            freq[S[i]-'a']++;    
        }
        
        
        if(abs(vcount - ccount)>1) return "-1";
        
        if(conQ.size()>vovQ.size()){
            bool turn = 0;
            while(conQ.size() || vovQ.size()){
                if(!turn){
                    // conturn
                    ans += conQ.top();
                    conQ.pop();
                }
                else{
                    ans += vovQ.top();
                    vovQ.pop();
                }
                
                turn = !turn;
            }
        }
        else if(conQ.size() < vovQ.size()){
            bool turn = 1;
            while(conQ.size() || vovQ.size()){
                if(!turn){
                    // conturn
                    ans += conQ.top();
                    conQ.pop();
                }
                else{
                    ans += vovQ.top();
                    vovQ.pop();
                }
                
                turn = !turn;
            }
        }
        else{
            if(conQ.top() < vovQ.top()){
                bool turn = 0;
                while(conQ.size() || vovQ.size()){
                    if(!turn){
                        // conturn
                        ans += conQ.top();
                        conQ.pop();
                    }
                    else{
                        ans += vovQ.top();
                        vovQ.pop();
                    }
                    
                    turn = !turn;
                }    
            }
            else{
                bool turn = 1;
                while(conQ.size() || vovQ.size()){
                    if(!turn){
                        // conturn
                        ans += conQ.top();
                        conQ.pop();
                    }
                    else{
                        ans += vovQ.top();
                        vovQ.pop();
                    }
                    
                    turn = !turn;
                }    
            }
        }
        
        return ans;
        
    }
    */
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
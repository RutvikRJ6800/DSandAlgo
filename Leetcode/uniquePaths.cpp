// https://leetcode.com/problems/unique-paths/submissions/
// https://www.youtube.com/watch?v=t_f0nwwdg5o&ab_channel=takeUforward
class Solution {
public:
    
    // dp approch-O(N2) time and space.
    int rec(int x,int y, int m, int n, vector<vector<int>> &sol){
        if(x==m-1 && y==n-1){
            return 1;
        }
        else if(x>=m || y>=n){
            return 0;
        }
        else{
            if(sol[x][y]!=-1){
                return sol[x][y];
            }
            else{
                return sol[x][y]=rec(x+1,y,m,n,sol)+rec(x,y+1,m,n,sol);   
            }
        }
    }
    
    int uniquePaths(int m, int n) {

        // combinatorics approch-the most optimal one.
        int N=m+n-2;
        int r=min(m,n)-1;
        double res=1;
        for(int i=1; i<=r; i++){
            res = res*(N-r+i)/i;
        }
    
        return (int)res;


        // int x,y;
        // x=0,y=0;
        // vector<vector<int>> sol(m,vector<int>(n,-1));
        // return rec(x,y,m,n,sol);
    }
};
#include<bits/stdc++.h>
using namespace std;


vector<int> findIntersection(vector<int>A, vector<int>B){
    int i=0, j=0;
    vector<int> res;

    while(i<A.size() && j<B.size()){
        if(A[i]==B[j]){
            res.push_back(A[i]);
            i++;
            j++;

        }
        else if(A[i]<B[j]){
            i++;
        }
        else j++;
    }

    return res;
}
void printArray(vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int gcd(int a, int b){
    
    // solve using prime factorization
    int m = max(a,b);
    vector<int> seive(m+1,-1);
    for(int i= 2; i<=m;i++){
        if(seive[i]==-1){
            int num = i*i;
            while(num<=m){
                if(seive[num]==-1)seive[num]=i;
                num += i;
            }
        }
    }
    printArray(seive);

    vector<int> primeFactorOfA;
    vector<int> primeFactorOfB;

    while(seive[a]!=-1){
        primeFactorOfA.push_back(seive[a]);
        a = a/seive[a];
    }
    primeFactorOfA.push_back(a);

    printArray(primeFactorOfA);

    while(seive[b]!=-1){
        primeFactorOfB.push_back(seive[b]);
        b = b/seive[b];
    }
    primeFactorOfB.push_back(b);

    printArray(primeFactorOfB);


    vector<int> commonFactors=findIntersection(primeFactorOfA, primeFactorOfB);
    int res=1;
    for(int i=0; i<commonFactors.size(); i++){
        res *= commonFactors[i];
    }

    return res;

}

int main(){

    cout<<gcd(20,42);
    return 0;
}
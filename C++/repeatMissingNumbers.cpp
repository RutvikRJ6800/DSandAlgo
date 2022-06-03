// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> freq(A.size(),0);

    for(int i=0; i<A.size(); i++){
        freq[A[i]-1]++;
    }
    vector<int> result(2);
    for(int i=0; i<freq.size(); i++){
        if(freq[i]==0){
            result[1]=i+1;
        }
        if(freq[i]==2){
            result[0]=i+1;
        }
    }
    return result;
}

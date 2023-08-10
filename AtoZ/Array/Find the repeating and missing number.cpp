// https://www.codingninjas.com/studio/problems/missing-and-repeating-numbers_6828164

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size();
    vector<int> occur(n+1, 0);
    int repeating, sum = 0;
    for(int num: a){
        if(occur[num]) repeating = num;
        occur[num] = 1;
        sum += num;
    }
    return{repeating, n*(n+1)/2 - sum + repeating};
    
}
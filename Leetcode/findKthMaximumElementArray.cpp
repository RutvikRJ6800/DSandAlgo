class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
//         approch 1 : sort array time O(nlgn) + memory O(1)
        // sort(nums.begin(),nums.end());
        // int idx=nums.size()-k;
        // return nums[idx];
        
        
//      approch 2 : partition algo time O(n)best and O(n2) worst but if suffled then O(n) avg
        int i,j,s;
        i=0; j=nums.size();
        s=nums.size();
        // shuffle(nums);
        while(i<j){
            int idx = partition(nums,i,j);
            if(idx<s-k){
                i=idx+1;
            }
            else if(idx>s-k){
                j=idx;
            }
            else{
                break;
            }
            
        }
        return nums[s-k];
        
        
    }
    
    int partition(vector<int> &nums,int i, int j){
        int key=nums[j-1];
        int l=i-1;
        for(int k=i; k<j;k++){
            if(nums[k]<key){
                int temp=nums[++l];
                nums[l]=nums[k];
                nums[k]=temp;
            }
        }
        int temp=nums[++l];
        nums[l]=key;
        nums[j-1]=temp;
        return l;
        
    }
//     void exch(vector<int> &a, int i, int j) {
//         int tmp = a[i];
//         a[i] = a[j];
//         a[j] = tmp;
//     }
    
//     void shuffle(vector<int> &a) {

//         final Random random = new Random();
//         for(int ind = 1; ind < a.length; ind++) {
//             int r = random.nextInt(ind + 1);
//             exch(a, ind, r);
//         }
//     }

};
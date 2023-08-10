// https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?leftPanelTab=0

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int secondLargest=INT_MIN, largest=INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for(auto num: a){
        if(num>largest){
            secondLargest = largest;
            largest = num;
        }
        else if(num>secondLargest){
            secondLargest = num;
        }

        if(num<smallest){
            secondSmallest = smallest;
            smallest = num;
        }
        else if(num<secondSmallest){
            secondSmallest = num;
        }
    }
    return {secondLargest, secondSmallest};
}


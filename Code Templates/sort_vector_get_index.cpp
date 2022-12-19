vector<int> fun(vector<int> arr) {

    int N = arr.size();

    // declare temp array and initialise it with 0,1,2,3 so on
    vector<int> V(N);
    std::iota(V.begin(),V.end(),0); //Initializing

    sort( V.begin(),V.end(), [&](int i,int j){return arr[i]>arr[j];} );

    return V;
}

// ref https://stackoverflow.com/questions/1577475/c-sorting-and-keeping-track-of-indexes

static bool cmp(vector<pair<int,int>>&v1,vector<pair<int,int>>&v2{
    if(v1.second<v2.second)return true;
    if(v1.second==v2.second)return v1.first<v2.first;
    else
        return false;
}

int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back(make_pair(start[i],end[i]));
        }

        sort(vec.begin(),vec.end(),cmp)
        int cnt=0;
        if(vec.size()==0)return count;

        cnt=1;
        int lastEnd=vec[0].second;

        for(int i=1; i<n; i++){
            if(lastEnd<vec[i].first){
                cnt++;
                lastEnd=vec[i].second
            }
        }
        return cnt


        return cnt;
    }

int main(){


    cout<<maxMeetings([1,3,0,5,8,5],[2,4,6,7,9,9],6)
    return 0;

}
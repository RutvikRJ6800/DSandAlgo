class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l, r, m;

        l = 0;
        r = nums.size() - 1;
        //         modified binary search -O(log n) time comp.
        while (l <= r)
        {
            m = (l + r) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[l] <= nums[m])
            {
                //              left part is sorted
                if (target >= nums[l] && target < nums[m])
                {
                    //                     target present in left part
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                //                 right part is sorted
                if (target > nums[m] && target <= nums[r])
                {
                    //                     target present in right part
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};
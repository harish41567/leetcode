class Solution {
public:
    int binarySearch(vector<int> &v, int left, int right, int x)
    {
        while (right > left)
        {
            int mid = left + (right - left) / 2;

            if (v[mid] >= x)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        int n = v.size();

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > v[n - 1])
            {
                v.push_back(nums[i]);
                n++;
            }
            else
            {
                int index = binarySearch(v, 0, n - 1, nums[i]);
                v[index] = nums[i];
            }
        }

        return v.size();





//         int n=nums.size();

//         vector<int> dp(n,1);
//         int res=1;

//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(nums[j] < nums[i])
//                     dp[i] = max(dp[i], dp[j]+1);
//             }
//             res=max(res, dp[i]);
//         }

//         return res;
    }
};

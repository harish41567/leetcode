class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,i=n-1;
        vector<int> v(n);
        
        while(l<=r){
            if(abs(nums[l]) <= abs(nums[r]))
            {
                v[i--]=nums[r]*nums[r];
                r--;
            }
            else
            {
                v[i--]=nums[l]*nums[l];
                l++;
            }
        }
        return v;
    }
};
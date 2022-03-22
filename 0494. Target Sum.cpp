class Solution {
private:
    int findTarget(int ind, vector<int>& nums, int target)
    {
        if(ind == 0)
        {
            if(target == 0 && nums[ind] == 0)
                return 2;
            if(nums[ind] == target || -nums[ind] == target)
                return 1;
            else
                return 0;
        }
        
        int plus = findTarget(ind-1, nums, target-nums[ind]);
        int minus = findTarget(ind-1, nums, target+nums[ind]);
        
        return plus + minus;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        return findTarget(n-1, nums, target);
    }
};

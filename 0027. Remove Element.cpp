class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        if (n == 0)
            return 0;

        int left = 0, right = 0;

        while (right < n)
        {
            if (nums[right] != val)
            {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};
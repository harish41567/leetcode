class Solution {
private:
    void reverse(int left, int right, vector<int>& nums)
    {
        while(left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        k = k % n;
        reverse(0, n-k-1, nums);
        reverse(n-k, n-1, nums);
        reverse(0, n-1, nums); 
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int XOR = n;
        for (int i = 0; i < n; i++)
            XOR = XOR ^ nums[i] ^ i;

        return XOR;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (auto it : nums)
        {
            freq[it]++;
            if (freq[it] > 1)
                return it;
        }

        return -1;
    }
};

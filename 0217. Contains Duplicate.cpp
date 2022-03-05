class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for (int num : nums)
            s.insert(num);

        return (n != s.size());
    }
};

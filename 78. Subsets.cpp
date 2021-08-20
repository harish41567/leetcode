class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        v.push_back({});
        
        for(int i=0; i<nums.size(); i++)
        {
            int n=v.size();
            
            for(int j=0; j<n; j++)
            {
                v.push_back(v[j]);
                v.back().push_back(nums[i]);
            }
        }
        
        return v;
    }
};
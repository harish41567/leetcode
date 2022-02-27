class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int res = 0;
        
        for(auto it : nums)
        {
            if(count == 0)
                res = it;
            
            if(it == res)
                count++;
            else
                count--;
        }
        
        return res;
    }
};
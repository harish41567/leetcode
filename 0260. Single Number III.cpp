class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        long long XOR = 0;
        int number1 = 0, number2 = 0;
        for (int num : nums)
            XOR = XOR ^ num;

        XOR = XOR & ~(XOR - 1);

        for (int num : nums)
        {
            if (num & XOR)
                number1 = number1 ^ num;
            else
                number2 = number2 ^ num;
        }

        ans.push_back(number1);
        ans.push_back(number2);

        return ans;
    }
};

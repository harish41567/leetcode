class Solution {
private:
    int count(int n)
    {
        int cnt = 0;
        while (n > 0)
        {
            n = n & (n - 1);
            cnt++;
        }

        return cnt;
    }

public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
            ans.push_back(count(i));

        return ans;
    }
};

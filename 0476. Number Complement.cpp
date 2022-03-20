class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int cnt = 0;
        while (num)
        {
            if ((num & 1) == 0)
                ans += (1 << cnt);
            cnt++;
            num = num >> 1;
        }
        return ans;
    }
};

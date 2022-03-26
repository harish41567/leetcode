class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isCaps = true, isNotCaps = true;
        int cnt = 0;

        for (auto ch : word)
        {
            if ((ch - 'a') >= 0 && (ch - 'a') <= 25)
                isCaps = false;
            else
            {
                isNotCaps = false;
                cnt++;
            }
        }

        if (!isCaps && !isNotCaps)
        {
            if (cnt == 1 && (word[0] - 'A') >= 0 && (word[0] - 'A') <= 25)
                return true;
            return false;
        }
        return true;
    }
};

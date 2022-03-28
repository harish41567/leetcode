class Solution {
private:
    bool checkEqual(vector<int>& c1, vector<int>& c2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (c1[i] != c2[i])
                return false;
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2)
            return false;

        vector<int> c1(26, 0), c2(26, 0);
        for (int i = 0; i < n2; i++)
        {
            if (i >= n1)
            {
                if (checkEqual(c1, c2))
                    return true;

                c2[s2[i - n1] - 'a']--;
                c2[s2[i] - 'a']++;
            }
            else
            {
                c1[s1[i] - 'a']++;
                c2[s2[i] - 'a']++;
            }
        }

        if (checkEqual(c1, c2))
            return true;

        return false;
    }
};

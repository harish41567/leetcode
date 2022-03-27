class Solution {
private:
    void reverse(int left, int right, string& s)
    {
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

public:
    string reverseWords(string s)
    {
        int n = s.length();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                reverse(j, i - 1, s);
                j = i + 1;
            }
        }
        reverse(j, n - 1, s);

        return s;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (char c : t)
            m[c]++;

        int start = 0, end = 0, counter = t.size();
        int minStart = 0, minLen = INT_MAX, size = s.size();

        // counter is the number of characters we yet to find in our window.

        while (end < size) {
            if (m[s[end]] > 0)
                counter--;

            m[s[end]]--;
            end++;

            while (counter == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }

                m[s[start]]++;

                if (m[s[start]] > 0)
                    counter++;

                start++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

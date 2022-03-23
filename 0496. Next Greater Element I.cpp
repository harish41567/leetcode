class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> s;
        vector<int> nge(n, -1);
        stack<int> st;
        vector<int> res(m, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            s[nums2[i]] = i;
            while (!st.empty() && st.top() < nums2[i])
                st.pop();

            if (!st.empty())
                nge[i] = st.top();

            st.push(nums2[i]);
        }

        for (int i = 0; i < m; i++)
        {
            if (s.find(nums1[i]) != s.end())
                res[i] = nge[s[nums1[i]]];
        }

        return res;
    }
};

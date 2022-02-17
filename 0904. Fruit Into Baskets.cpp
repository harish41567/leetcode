class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();
        unordered_map<int, int> m;

        int i = 0, j = 0, res = 0;

        for (j = 0; j < n; j++) {

            m[fruits[j]]++;

            while (i < n && m.size() > 2) {
                m[fruits[i]]--;
                if (m[fruits[i]] == 0)
                    m.erase(fruits[i]);
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};

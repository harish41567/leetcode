class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int cnt = 0;

        for (int i = 0; i < size; i++)
        {
            if (flowerbed[i] == 0)
            {
                if ((i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0))
                {
                    flowerbed[i] = 1;
                    cnt++;
                }
            }
            if (cnt >= n)
                return true;
        }
        return false;
    }
};

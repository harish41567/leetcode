class Solution {
private:
    int merge(vector<int> &nums, int low, int mid, int high) {
        int cnt = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            }
            else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        return cnt;

    }

    int mergeSort(vector<int> &nums, int left, int right) {
        int inv = 0;

        if (left < right)
        {
            int mid = left + (right - left) / 2;
            inv += mergeSort(nums, left, mid);
            inv += mergeSort(nums, mid + 1, right);
            inv += merge(nums, left, mid, right);
        }

        return inv;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, (int)nums.size() - 1);
    }
};

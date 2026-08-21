class Solution {
public:
    vector<int> divide(vector<int>& nums, int i, int j) {
        int mid = i + (j - i) / 2;
        if (j - i <= 1) {
            vector<int> res;
            for (int k = i; k < j; k++) {
                res.push_back(nums[k]);
            }
            return res;
        }
        vector<int> left = divide(nums, i, mid);
        vector<int> right = divide(nums, mid, j);
        return merge(left, right);
    }
    vector<int> merge(vector<int> left, vector<int> right) {
        vector<int> res;
        int m = left.size() + right.size();
        int l = 0, r = 0;
        while (res.size() < m) {
            if (l >= left.size()) {
                res.push_back(right[r]);
                r++;
                continue;
            }
            if (r >= right.size()) {
                res.push_back(left[l]);
                l++;
                continue;
            }

            if (left[l] <= right[r]) {
                res.push_back(left[l]);
                l++;
            }

            else {
                res.push_back(right[r]);
                r++;
            }
        }
        return res;
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return nums;
        vector<int> left = divide(nums, 0, n / 2);
        vector<int> right = divide(nums, n / 2, n);
        return merge(left, right);
    }
};
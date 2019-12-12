class Solution {
public:
    int helper(vector<int>& nums, int l, int r, int k) {
        swap(nums[r], nums[l + (r - l) / 2]);
        int s = l;
        for (int f = l; f < r; ++f) {
            if (nums[f] > nums[r]) {
                swap(nums[s++], nums[f]);
            }
        }
        swap(nums[s], nums[r]);
        if (s + 1 == k) return nums[s];
        if (s + 1 > k) return helper(nums, l, s - 1, k);
        return helper(nums, s + 1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size() - 1, k);
    }
};

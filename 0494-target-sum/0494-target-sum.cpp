class Solution {
public:
    int count = 0;

    void finding(int i, vector<int>& nums, int target, int sum) {
        if (i == nums.size()) {
            if (sum == target) {
                count++;
            }
            return;
        }
        finding(i + 1, nums, target, sum + nums[i]);
        finding(i + 1, nums, target, sum - nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int zeroCount = 0;
        vector<int> nonZeroNums;
        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                nonZeroNums.push_back(num);
            }
        }
        finding(0, nonZeroNums, target, 0);
        return count * pow(2, zeroCount);
    }
};

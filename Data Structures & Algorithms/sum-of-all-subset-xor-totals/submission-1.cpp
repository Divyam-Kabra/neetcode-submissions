class Solution {
public:
    int solve(int idx, vector<int>& nums, int sum)
    {
        if (idx == nums.size())
            return sum;

        int take = solve(idx + 1, nums, sum ^ nums[idx]);
        int nottake = solve(idx + 1, nums, sum);

        return take + nottake;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(0, nums, 0);
    }
};
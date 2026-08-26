class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        while (j < n) {
            
            if (nums[i] != val) {
                i++;
                j++;
                continue;
            }

            while (j < n && nums[j] == val) {
                j++;
            }

            if (j == n)
                break;

            swap(nums[i], nums[j]);
            i++;
            j++;
        }

        return i;
    }
};
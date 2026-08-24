class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mn = INT_MAX;

        for (string s : strs) {
            mn = min(mn, (int)s.size());
        }

        int left = 0;
        int right = mn - 1;

        while (left <= right) {
            bool same = true;

            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][left] != strs[0][left]) {
                    same = false;
                    break;
                }
            }

            if (!same)
                return strs[0].substr(0, left);

            left++;
        }

        return strs[0].substr(0, mn);
    }
};
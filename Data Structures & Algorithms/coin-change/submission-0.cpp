class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {

                // Don't take the current coin
                dp[i][j] = dp[i + 1][j];

                // Take the current coin
                if (j >= coins[i])
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i][j - coins[i]]);
            }
        }

        return dp[0][amount] == INF ? -1 : dp[0][amount];
    }
};
#include <bits/stdc++.h>
using namespace std;

int main() {
    int eggs, floors;
    cin >> eggs >> floors;

    vector<vector<int>> dp(
        eggs + 1,
        vector<int>(floors + 1)
    );

    for (int e = 1; e <= eggs; e++) {
        dp[e][0] = 0;

        if (floors >= 1)
            dp[e][1] = 1;
    }

    for (int f = 1; f <= floors; f++)
        dp[1][f] = f;

    for (int e = 2; e <= eggs; e++) {

        for (int f = 2; f <= floors; f++) {

            dp[e][f] = INT_MAX;

            for (int x = 1; x <= f; x++) {

                int attempts =
                    1 + max(
                        dp[e - 1][x - 1],
                        dp[e][f - x]
                    );

                dp[e][f] =
                    min(dp[e][f], attempts);
            }
        }
    }

    cout << "Minimum Attempts: "
         << dp[eggs][floors] << endl;

    return 0;
}

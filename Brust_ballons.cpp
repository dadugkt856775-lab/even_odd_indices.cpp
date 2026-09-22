#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 2);

    a[0] = 1;
    a[n + 1] = 1;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(
        n + 2,
        vector<int>(n + 2, 0)
    );

    for (int length = 1; length <= n; length++) {

        for (int left = 1;
             left + length - 1 <= n;
             left++) {

            int right = left + length - 1;

            for (int k = left; k <= right; k++) {

                int coins =
                    a[left - 1] *
                    a[k] *
                    a[right + 1];

                coins += dp[left][k - 1];
                coins += dp[k + 1][right];

                dp[left][right] =
                    max(dp[left][right], coins);
            }
        }
    }

    cout << "Maximum Coins: "
         << dp[1][n] << endl;

    return 0;
}

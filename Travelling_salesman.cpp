#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cost(
        n,
        vector<int>(n)
    );

    for (auto& row : cost)
        for (int& x : row)
            cin >> x;

    int totalMasks = 1 << n;

    const int INF = 1e9;

    vector<vector<int>> dp(
        totalMasks,
        vector<int>(n, INF)
    );

    dp[1][0] = 0;

    for (int mask = 1; mask < totalMasks; mask++) {

        for (int u = 0; u < n; u++) {

            if (!(mask & (1 << u)))
                continue;

            if (dp[mask][u] == INF)
                continue;

            for (int v = 0; v < n; v++) {

                if (mask & (1 << v))
                    continue;

                int newMask =
                    mask | (1 << v);

                dp[newMask][v] =
                    min(
                        dp[newMask][v],
                        dp[mask][u] + cost[u][v]
                    );
            }
        }
    }

    int fullMask = totalMasks - 1;
    int answer = INF;

    for (int last = 1; last < n; last++) {
        answer = min(
            answer,
            dp[fullMask][last] + cost[last][0]
        );
    }

    cout << "Minimum Tour Cost: "
         << answer << endl;

    return 0;
}

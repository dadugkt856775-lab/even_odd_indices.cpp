#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = (s.size() + 1) / 2;

    vector<vector<long long>> T(n, vector<long long>(n));
    vector<vector<long long>> F(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        if (s[2 * i] == 'T')
            T[i][i] = 1;
        else
            F[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            for (int k = i; k < j; k++) {
                char op = s[2 * k + 1];

                long long lt = T[i][k];
                long long lf = F[i][k];
                long long rt = T[k + 1][j];
                long long rf = F[k + 1][j];

                if (op == '&') {
                    T[i][j] += lt * rt;
                    F[i][j] += lt * rf + lf

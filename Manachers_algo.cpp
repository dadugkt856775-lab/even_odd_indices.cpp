#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string t = "^";

    for (char c : s) {
        t += "#";
        t += c;
    }

    t += "#$";

    int n = t.size();
    vector<int> p(n, 0);

    int center = 0;
    int right = 0;

    int bestCenter = 0;
    int bestLength = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        if (p[i] > bestLength) {
            bestLength = p[i];
            bestCenter = i;
        }
    }

    int start = (bestCenter - bestLength) / 2;

    cout << "Longest Palindromic Substring: "
         << s.substr(start, bestLength) << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void init_cin() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}

/*
 * Problem Name: Cent Savings
 * Difficulty: 5.1 (Medium)
 * Categories: Dynamic Programming
 * Algorithms: 
 */

int round(int x) {
    return (x + 5) / 10 * 10;
}

int main() {
    init_cin();

    int N, D;
    cin >> N >> D;

    vi p(N);
    rep(i, 0, N) cin >> p[i];

    vector<vector<pii>> dp(N, vector<pii>(D + 1)); // dp[i, d] = {rounded, unrounded} min cost of
                                                   // p[0 -> i] with d dividers (note that rounded
                                                   // min cost is not necessarily round(unrounded))

    rep(d, 1, D + 1) dp[0][d] = pii(round(p[0]), p[0]);
    int sum = 0;
    rep(i, 0, N) dp[i][0] = pii(round((sum += p[i])), sum);

    rep(i, 1, N) rep(d, 1, D + 1) {
        // min(don't use divider, use divider)
        dp[i][d].first = min(round(p[i] + dp[i - 1][d].second),
                             round(p[i] + dp[i - 1][d - 1].first));
        dp[i][d].second = p[i] + min(dp[i - 1][d].second, dp[i - 1][d - 1].first);
    }

    cout << dp[N - 1][D].first << endl;

    return 0;
}

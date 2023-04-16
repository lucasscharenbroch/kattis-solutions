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
 * Problem Name: Anthony and Cora
 * Difficulty: 5.3 (Medium)
 * Categories: Dynamic Programming
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    vector<double> prob(N + M - 1);
    rep(i, 0, N + M - 1) cin >> prob[i];

    // use dp to calculate the probability of each point combination and
    // return the sum of all winning situations

    vector<vector<double>> dp(N + 1, vector<double>(M + 1));
    dp[0][0] = 1;

    rep(i, 0, N) rep(j, 0, M) {
        dp[i + 1][j] += dp[i][j] * (1 - prob[i + j]); // loss
        dp[i][j + 1] += dp[i][j] * prob[i + j]; // win
    }

    double result = 0;
    rep(i, 0, N) result += dp[i][M];

    cout << setprecision(15) << result << endl;

    return 0;
}

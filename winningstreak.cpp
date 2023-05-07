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
 * Problem Name: Winning Streak
 * Difficulty: 6.8 (Hard)
 * Categories: Math, Dynamic Programming
 * Algorithms: 
 */

int main() {
    init_cin();

    while(!(cin >> ws).eof()) {
        int N;
        double W;
        cin >> N >> W;
        double L = 1 - W;

        // dp[i][s] = probability that season of length i has max win-streak of s or less
        vector<vector<double>> dp(N + 1, vector<double>(N + 1));

        vector<double> w_pow(N + 1, 1);
        rep(i, 1, N + 1) w_pow[i] = W * w_pow[i - 1];

        rep(i, 0, N + 1) rep(s, 0, N + 1) {
            if(s >= i) dp[i][s] = 1;
            else if(s + 1 == i) dp[i][s] = 1 - w_pow[i];
            else dp[i][s] = dp[i - 1][s] - dp[i - 2 - s][s] * L * w_pow[s + 1];
        }

        double result = 0;
        rep(i, 1, N + 1) result += i * (dp[N][i] - dp[N][i - 1]);

        cout << setprecision(15) << result << endl;
    }

    return 0;
}

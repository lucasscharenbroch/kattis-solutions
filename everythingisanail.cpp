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
 * Problem Name: Everything Is A Nail
 * Difficulty: 5.9 (Hard)
 * Categories: DP
 * Algorithms: 
 */

int dp[3][3][3][3 * ((int)1e5) + 1]; // dp[a][b][c][i] = max score at index i with state (a, b, c)
constexpr int USED = 0, IN_USE = 1, FREE = 2;

int *dp_at(int shift, int a, int b, int c, int i) {
    if(shift == 0) return &dp[a][b][c][i];
    else if(shift == 1) return &dp[c][a][b][i];
    else if(shift == 2) return &dp[b][c][a][i];
    else assert(false);
}

int main() {
    init_cin();

    memset(dp, 0, sizeof(dp));

    int N;
    cin >> N;

    vi jobs(N + 1);
    rep(i, 1, N + 1) cin >> jobs[i];

    rep(i, 1, N + 1) {
        int sh = jobs[i]; // shift

        rep(j, 0, 3) rep(k, 0, 3) {
            if(j == IN_USE && k == IN_USE) continue;

            *dp_at(sh, USED, j, k, i) = *dp_at(sh, USED, j, k, i - 1);
            *dp_at(sh, FREE, j, k, i) = *dp_at(sh, FREE, j, k, i - 1);

            if(j != IN_USE && k != IN_USE) {
                *dp_at(sh, IN_USE, j, k, i) = max(*dp_at(sh, IN_USE, j, k, i), max(*dp_at(sh, IN_USE, j, k, i - 1), *dp_at(sh, FREE, j, k, i - 1)) + 1);
            } else {
                int jp = j == IN_USE ? USED : j;
                int kp = k == IN_USE ? USED : k;
                *dp_at(sh, IN_USE, jp, kp, i) = max(*dp_at(sh, IN_USE, jp, kp, i), *dp_at(sh, FREE, j, k, i - 1) + 1);
            }
        }
    }

    int result = 0;
    rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) result = max(result, dp[i][j][k][N]);
    cout << result << endl;

    return 0;
}

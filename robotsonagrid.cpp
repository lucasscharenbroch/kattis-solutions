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
 * Problem Name: Robots on a Grid
 * Difficulty: 4.0 (Medium)
 * Categories: Dynamic Programming
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vector<vi> can_walk(N, vi(N));

    rep(i, 0, N) rep(j, 0, N) {
        char c;
        cin >> c;

        if(c == '.') can_walk[i][j] = 1;
    }

    // dp to find number of paths to bottom right

    vector<vector<ll>> dp(N, vector<ll>(N));
    dp[0][0] = 1;

    rep(i, 0, N) rep(j, 0, N) {
        ll up = i == 0 ? 0 : dp[i - 1][j];
        ll left = j == 0 ? 0 : dp[i][j - 1];

        if(can_walk[i][j]) dp[i][j] += up + left;
        dp[i][j] %= INT_MAX;
    }

    if(dp[N - 1][N - 1]) {
        cout << dp[N - 1][N - 1] << endl;
        return 0;
    }

    // bfs to check if there exists a path from top left to bottom right

    queue<pii> q;
    q.push(pii(0, 0));
    can_walk[0][0] = 0; // use can_walk as vis

    while(!q.empty()) {
        auto [r, c] = q.front();
        if(r == N - 1 && c == N - 1) break;
        q.pop();

        for(auto [dr, dc] : vector<pii> {pii(0, 1), pii(1, 0), pii(0, -1), pii(-1, 0)}) {
            dr += r, dc += c;
            if(dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
            if(!can_walk[dr][dc]) continue;
            can_walk[dr][dc] = 0;
            q.push(pii(dr, dc));
        }
    }

    cout << (q.empty() ? "INCONCEIVABLE" : "THE GAME IS A LIE") << endl;

    return 0;
}

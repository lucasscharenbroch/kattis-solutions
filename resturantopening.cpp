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
 * Problem Name: Resturant Opening
 * Difficulty: 1.8 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    vector<vi> grid(N, vi(M));

    rep(i, 0, N) rep(j, 0, M) cin >> grid[i][j];

    int result = INT_MAX;

    rep(i, 0, N) rep(j, 0, M) {
        int cost = 0;
        rep(r, 0, N) rep(c, 0, M) cost += grid[r][c] * (abs(i - r) + abs(j - c));
        result = min(cost, result);
    }

    cout << result << endl;

    return 0;
}

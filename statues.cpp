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
 * Problem Name: Statues
 * Difficulty: 2.3 (Easy)
 * Categories: Greedy
 * Algorithms: 
 */

int try_rot(vector<vi> grid, int num_rot) {
    for(int n = 0; n < num_rot; n++) { // rotate 90 degrees
        vector<vi> new_grid(sz(grid[0]), vi(sz(grid)));
        rep(i, 0, sz(new_grid)) rep(j, 0, sz(grid)) {
            new_grid[i][j] = grid[sz(grid) - 1 - j][i];
        }

        grid = new_grid;
    }

    int n = sz(grid), m = sz(grid[0]);

    vi diag_sz(n + m);
    vector<pii> statues; // (height, diag)

    rep(i, 0, n) rep(j, 0, m) {
        if(grid[i][j] == -1) continue;
        assert(grid[i][j] != 0);

        diag_sz[i + j]++;
        statues.push_back(pii(grid[i][j], i + j));
    }

    sort(all(statues));

    int result = 0;

    int s = 0; // current statue group (iterates forwards)
    int i = -1; // points to the last unused statue after s of equal height
    int jmp = 0; // points to one after the last statue of equal height

    rep(d, 0, sz(diag_sz)) rep(k, 0, diag_sz[d]) {
        if(i < s) {
            i = s;
            while(i + 1 < sz(statues) && statues[i + 1].first == statues[s].first) i++;
            jmp = i + 1;
        }

        if(statues[s].second == d) {
            s++;
        } else {
            i--;
            result++;
            if(i < s) s = jmp;
        }
    }

    return result;
}

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    vector<vi> grid(N, vi(M));

    rep(i, 0, N) rep(j, 0, M) {
        cin >> grid[i][j];
    }

    int result = INT_MAX;

    rep(i, 0, 4) result = min(result, try_rot(grid, i));

    cout << result << endl;

    return 0;
}

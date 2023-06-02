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
 * Problem Name: Muddy Hike
 * Difficulty: 3.4 (Medium)
 * Categories: Graph, Search
 * Algorithms: BFS, Binary Search
 */

// true if there exists a path with less than threshold $mx max cell-value
bool can_reach(vector<vi>& grid, int mx) {
    vector<vi> vis(sz(grid), vi(sz(grid[0])));
    queue<pii> q;
    rep(i, 0, sz(grid)) if(grid[i][0] <= mx) { q.push(pii(i, 0)); vis[i][0] = true; }

    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for(auto [dr, dc] : vector<pii> {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int nr = r + dr, nc = c + dc;
            if(nr < 0 || nr >= sz(grid) || nc < 0 || nc >= sz(grid[r]) ||
                                           vis[nr][nc] || grid[nr][nc] > mx) continue;
            vis[nr][nc] = true;
            q.push(pii(nr, nc));
            if(nc == sz(grid[0]) - 1) return true; // reached the last row
        }
    }

    return false;
}

int main() {
    init_cin();

    int R, C;
    cin >> R >> C;

    vector<vi> grid(R, vi(C));
    rep(i, 0, R) rep(j, 0, C) cin >> grid[i][j];

    int l = 0, r = 1'000'000;
    while(l < r) {
        int m = (l + r) / 2;
        if(can_reach(grid, m)) r = m;
        else l = m + 1;
    }

    cout << l << endl;

    return 0;
}

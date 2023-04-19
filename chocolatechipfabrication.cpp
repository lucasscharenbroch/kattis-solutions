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
 * Problem Name: Chocolate Chip Fabrication
 * Difficulty: 6.3 (Hard)
 * Categories: Graph
 * Algorithms: Breadth First Search
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    vector<vector<char>> grid(N, vector<char>(M));

    rep(i, 0, N) rep(j, 0, M) cin >> grid[i][j];

    queue<pii> q;

    // add cookie cells that aren't completely surrounded into q
    rep(i, 0, N) rep(j, 0, M) {
        if(grid[i][j] == '-') continue;
        for(auto [dr, dc] : vector<pii> {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            int r = i + dr, c = j + dc;
            if(r < 0 || r >= N || c < 0 || c >= M || grid[r][c] == '-') {
                q.push(pii(i, j));
                grid[i][j] = 'C';
                break;
            }
        }
    }

    // count breadths explored
    int breadth = 0;

    while(!q.empty()) {
        breadth++;
        int n = sz(q);

        while(n--) {
            auto [r, c] = q.front(); q.pop();
            for(auto [dr, dc] : vector<pii> {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int nr = r + dr, nc = c + dc;
                if(nr < 0 || nr >= N || nc < 0 || nc >= M ||
                   grid[nr][nc] == '-' || grid[nr][nc] == 'C') continue;
                grid[nr][nc] = 'C';
                q.push(pii(nr, nc));
            }
        }
    }

    cout << breadth << endl;

    return 0;
}

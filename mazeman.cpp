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
 * Problem Name: MazeMan
 * Difficulty: 4.1 (Medium)
 * Categories: Graph
 * Algorithms: BFS
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M >> ws;

    vector<vector<char>> grid(N, vector<char>(M));
    vector<pii> entrances;
    int total_dots = 0;

    rep(i, 0, N) {
        string S;
        getline(cin, S);
        rep(j, 0, M) {
            grid[i][j] = S[j];
            if(grid[i][j] == '.') total_dots++;
            if(grid[i][j] >= 'A' && grid[i][j] <= 'W') entrances.push_back(pii(i, j));
        }
    }

    int min_entrances = 0;

    for(auto [er, ec] : entrances) {
        int dots_reachable = 0;
        queue<pii> q;
        vector<vector<bool>> vis(N, vector<bool>(M));
        q.push(pii(er, ec));
        vis[er][ec] = true;

        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if(grid[r][c] == '.') {
                if(!dots_reachable++) min_entrances++;
                grid[r][c] = ' ';
            }

            for(auto [dr, dc] : vector<pii> {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                int nr = dr + r, nc = dc + c;
                if(nr < 0 || nr >= N || nc < 0 || nc >= M || vis[nr][nc] ||
                   !(grid[nr][nc] == ' ' || grid[nr][nc] == '.')) continue;

                q.push(pii(nr, nc));
                vis[nr][nc] = true;
            }
        }

        total_dots -= dots_reachable;
    }

    cout << min_entrances << " " << total_dots << endl;

    return 0;
}

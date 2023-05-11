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
 * Problem Name: Lone Rook
 * Difficulty: 7.2 (Hard)
 * Categories: Graph, Search
 * Algorithms: Topological Sort, DFS
 */

int R, C;
constexpr int UNREACHABLE = 0, REACHABLE_BLOCKED = 1, REACHABLE = 2;
bool can_reach_t = false;
queue<pii> reachable_knights; // coords of knights with indegree 0

void explore(vector<string>& grid, vector<vi>& status, vector<vi>& indegree, int r, int c, pii direction) {
    if(r < 0 || r >= R || c < 0 || c >= C) return; // cell out of range
    if(status[r][c] == REACHABLE) return; // already visited

    if(grid[r][c] == 'T' && !indegree[r][c]) {
        can_reach_t = true;
    } else if(grid[r][c] == 'K') {
        if(status[r][c] != REACHABLE_BLOCKED && !indegree[r][c]) reachable_knights.push(pii(r, c));
        status[r][c] = REACHABLE_BLOCKED;
    } else if(indegree[r][c]) {
        status[r][c] = REACHABLE_BLOCKED;
        explore(grid, status, indegree, r + direction.first, c + direction.second, direction);
    } else {
        status[r][c] = REACHABLE;

        // explore in all 4 directions
        explore(grid, status, indegree, r + 1, c, pii(1, 0));
        explore(grid, status, indegree, r - 1, c, pii(-1, 0));
        explore(grid, status, indegree, r, c + 1, pii(0, 1));
        explore(grid, status, indegree, r, c - 1, pii(0, -1));
    }
}

int main() {
    init_cin();

    cin >> R >> C >> ws;

    vector<string> grid(R);
    rep(i, 0, R) getline(cin, grid[i]);

    const vector<pii> knight_moves = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
    vector<vi> status(R, vi(C, UNREACHABLE));
    vector<vi> indegree(R, vi(C)); // number of remaining knights that can move to cell (i, j)

    int start_r, start_c;

    rep(i, 0, R) rep(j, 0, C) {
        if(grid[i][j] == 'R') start_r = i, start_c = j;
        else if(grid[i][j] == 'K') {
            for(auto [dr, dc] : knight_moves) {
                int r = i + dr, c = j + dc;
                if(r < 0 || r >= R || c < 0 || c >= C) continue;
                indegree[r][c]++;
            }
        }
    }

    explore(grid, status, indegree, start_r, start_c, pii(0, 0)); // explore from start node

    // repeatedly remove reachable knights with indegree 0
    while(!reachable_knights.empty()) {
        auto [kr, kc] = reachable_knights.front(); reachable_knights.pop();

        // remove this knight from knights, grid, and indegrees; explore
        // from knight's position and any new (indegree = 0) positions
        grid[kr][kc] = '.';
        for(auto [dr, dc] : knight_moves) {
            int r = kr + dr, c = kc + dc;
            if(r < 0 || r >= R || c < 0 || c >= C) continue;
            indegree[r][c]--;
            if(!indegree[r][c] && status[r][c] == REACHABLE_BLOCKED) {
                explore(grid, status, indegree, r, c, pii(0, 0));
                if(grid[r][c] == 'K') reachable_knights.push(pii(r, c));
            }
        }

        explore(grid, status, indegree, kr, kc, pii(0, 0));
        if(can_reach_t) break;
    }

    if(can_reach_t) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}

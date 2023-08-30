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
 * Problem Name: Stable Table
 * Difficulty: 4.8 (Medium)
 * Categories: Graph Search
 * Algorithms: BFS
 */

vector<unordered_set<int>> cnx(10'000);

int bfs_to_set(vector<vi>& grid, unordered_set<int> target_set, int start) {
    queue<int> q;
    vi vis(10'000);
    int breadth = 0;

    q.push(start);
    vis[start] = true;

    while(sz(q)) {
        int n = sz(q);
        breadth++;

        while(n--) {
            int curr = q.front(); q.pop();
            if(target_set.find(curr) != target_set.end()) return breadth;

            for(int child : cnx[curr]) {
                if(!vis[child]) q.push(child);
                vis[child] = true;
            }
        }
    }

    return -1;
}

int main() {
    init_cin();

    int R, C;
    cin >> R >> C;

    vector<vi> grid(R, vi(C));

    int num_pieces = 0;

    rep(i, 0, R) rep(j, 0, C) {
        cin >> grid[i][j];
        num_pieces = max(num_pieces, grid[i][j]);
    }

    unordered_set<int> tops, bottoms;

    rep(i, 0, C) {
        tops.insert(grid[0][i]);
        bottoms.insert(grid[R - 1][i]);
    }

    // form a directed graph
    rep(i, 0, R - 1) rep(j, 0, C) {
        if(grid[i][j] != grid[i + 1][j])
            cnx[grid[i][j]].insert(grid[i + 1][j]);
    }

    int result = INT_MAX;

    if(sz(tops) == 1) {
        // find shortest path from the top piece to any bottom
        int dist = bfs_to_set(grid, bottoms, grid[0][0]);
        result = dist;
    } else {
        // two cases:
        // (1) two completely disjoint paths from tops to bottom
        int net_dist = 0;
        for(int top : tops) {
            int d = bfs_to_set(grid, bottoms, top);
            net_dist += d;
        }

        result = min(result, net_dist);

        // (2) the paths join at some common node
        for(int cn = 1; cn <= num_pieces; cn++) { // for each possible common node
                                                  // (including the tops themselves)
            int cn_dist_to_bot = bfs_to_set(grid, bottoms, cn);
            unordered_set<int> cn_set = {cn};

            int net_dist = 0;

            for(int top : tops) {
                int d = bfs_to_set(grid, cn_set, top);
                if(d == -1) goto skip;
                net_dist += d;
            }

            result = min(result, net_dist - 2 + cn_dist_to_bot);
            skip:;
        }
    }

    cout << result << endl;
    return 0;
}

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
 * Problem Name: Gregory The Grasshopper
 * Difficulty: 3.8 (Medium)
 * Categories: Graph
 * Algorithms: Dijkstra's
 */

int main() {
    init_cin();

    while(!(cin >> ws).eof()) {
        int R, C, sr, sc, tr, tc;
        cin >> R >> C >> sr >> sc >> tr >> tc;
        sr--, sc--, tr--, tc--; // adjust to 0-indexing

        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
        vector<vi> dist(R, vi(C, INT_MAX));

        q.push(pair<int, pii>(0, pii(sr, sc)));
        dist[sr][sc] = 0;

        while(!q.empty()) {
            auto [cost, curr] = q.top(); q.pop();
            if(dist[curr.first][curr.second] != cost) continue;

            if(curr.first == tr && curr.second == tc) {
                cout << cost << endl;
                goto next_testcase;
            }

            for(auto[dr, dc] : vector<pii>({{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}})) {
                int r = curr.first + dr, c = curr.second + dc;
                if(r < 0 || r >= R || c < 0 || c >= C) continue;
                if(dist[r][c] > cost + 1) q.push(pair<int, pii>(cost + 1, pii(r, c)));
                dist[r][c] = min(dist[r][c], cost + 1);
            }
        }

        cout << "impossible" << endl;
        next_testcase:;
    }

    return 0;
}

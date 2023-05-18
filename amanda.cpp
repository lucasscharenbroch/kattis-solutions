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
 * Problem Name: Amanda Lounges
 * Difficulty: 5.7 (Hard)
 * Categories: Graph
 * Algorithms: 
 */

int result = 0;
bool impossible = false;

void force_status(vector<vector<pii>>& cnx, vi& vis, int curr, int status) {
    vis[curr] = status + 1;
    result += status;

    for(auto [neigh, weight] : cnx[curr]) {
        if(vis[neigh]) {
            if(status + vis[neigh] - 1 != weight) goto impossible;
        } else {
            if(weight == 0) {
                if(status) goto impossible;                  // 1 ---0---> X
                else force_status(cnx, vis, neigh, 0);       // 0 ---0---> 0
            } else if(weight == 1) {
                force_status(cnx, vis, neigh, !status);      // 1 ---1---> 0
                                                             // 0 ---1---> 1
            } else { // weight == 2
                if(status) force_status(cnx, vis, neigh, 1); // 1 ---2---> 1
                else goto impossible;                        // 0 ---2---> X
            }
        }
    }

    return;
    impossible: impossible = true;
}

void bipartite_explore(vector<vector<pii>>& cnx, vi& vis, int curr, int g, int& g0, int& g1) {
    vis[curr] = g + 1;
    if(g) g1++; else g0++;

    for(auto [neigh, weight] : cnx[curr]) {
        if(vis[neigh]) {
            if(g + 1 == vis[neigh]) goto impossible;
        } else bipartite_explore(cnx, vis, neigh, !g, g0, g1);
    }

    return;
    impossible: impossible = true;
}

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    vector<vector<pii>> cnx(N);

    rep(i, 0, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        cnx[a].push_back(pii(b, c));
        cnx[b].push_back(pii(a, c));
    }

    vi vis(N);

    // explore any components with 0-weight or 2-weight edges
    rep(i, 0, N) {
        if(vis[i]) continue;
        rep(j, 0, sz(cnx[i])) {
            if(cnx[i][j].second == 1) continue;
            if(cnx[i][j].second == 0) force_status(cnx, vis, i, 0);
            else force_status(cnx, vis, i, 1);
            break;
        }
    }

    // explore any remaining components with only 1-weight edges
    // in order to be valid, these components must be bipartite
    // the vertex-group with minimal cardinality can be assigned status 1
    rep(i, 0, N) {
        if(vis[i]) continue;

        int g0 = 0, g1 = 0; // cardinality of each group

        bipartite_explore(cnx, vis, i, 0, g0, g1);
        result += min(g0, g1);
    }

    if(impossible) cout << "impossible" << endl;
    else cout << result << endl;

    return 0;
}

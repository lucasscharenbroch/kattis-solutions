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
 * Problem Name: Eulerian Path
 * Difficulty: 5.6 (Hard)
 * Categories: Graph
 * Algorithms: Eulerian Path
 */

void find_path(int curr, vector<vi>& cnx, vi& cnx_pos, vi& path) {
    while(cnx_pos[curr] < sz(cnx[curr])) {
        find_path(cnx[curr][cnx_pos[curr]++], cnx, cnx_pos, path);
    }
    path.push_back(curr);
}

int main() {
    init_cin();

    while(true) {
        int N, M;
        cin >> N >> M;
        if(N == 0) break;

        vector<vi> cnx(N);
        vi indegrees(N), outdegrees(N);
        vi path;
        vi cnx_pos(N); // cnx_pos[i] = position in cnx[i]
        int s = -1, t = -1;

        rep(i, 0, M) {
            int u, v;
            cin >> u >> v;
            cnx[u].push_back(v);
            indegrees[v]++, outdegrees[u]++;
        }

        // ensure that an eulerian path exists; find s and t if applicable
        rep(i, 0, N) {
            if(indegrees[i] - outdegrees[i] == 0);
            else if(indegrees[i] - outdegrees[i] == 1) {
                if(t != -1) goto impossible;
                t = i;
            } else if(indegrees[i] - outdegrees[i] == -1) {
                if(s != -1) goto impossible;
                s = i;
            } else goto impossible;
        }

        // in the case where s == -1, find a node with nonzero degree to find the cycle from
        if(s == -1)
        rep(i, 0, M) if(outdegrees[i]) { s = i; break; }

        find_path(s, cnx, cnx_pos, path);

        if(sz(path) != M + 1) goto impossible; // nodes with edges aren't connected
        for(int i = sz(path); i --> 0;) cout << path[i] << (i == 0 ? "\n" : " ");

        continue;
        impossible:
        cout << "Impossible" << endl;
    }

    return 0;
}

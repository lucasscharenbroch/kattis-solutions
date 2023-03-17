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
 * Problem Name: Curveknights
 * Difficulty: 3.0 (Medium)
 * Categories: Graph
 * Algorithms: Topological Sort
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    vector<ll> amounts(N);

    rep(i, 0, N) cin >> amounts[i];

    // do a topological sort over the reversed graph, multiplying the edge
    // weights by the number associated with the dependent node, and adding
    // that value to the ingredient's node.

    vi indegrees(N, 0);
    vector<vector<pii>> cnx(N); // "reversed" graph (results point to ingredients)

    rep(i, 0, M) {
        int u, v, w;
        cin >> u >> v >> w;
        cnx[v].push_back(pii(u, w));
        indegrees[u]++;
    }

    queue<int> q;
    rep(i, 0, N) if(indegrees[i] == 0) q.push(i);

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(pii& edge : cnx[curr]) {
            int u = edge.first, w = edge.second;
            amounts[u] += amounts[curr] * w;
            indegrees[u]--;
            if(indegrees[u] == 0) q.push(u);
        }
    }

    rep(i, 0, N) cout << amounts[i] << (i == N - 1 ? "" :  " ");
    cout << endl;

    return 0;
}

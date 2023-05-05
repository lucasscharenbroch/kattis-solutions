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
 * Problem Name: A Walk Through The Forest
 * Difficulty: 3.7 (Medium)
 * Categories: Graph, Dynamic Programming
 * Algorithms: Dijkstra's, Bellman-Ford
 */

int main() {
    init_cin();

    while(true) {
        int N, M;
        cin >> N;
        if(!N) return 0;
        cin >> M;

        vector<vector<pii>> cnx(N);

        rep(i, 0, M) {
            int a, b, w;
            cin >> a >> b >> w;
            a--, b--;
            cnx[a].push_back(pii(b, w));
            cnx[b].push_back(pii(a, w));
        }

        // use Dijkstra's to calculate shortest path from t to each node
        vi dist(N, INT_MAX);
        int s = 0, t = 1;
        dist[t] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push(pii(t, 0));

        while(!q.empty()) {
            auto [curr, d] = q.top(); q.pop();
            if(d != dist[curr]) continue;

            for(auto& [neigh, dn] : cnx[curr]) {
                if(dist[neigh] <= d + dn) continue;
                dist[neigh] = d + dn;
                q.push(pii(neigh, d + dn));
            }
        }

        // remove all non-direct edges from cnx
        rep(i, 0, N) {
            vector<pii> new_cnx;
            for(pii& edge : cnx[i]) {
                if(dist[edge.first] < dist[i]) new_cnx.push_back(edge);
            }
            cnx[i] = new_cnx;
        }

        // use modified Bellman-Ford to count the number of direct paths
        int result = 0;
        vector<vi> dp(N, vi(N + 1)); // dp[v][i] = number of direct paths from v to t
        dp[t][0] = 1;                // with exactly i steps

        rep(i, 1, N + 1) rep(v, 0, N) {
            for(auto& [neigh, d] : cnx[v]) {
                dp[v][i] += dp[neigh][i - 1];
            }
            if(v == s) result += dp[v][i];
        }

        cout << result << endl;
    }

    return 0;
}

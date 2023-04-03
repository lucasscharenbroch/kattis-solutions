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
 * Problem Name: Arachnophobia
 * Difficulty: 5.0 (Medium)
 * Categories: Graph, Search
 * Algorithms: Dijkstra's, Binary Search
 */

// returns true if there exists a path from s to t with <= T weight
// and >= D maximum distance from a spider
bool can_reach(vector<vector<pii>>& cnx, vi& dist_from_spider, int s, int t, int T, int D) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<bool> vis(sz(cnx));
    q.push(pii(0, s));

    while(!q.empty()) {
        auto [dist, curr] = q.top(); q.pop();
        if(dist > T) break;
        if(curr == t) return true;

        for(auto& [neigh, d] : cnx[curr]) {
            if(vis[neigh] || dist_from_spider[neigh] < D) continue;
            vis[neigh] = true;
            q.push(pii(dist + d, neigh));
        }
    }

    return false;
}

int main() {
    init_cin();

    int N, M, T;
    cin >> N >> M >> T;

    vector<vector<pii>> cnx(N);

    rep(i, 0, M) {
        int u, v, d;
        cin >> u >> v >> d;

        cnx[u].push_back(pii(v, d));
        cnx[v].push_back(pii(u, d));
    }

    int s, t;
    cin >> s >> t;

    int K;
    cin >> K;

    vi dist_from_spider(N, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> q;

    rep(i, 0, K) {
        int a;
        cin >> a;
        q.push(pii(0, a));
    }

    // dijkstra's from spiders to determine dist_from_spider for all nodes
    while(!q.empty()) {
        auto [dist, curr] = q.top(); q.pop();
        if(dist_from_spider[curr] != INT_MAX) continue;
        dist_from_spider[curr] = dist;

        for(auto& [neigh, d] : cnx[curr]) {
            if(dist_from_spider[neigh] != INT_MAX) continue;
            q.push(pii(dist + d, neigh));
        }
    }

    // binary search the answer

    int low = 0, high = dist_from_spider[s];

    while(low < high) {
        int mid = (low + high + 1) / 2;
        if(can_reach(cnx, dist_from_spider, s, t, T, mid)) low = mid;
        else high = mid - 1;
    }

    cout << low << endl;

    return 0;
}

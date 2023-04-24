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
 * Problem Name: Detour
 * Difficulty: 4.9 (Medium)
 * Categories: Graph
 * Algorithms: Dijkstra's
 */

vi result;

bool dfs(int curr, int t, vector<vector<pii>>& cnx, vi& parent, vi& vis) {
    if(curr == t) {
        result.push_back(t);
        return true;
    }

    for(auto& [neigh, weight] : cnx[curr]) {
        if(vis[neigh] || parent[curr] == neigh) continue;
        vis[neigh] = true;
        if(dfs(neigh, t, cnx, parent, vis)) {
            result.push_back(curr);
            return true;
        }
    }

    return false;
}

int main() {
    init_cin();

    ll N, M;
    cin >> N >> M;
    int s = 0, t = 1;

    vector<vector<pii>> cnx(N);

    rep(i, 0, M) {
        int a, b, w;
        cin >> a >> b >> w;
        cnx[a].push_back(pii(b, w));
        cnx[b].push_back(pii(a, w));
    }

    // use dijkstra's from t to form parent array
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push(pair<ll, int>(0LL, t));
    vector<ll> dist(N, LLONG_MAX);
    dist[t] = 0;
    vi parent(N, -1);

    while(!q.empty()) {
        auto [cost, curr] = q.top(); q.pop();
        if(cost > dist[curr]) continue;

        for(auto& [n, w] : cnx[curr]) {
            if(cost + w >= dist[n]) continue;
            q.push(pair<ll, int>(cost + w, n));
            dist[n] = cost + w;
            parent[n] = curr;
        }
    }

    vi vis(N);
    vis[s] = true;

    // dfs from s without using edges in the parent array
    if(!dfs(s, t, cnx, parent, vis)) {
        cout << "impossible" << endl;
        return 0;
    }

    reverse(all(result));

    cout << sz(result) << " ";

    rep(i, 0, sz(result)) cout << result[i] << (i == sz(result) - 1 ? "\n" : " ");

    return 0;
}

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
 * Problem Name: Water
 * Difficulty: 3.6 (Medium)
 * Categories: Network Flow
 * Algorithms: Dinic's
 */

vector<pii> edges; // = {{to, net-capacity}}
vi cnx[101]; // cnx[from] = {indices-in-edges}
int level[101]; // level in level graph
int vis[101];
int vis_id = 1;
int max_flow = 0;
int N;
int s = 0, t = 1;

// fills level with the "level" of each node, return false if t is not reached
bool bfs() {
    queue<int> q;
    q.push(s);
    vis[s] = ++vis_id;
    int l = 0; // current level

    while(!q.empty()) {
        l++;
        int n = q.size();

        while(n--) {
            int curr = q.front(); q.pop();
            level[curr] = l;
            if(curr == t) return true;

            for(int& edge_id : cnx[curr]) {
                int neigh = edges[edge_id].first, edge_cap = edges[edge_id].second;
                if(!edge_cap || vis[neigh] == vis_id) continue;
                vis[neigh] = vis_id;
                q.push(neigh);
            }
        }
    }

    return false;
}

int dfs(int curr, int flow_in) {
    if(curr == t) { max_flow += flow_in; return flow_in; }
    if(curr == s) vis[s] = ++vis_id;

    for(int& edge_id : cnx[curr]) {
        int neigh = edges[edge_id].first, edge_cap = edges[edge_id].second;

        if(level[neigh] != level[curr] + 1 || vis[neigh] == vis_id) continue;
        if(edge_cap == 0) continue;
        vis[neigh] = vis_id;

        int f;
        if(f = dfs(neigh, min(flow_in, edge_cap))) {
            edges[edge_id].second -= f;
            edges[edge_id ^ 1].second += f; // increase net-capacity of opposite-direction edge
            return f;
        } else level[neigh] = -1; // pruin dead-ends
    }

    return 0;
}

int calc_max_flow() {
    while(bfs()) while(dfs(s, INT_MAX));
    return max_flow;
}

int main() {
    init_cin();

    int P, K;
    cin >> N >> P >> K;

    int max_flow = 0;

    // create edges, and add them to cnx
    rep(i, 0, P) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        // each edge's residual complement is adjacent to it in the edge array,
        // so edges[i ^ 1] is the residual/normal edge corresponding to edges[i].
        cnx[a].push_back(edges.size());
        edges.push_back(pii(b, c));
        cnx[b].push_back(edges.size());
        edges.push_back(pii(a, c));
    }

    cout << calc_max_flow() << endl;
    rep(i, 0, K) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        cnx[a].push_back(edges.size());
        edges.push_back(pii(b, c));
        cnx[b].push_back(edges.size());
        edges.push_back(pii(a, c));

        cout << calc_max_flow() << endl;
    }

    return 0;
}

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
 * Problem Name: Maximum Flow
 * Difficulty: 4.7 (Medium)
 * Categories: Network Flow
 * Algorithms: Dinic's
 */

struct edge {
    int from, to, flow, cap;
    edge(int from, int to, int cap): from(from), to(to), flow(0), cap(cap) { }
};

vector<edge> edges;
vector<vi> cnx;
vi vis;
vi level;
int vis_id = 1;
int s, t;

void add_edge(int from, int to, int cap) {
    cnx[from].push_back(sz(edges));
    edges.push_back(edge(from, to, cap));
    cnx[to].push_back(sz(edges));
    edges.push_back(edge(to, from, 0));
}

bool bfs() {
    queue<int> q;
    q.push(s);
    vis[s] = ++vis_id;
    int l = 0;

    while(!q.empty()) {
        int n = sz(q);
        l++;

        while(n--) {
            int curr = q.front(); q.pop();
            level[curr] = l;
            if(curr == t) return true;

            for(int edge_id : cnx[curr]) {
                int neigh = edges[edge_id].to, edge_cap = edges[edge_id].cap - edges[edge_id].flow;
                if(vis[neigh] == vis_id || !edge_cap) continue;
                vis[neigh] = vis_id;
                q.push(neigh);
            }
        }
    }

    return false;
}

int dfs(int curr, int flow_in) {
    if(curr == t) return flow_in;

    for(int edge_id : cnx[curr]) {
        int neigh = edges[edge_id].to, edge_cap = edges[edge_id].cap - edges[edge_id].flow;
        if(!edge_cap || level[curr] + 1 != level[neigh]) continue;

        int f;
        if(f = dfs(neigh, min(flow_in, edge_cap))) {
            edges[edge_id].flow += f, edges[edge_id ^ 1].flow -= f;
            return f;
        } else level[neigh] = -1;
    }

    return 0;
}

int max_flow() {
    int max_flow = 0;

    while(bfs()) {
        int f;
        while(f = dfs(s, INT_MAX)) max_flow += f;
    }

    return max_flow;
}

int main() {
    init_cin();

    int N, M;
    cin >> N >> M >> s >> t;

    edges.clear();
    cnx.assign(N, vi());
    vis.assign(N, 0);
    level.assign(N, 0);

    rep(i, 0, M) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }

    int f = max_flow();
    int used_edges = 0;

    rep(i, 0, sz(edges)) if(edges[i].cap && edges[i].flow) used_edges++;

    cout << N << " " << f << " " << used_edges << endl;

    rep(i, 0, sz(edges)) {
        if(!edges[i].cap || !edges[i].flow) continue;
        cout << edges[i].from << " " << edges[i].to << " " << edges[i].flow << endl;
    }

    return 0;
}

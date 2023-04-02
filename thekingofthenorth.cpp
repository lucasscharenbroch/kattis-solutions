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
 * Problem Name: The King of The North
 * Difficulty: 4.5 (Medium)
 * Categories: Network Flow
 * Algorithms: Dinic's
 */

struct edge {
    int from, to, flow, cap;
    edge(int from, int to, int flow, int cap) : from(from), to(to), flow(flow), cap(cap) { }
};

int MAX_N = 300 * 300 * 2 + 1;

vector<edge> edges;
vector<vi> cnx(MAX_N);
vi vis(MAX_N), level(MAX_N);
int vis_id = 1;
int s, t;

void add_edge(int from, int to, int cap) {
    cnx[from].push_back(sz(edges));
    edges.push_back(edge(from, to, 0, cap));
    cnx[to].push_back(sz(edges));
    edges.push_back(edge(to, from, 0, 0));
}

bool bfs() {
    queue<int> q;
    vis[s] = ++vis_id;
    q.push(s);
    int l = 0;

    while(!q.empty()) {
        int n = q.size();
        l++;

        while(n--) {
            int curr = q.front(); q.pop();
            level[curr] = l;
            if(curr == t) return true;

            for(int& edge_id : cnx[curr]) {
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

    for(int& edge_id : cnx[curr]) {
        int neigh = edges[edge_id].to, edge_cap = edges[edge_id].cap - edges[edge_id].flow;
        if(!edge_cap || level[curr] + 1 != level[neigh]) continue;

        int f;
        if(f = dfs(neigh, min(flow_in, edge_cap))) {
            edges[edge_id].flow += f; edges[edge_id ^ 1].flow -= f;
            return f;
        } else level[neigh] = -1;
    }

    return 0;
}

int calc_max_flow() {
    int max_flow = 0;

    while(bfs()) {
        int f;
        while(f = dfs(s, INT_MAX)) max_flow += f;
    }

    return max_flow;
}

int main() {
    init_cin();

    int R, C;
    cin >> R >> C;

    // read weights, and add edges between neighboring nodes
    rep(i, 0, R) rep(j, 0, C) {
        int weight;
        cin >> weight;

        // add a dummy node to bottleneck the capacity of a the node
        add_edge(i * C + j, i * C + (R * C) + j, weight);

        // add edges from dummy node to neighboring nodes
        for(auto& [dr, dc] : vector<pii> {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            int r = i + dr, c = j + dc;
            if(r < 0 || r >= R || c < 0 || c >= C) continue;
            add_edge(i * C + (R * C) + j, r * C + c, INT_MAX);
        }
    }

    int tr, tc;
    cin >> tr >> tc;
    t = tr * C + (R * C) + tc;

    // add edges from s to borders
    s = R * C * 2;
    rep(i, 0, R) {
        add_edge(s, i * C + 0, INT_MAX);
        add_edge(s, i * C + (C - 1), INT_MAX);
    }

    rep(j, 0, C) {
        add_edge(s, 0 * C + j, INT_MAX);
        add_edge(s, (R - 1) * C + j, INT_MAX);
    }


    cout << calc_max_flow() << endl;

    // for(int i = 0; i < sz(edges); i += 2) cout << i << " (" << (edges[i].to / C) << " " << (edges[i].to % C) << ") " << edges[i].flow << " / " << edges[i].cap << endl;

    return 0;
}

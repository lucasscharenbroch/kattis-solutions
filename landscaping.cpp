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
 * Problem Name: Landscaping
 * Difficulty: 4.6 (Medium)
 * Categories: Network Flow
 * Algorithms: Dinic's
 */

struct edge {
    int from, to, flow, cap;
    edge(int from, int to, int flow, int cap) : from(from), to(to), flow(flow), cap(cap) { }
};


int MAX_N = 50 * 50 + 2;

vector<edge> edges;
vector<vi> cnx(MAX_N);
vi level(MAX_N);
vi vis(MAX_N);
int vis_id = 1;
int s, t;

void add_edge(int from, int to, int cap) {
    cnx[from].push_back(edges.size());
    edges.push_back(edge(from, to, 0, cap));
    cnx[to].push_back(edges.size());
    edges.push_back(edge(to, from, 0, 0));
}

bool bfs() {
    queue<int> q;
    q.push(s);
    vis[s] = ++vis_id;
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
            edges[edge_id].flow += f, edges[edge_id ^ 1].flow -= f;
            return f;
        } else level[neigh] = -1;
    }

    return 0;
}

int calc_max_flow() {
    int flow = 0;

    while(bfs()) {
        int f;
        while(f = dfs(s, INT_MAX)) flow += f;
    }

    return flow;
}

int main() {
    init_cin();

    // add edge between each neighboring cell of weight A
    // add edge between s and each cell of low elevation of weight B
    // add edge between each cell with high elevation and t with weibht B
    // find min cut on the network, which is equal to the minimum price

    int R, C, A, B;
    cin >> R >> C >> A >> B;

    s = R * C, t = s + 1;

    rep(i, 0, R) rep(j, 0, C) {
        char c; cin >> c;
        if(c == '.') add_edge(s, i * C + j, B);
        else add_edge(i * C + j, t, B);

        // add edge of weight A to all neighboring cells
        for(auto& [ox, oy] : vector<pii> {{-1, 0}, {0, 1}, {0, -1}, {1, 0}}) {
            int nr = i + ox, nc = j + oy;
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            add_edge(i * C + j, nr * C + nc, A);
        }
    }

    cout << calc_max_flow() << endl;

    return 0;
}

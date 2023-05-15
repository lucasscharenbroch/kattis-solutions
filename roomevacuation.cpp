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
 * Problem Name: Room Evacuation
 * Difficulty: 6.9 (Hard)
 * Categories: Network Flow
 * Algorithms: Dinic's
 */

struct edge {
    int to, from, flow, cap;
    edge(int from, int to, int flow, int cap) : from(from), to(to), flow(flow), cap(cap) { }
};

int MAX_N = 20 * 20 * 201 + 2;

vector<edge> edges;
vector<vector<int>> cnx(MAX_N);
vector<int> vis(MAX_N);
vector<int> level(MAX_N);
int vis_id = 1;
int s = MAX_N - 2, t = MAX_N - 1;

void add_edge(int from, int to, int cap) {
    cnx[from].push_back(sz(edges));
    edges.push_back(edge(from, to, 0, cap));
    cnx[to].push_back(sz(edges));
    edges.push_back(edge(to, from, 0, 0));
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

            for(int& edge_id : cnx[curr]) {
                int neigh = edges[edge_id].to, edge_cap = edges[edge_id].cap - edges[edge_id].flow;
                if(!edge_cap || vis[neigh] == vis_id) continue;
                q.push(neigh);
                vis[neigh] = vis_id;
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
    int flow = 0;

    while(bfs()) {
        int f;
        while(f = dfs(s, INT_MAX)) flow += f;
    }

    return flow;
}

int main() {
    init_cin();

    int N, M, T;
    cin >> N >> M >> T;

    vector<string> grid(N);
    rep(i, 0, N) cin >> grid[i];

    // add edges to network
    rep(i, 0, N) rep(j, 0, M) rep(k, 0, T + 1) {
        if(grid[i][j] == '#') continue;
        if(grid[i][j] == 'P' && k == 0) add_edge(s, k * M * N + i * M + j, 1);

        if(grid[i][j] == 'E') add_edge(k * M * N + i * M + j, t, 1);
        else if(k != T) { // add edges to neighbors in next layer
            for(auto [dr, dc] : vector<pii> {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int nr = i + dr, nc = j + dc;
                if(nr < 0 || nr >= N || nc < 0 || nc >= M || grid[nr][nc] == '#') continue;
                add_edge(k * M * N + i * M + j, (k + 1) * M * N + nr * M + nc, 1);
            }
        }
    }

    cout << calc_max_flow() << endl;

    return 0;
}

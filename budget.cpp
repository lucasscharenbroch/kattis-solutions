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
 * Problem Name: Budget
 * Difficulty: 7.1 (Hard)
 * Categories: Network Flow
 * Algorithms: Dinic's
 */

struct edge {
    int flow, cap, to;
    edge(int fl, int c, int t) : flow(fl), cap(c), to(t) { }
    edge() {}
};

constexpr int MAX_R = 200, MAX_C = 20;
constexpr int MAX_NODES = MAX_R * MAX_C * 4;

edge edges[MAX_NODES * 4];
int num_edges = 0;
int cnx[MAX_NODES][MAX_NODES];
int cnx_sz[MAX_NODES];
int high[MAX_R][MAX_C], low[MAX_R][MAX_C]; // upper/lower bounds on cells
int row_sums[MAX_R], col_sums[MAX_R];
int s, t; // node-id of source and sink

void add_edge(int flow, int cap, int from, int to) {
    cnx[from][cnx_sz[from]++] = num_edges;
    edges[num_edges++] = edge(flow, cap, to);
    cnx[to][cnx_sz[to]++] = num_edges;
    edges[num_edges++] = edge(0, 0, from);
}

int vis[MAX_NODES] = {0};
int vis_id = 1;
int level[MAX_NODES];

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
            rep(i, 0, cnx_sz[curr]) {
                int edge_id = cnx[curr][i];
                int neigh = edges[edge_id].to, edge_cap = edges[edge_id].cap - edges[edge_id].flow;
                if(vis[neigh] == vis_id || !edge_cap) continue;
                q.push(neigh);
                vis[neigh] = vis_id;
            }
        }

    }

    return false;
}

int dfs(int curr, int flow) {
    if(curr == s) vis[s] = ++vis_id;
    else if(curr == t) return flow;

    rep(i, 0, cnx_sz[curr]) {
        int edge_id = cnx[curr][i];
        int neigh = edges[edge_id].to, edge_cap = edges[edge_id].cap - edges[edge_id].flow;
        if(vis[neigh] == vis_id || !edge_cap || level[curr] + 1 != level[neigh]) continue;

        int f;
        if((f = dfs(neigh, min(flow, edge_cap)))) {
            edges[edge_id].flow += f;
            edges[edge_id ^ 1].flow -= f;
            return f;
        } else level[neigh] = -1;
    }

    return 0;
}

int calc_max_flow() {
    int mx_fl = 0;
    while(bfs()) {
        int fl;
        while(fl = dfs(s, INT_MAX)) mx_fl += fl;
    }
    return mx_fl;
}

void solve() {
    num_edges = 0;
    memset(cnx_sz, 0, sizeof(cnx_sz));
    memset(low, 0, sizeof(low));
    memset(high, 0x3f, sizeof(high));
    int max_flow;

    int R, C;
    cin >> R >> C;

    // node-ids:
    // cells: 0 -> R*C - 1, where id(r, c) = r * C + c
    // rows: R*C -> R*C + R - 1
    // cols: R*C + R -> R*C + R + C - 1
    // s: R*C + R + C, t: R*C + R + C +1
    s = R * C + R + C, t = s + 1;

    rep(i, 0, R) cin >> row_sums[i];
    rep(i, 0, C) cin >> col_sums[i];

    int K;
    cin >> K;

    // use constraints to set high and low bounds
    rep(i, 0, K) {
        int r, c, rhs;
        char sign;
        cin >> r >> c >> sign >> rhs;
        r--, c--;

        int rs = r, re = r, cs = c, ce = c;
        if(r == -1) rs = 0, re = R - 1;
        if(c == -1) cs = 0, ce = C - 1;

        rep(i, rs, re + 1) rep(j, cs, ce + 1) {
            if(sign == '>') low[i][j] = max(low[i][j], rhs + 1);
            else if(sign == '<') high[i][j] = min(high[i][j], rhs - 1);
            else low[i][j] = max(low[i][j], rhs), high[i][j] = min(high[i][j], rhs);
        }
    }

    int expected_flow = 0;

    // add edges from s => row-nodes
    rep(r, 0, R) {
        int lower_bound_sum = 0;
        rep(c, 0, C) lower_bound_sum += low[r][c];
        if(row_sums[r] < lower_bound_sum) goto impossible;
        add_edge(0, row_sums[r] - lower_bound_sum, s, R * C + r);
        expected_flow += row_sums[r] - lower_bound_sum;
    }

    // add edges from col-nodes => t
    rep(c, 0, C) {
        int lower_bound_sum = 0;
        rep(r, 0, R) lower_bound_sum += low[r][c];
        if(col_sums[c] < lower_bound_sum) goto impossible;
        add_edge(0, col_sums[c] - lower_bound_sum, R * C + R + c, t);
    }

    // add edges from row-nodes => cell-nodes => col-nodes
    rep(r, 0, R) rep(c, 0, C) {
        if(high[r][c] < low[r][c]) goto impossible;
        add_edge(0, high[r][c] - low[r][c], R * C + r, r * C + c);
        add_edge(0, high[r][c] - low[r][c], r * C + c, R * C + R + c);
    }

    max_flow = calc_max_flow();
    if(max_flow != expected_flow) goto impossible;

    // print flows
    rep(r, 0, R) {
        rep(c, 0, C) {
            cout << edges[cnx[r * C + c][1]].flow + low[r][c] << (c == C - 1 ? "" : " ");
        }
        cout << endl;
    }
    return;

    impossible: 
    cout << "IMPOSSIBLE" << endl;
    return;
}

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        solve();
        if(T) cout << endl;
    }

    return 0;
}

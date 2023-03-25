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
 * Problem Name: Dots and Boxes
 * Difficulty: 6.1 (Hard)
 * Categories: Network Flow
 * Algorithms: Dinic's
 */

struct edge {
    int to, from, flow, cap;
    edge(int from, int to, int flow, int cap) : from(from), to(to), flow(flow), cap(cap) { }
};

int MAX_N = 80 * 80 + 2;

vector<edge> edges;
vector<vector<int>> cnx(MAX_N);
vector<int> vis(MAX_N);
vector<int> level(MAX_N);
int vis_id = 1;
int s, t; // assign to source and sink

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

    int N;
    cin >> N;

    s = (N  - 1) * (N - 1), t = s + 1;

    vector<vector<char>> grid(2 * N + 1, vector<char>(2 * N + 1));
    rep(i, 0, 2 * N - 1) rep(j, 0, 2 * N - 1) cin >> grid[i][j];

    rep(i, 0, N - 1) rep(j, 0, N - 1) {
        int total_empty = 0;
        int total_extra = 0;
        int node = i * (N - 1) + j;
        int empty_from, extra_from, empty_to, extra_to;
        // add edge (empty_to -> empty_from) with capacity (#surrounding which == '.' - 1)
        // add edge (extra_from -> extra_to) for each surrounding edge which isn't shared by another
        // square

        if((i + j) % 2) {
            empty_from = s;
            empty_to = node;
            extra_from = node;
            extra_to = t;
        } else {
            empty_from = node;
            empty_to = t;
            extra_from = s;
            extra_to = node;
        }

        // top
        if(grid[2 * i][2 * j + 1] == '.') {
            total_empty++;
            if(i == 0) total_extra++; // no connection to another square
            else if((i + j) % 2) add_edge(node, (i - 1) * (N - 1) + j, 1); // add edge to neigh
        }

        // right
        if(grid[2 * i + 1][2 * j + 2] == '.') {
            total_empty++;
            if(j == N - 2) total_extra++; // no connection to another square
            else if((i + j) % 2) add_edge(node, i * (N - 1) + (j + 1), 1); // add edge to neigh
        }

        // bottom
        if(grid[2 * i + 2][2 * j + 1] == '.') {
            total_empty++;
            if(i == N - 2) total_extra++; // no connection to another square
            else if((i + j) % 2) add_edge(node, (i + 1) * (N - 1) + j, 1); // add edge to neigh
        }

        // left
        if(grid[2 * i + 1][2 * j] == '.') {
            total_empty++;
            if(j == 0) total_extra++; // no connection to another square
            else if((i + j) % 2) add_edge(node, i * (N - 1) + (j - 1), 1); // add edge to neigh
        }

        if(total_empty > 1) add_edge(empty_from, empty_to, total_empty - 1);
        if(total_extra) add_edge(extra_from, extra_to, total_extra);
    }

    cout << (1 + calc_max_flow()) << endl;

    return 0;
}

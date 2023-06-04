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
 * Problem Name: Early Orders
 * Difficulty: 5.9 (Hard)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, K;
    cin >> N >> K;

    vi vis(K + 1);
    vi counts(K + 1);

    vi a(N);
    rep(i, 0, N) {
        cin >> a[i];
        counts[a[i]]++;
    }

    vi result;
    map<int, queue<int>> idx_map; // {number : index-queue}
    int left_bound = 0; // assume that a[left_bound - 1] is in result

    // populate idx_map, vis, and result
    rep(i, 0, N) {
        if(!vis[a[i]]) idx_map[a[i]].push(i);
        if(--counts[a[i]] != 0 || vis[a[i]]) continue;

        // last occurrence of a[i] found: must add it to result before continuing

        auto it = idx_map.begin();
        while(it != idx_map.end()) {
            queue<int>& q = it->second;
            int curr = it->first;
            while(sz(q) && q.front() < left_bound) q.pop();
            if(!sz(q)) { idx_map.erase(it++); continue; }

            vis[curr] = true;
            result.push_back(curr);
            left_bound = q.front() + 1;
            idx_map.erase(it++);
            if(curr == a[i]) break;
        }
    }

    rep(i, 0, K) cout << result[i] << (i == K - 1 ? "\n" : " ");

    return 0;
}

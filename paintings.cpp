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
 * Problem Name: Paintings
 * Difficulty: 3.9 (Medium)
 * Categories: Backtracking
 * Algorithms: 
 */

vi best;
int num_result;

void find_result(vi& curr, vector<bool>& is_used, vector<vector<bool>>& is_ugly) {
    if(sz(curr) == sz(is_used)) {
        if(num_result == 0) best = curr;
        num_result++;
    }

    rep(i, 0, sz(is_used)) {
        if(is_used[i]) continue;
        if(curr.size() && is_ugly[i][curr.back()]) continue;

        is_used[i] = true;
        curr.push_back(i);
        find_result(curr, is_used, is_ugly);
        curr.pop_back();
        is_used[i] = false;
    }
}

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        unordered_map<string, int> color_to_id(N);
        vector<string> colors(N);
        vector<bool> is_used(N, false);
        vector<vector<bool>> is_ugly(N, vector<bool>(N));

        rep(i, 0, N) {
            cin >> colors[i];
            color_to_id[colors[i]] = i;
        }

        int M;
        cin >> M;
        rep(i, 0, M) {
            string a, b;
            cin >> a >> b;

            int id_a = color_to_id[a], id_b = color_to_id[b];
            is_ugly[id_a][id_b] = true;
            is_ugly[id_b][id_a] = true;
        }

        best.clear();
        num_result = 0;
        vi curr;

        find_result(curr, is_used, is_ugly);

        cout << num_result << endl;
        rep(i, 0, N) cout << colors[best[i]] << (i == N - 1 ? "" : " ");
        cout << endl;
    }

    return 0;
}

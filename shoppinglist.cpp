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
 * Problem Name: Shopping List
 * Difficulty: 3.5 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    map<string, pii> counts;

    string item;
    rep(i, 0, N) {
        rep(j, 0, M) {
            cin >> item;
            if(counts[item].second != i + 1) counts[item].first++;
            counts[item].second = i + 1;
        }
    }

    vector<string> result;

    for(auto& item : counts) {
        if(counts[item.first].first == N) result.push_back(item.first);
    }

    cout << sz(result) << endl;
    rep(i, 0, sz(result)) cout << result[i] << endl;

    return 0;
}

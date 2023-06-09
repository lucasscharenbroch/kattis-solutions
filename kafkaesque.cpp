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
 * Problem Name: Kafkaesque
 * Difficulty: 2.0 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int K;
    cin >> K;

    int last = -1;
    int result = 1;

    rep(i, 0, K) {
        int d;
        cin >> d;

        if(d < last) result++;
        last = d;
    }

    cout << result << endl;

    return 0;
}

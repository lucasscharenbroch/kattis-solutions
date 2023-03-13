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
 * Problem Name: Accounting
 * Difficulty: 4.0 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, Q;
    cin >> N >> Q;

    vi a(N), mod(N); // amount, modification id
    int id = 1; // modification id
    int res_id = 0; // id of last "reset" modification
    int res_val = 0; // last reset value

    while(Q--) {
        string s;
        cin >> s;
        int i, x;

        if(s == "PRINT") {
            cin >> i;
            if(mod[i] > res_id) cout << a[i] << endl;
            else cout << res_val << endl;
        } else if(s == "SET") {
            cin >> i >> x;
            a[i] = x;
            mod[i] = id++;
        } else {
            cin >> x;
            res_val = x;
            res_id = id++;
        }
    }

    return 0;
}

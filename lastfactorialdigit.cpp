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

int main() {
    init_cin();

    int T, N;

    cin >> T;

    while(T--) {
        cin >> N;

        int last_digit = 1;

        rep(i, 1, N + 1) {
            last_digit *= i;
            last_digit %= 10;
        }

        cout << last_digit << endl;
    }

    return 0;
}

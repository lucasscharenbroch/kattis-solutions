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
    int K, N, T;
    char Z;

    cin >> K >> N;

    int time = 210; // 3 minutes and 30 seconds
    int player = K;

    while(N--) {
        cin >> T;
        if(time > 0 && time - T <= 0) cout << player << endl; // current player loses
        time -=T;

        cin >> Z;
        if(Z == 'T') player = (player % 8) + 1;
    }

    return 0;
}

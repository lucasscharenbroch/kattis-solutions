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

    while(true) {
        double R;
        int M, C;

        cin >> R >> M >> C;

        if(R == 0 && M == 0 && C == 0) break;

        double area = M_PI * R * R;
        double estimate = (2 * R) * (2 * R) * ((double)C / (double)M);

        cout << area << " " << estimate << endl;
    }

    return 0;
}

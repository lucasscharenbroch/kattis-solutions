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
 * Problem Name: Trick or Treat
 * Difficulty: 3.6 (Medium)
 * Categories: 
 * Algorithms: Binary Search
 */

double epsilon = 1e-6;

double max_dist(vector<pair<double, double>>& coords, double x) {
    double max_d = 0;

    for(auto& c : coords) {
        double cx = c.first, cy = c.second;

        double dx = cx - x;
        double dy = cy;

        max_d = max(max_d, sqrt(dx * dx + dy * dy));
    }

    return max_d;
}

int main() {
    init_cin();

    while(true) {
        int N;
        cin >> N;
        if(!N) break;

        vector<pair<double, double>> coords;

        rep(i, 0, N) {
            double X, Y;
            cin >> X >> Y;
            coords.push_back(pair<double, double>(X, Y));
        }

        // Binary Search The Answer
        double left = -200'000, right = 200'000;

        while(abs(left - right) > epsilon) {
            double mid = (left + right) / 2;
            double left_mid = (left + mid) / 2;
            double right_mid = (right + mid) / 2;

            double left_dist = max_dist(coords, left_mid);
            double right_dist = max_dist(coords, right_mid);

            if(left_dist < right_dist) right = right_mid;
            else left = left_mid;
        }

        cout << left << " " << max_dist(coords, left) << endl;
    }

    return 0;
}

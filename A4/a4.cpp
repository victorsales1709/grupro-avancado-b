#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;

    cin >> n;
    vector<int> blocks(n);

    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }

    vector<int> dp;
    dp.reserve(n);

    for (int i = n - 1; i >= 0; i--) {
        auto it = upper_bound(dp.begin(), dp.end(), blocks[i]);

        if (it == dp.end()) {
            dp.push_back(blocks[i]);
        } else {
            *it = blocks[i];
        }
    }

    cout << dp.size() << endl;
}
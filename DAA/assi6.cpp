#include <bits/stdc++.h>
#include <vector>
#include <limits>

using namespace std;

pair<vector<vector<int>>, vector<vector<int>>> optimalBST(const vector<int>& keys, const vector<int>& freq) {
    int n = keys.size();
    vector<vector<int>> cost(n, vector<int>(n, 0));
    vector<vector<int>> root(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        root[i][i] = i;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            cost[i][j] = numeric_limits<int>::max();
            int totalFreq = 0;

            for (int k = i; k <= j; k++) {
                totalFreq += freq[k];
            }

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        totalFreq;

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    return {cost, root};
}

void printOptimalBST(const vector<int>& keys, const vector<vector<int>>& root, int i, int j) {
    if (i > j) return;

    int r = root[i][j];
    cout << "Key: " << keys[r] << " is root of keys [" 
         << (i == j ? keys[i] : keys[i]) << " - " << keys[j] << "]" << endl;

    printOptimalBST(keys, root, i, r - 1);
    printOptimalBST(keys, root, r + 1, j);
}

int main() {
    vector<int> keys = {10, 20, 30};
    vector<int> freq = {34, 8, 50};

    auto temp = optimalBST(keys, freq);
    auto cost = temp.first;
    auto root = temp.second;

    cout << "Optimal Cost: " << cost[0][keys.size() - 1] << endl;

    cout << "Optimal Binary Search Tree structure:" << endl;
    printOptimalBST(keys, root, 0, keys.size() - 1);

    return 0;
}


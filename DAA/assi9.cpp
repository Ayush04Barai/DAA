#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

struct Node {
    int level;
    int profit;
    int weight;
    double bound;
};

struct CompareNode {
    bool operator()(Node const &a, Node const &b) {
        return a.bound < b.bound;
    }
};

void calculateRatios(vector<Item> &items) {
    for (auto &item : items) {
        item.ratio = static_cast<double>(item.value) / item.weight;
    }
}

void sortItemsByRatio(vector<Item> &items) {
    for (size_t i = 0; i < items.size() - 1; ++i) {
        for (size_t j = 0; j < items.size() - i - 1; ++j) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

double bound(Node &u, int n, int W, vector<Item> &items) {
    if (u.weight >= W) return 0;

    double profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        profitBound += items[j].value;
        j++;
    }

    if (j < n) {
        profitBound += (W - totalWeight) * items[j].ratio;
    }

    return profitBound;
}

int knapsack(int W, vector<Item> &items) {
    sortItemsByRatio(items);

    priority_queue<Node, vector<Node>, CompareNode> pq;

    Node root;
    root.level = -1;
    root.profit = 0;
    root.weight = 0;
    root.bound = bound(root, items.size(), W, items);

    pq.push(root);
    int maxProfit = 0;

    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();

        if (u.bound > maxProfit) {
            Node v;
            v.level = u.level + 1;
            v.weight = u.weight + items[v.level].weight;
            v.profit = u.profit + items[v.level].value;

            if (v.weight <= W && v.profit > maxProfit) {
                maxProfit = v.profit;
            }

            v.bound = bound(v, items.size(), W, items);
            if (v.bound > maxProfit) {
                pq.push(v);
            }

            v.weight = u.weight;
            v.profit = u.profit;
            v.level = u.level + 1;
            v.bound = bound(v, items.size(), W, items);
            if (v.bound > maxProfit) {
                pq.push(v);
            }
        }
    }

    return maxProfit;
}

int main() {
    int W = 50;
    vector<Item> items = {
        {60, 10}, {100, 20}, {120, 30}
    };

    calculateRatios(items);

    int maxProfit = knapsack(W, items);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}


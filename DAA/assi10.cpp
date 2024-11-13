#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct State {
    int mask;
    int cost;
    int level;
};

struct CompareState {
    bool operator()(const State &a, const State &b) {
        return a.cost > b.cost;
    }
};

class JobAssignment {
    int n;
    vector<vector<int>> costMatrix;

public:
    JobAssignment(int n, vector<vector<int>> &costMatrix);
    int branchAndBound();
};

JobAssignment::JobAssignment(int n, vector<vector<int>> &costMatrix) {
    this->n = n;
    this->costMatrix = costMatrix;
}

int JobAssignment::branchAndBound() {
    priority_queue<State, vector<State>, CompareState> pq;
    State initialState = {0, 0, 0};
    pq.push(initialState);
    
    int minCost = INT_MAX;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.level == n) {
            minCost = min(minCost, current.cost);
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (!(current.mask & (1 << j))) {
                State nextState = current;
                nextState.mask |= (1 << j);
                nextState.cost += costMatrix[current.level][j];
                nextState.level++;
                pq.push(nextState);
            }
        }
    }

    return minCost;
}

int main() {
    int n = 4;
    vector<vector<int>> costMatrix = {
        {10, 19, 8, 15},
        {10, 18, 7, 17},
        {13, 16, 9, 14},
        {12, 19, 20, 8}
    };

    JobAssignment jobAssignment(n, costMatrix);
    int minCost = jobAssignment.branchAndBound();
    
    cout << "The minimum cost of job assignment is: " << minCost << endl;

    return 0;
}


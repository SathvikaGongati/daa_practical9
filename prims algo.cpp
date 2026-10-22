#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int cost[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    int visited[4] = {0};
    visited[0] = 1;

    int edges = 0, mincost = 0;

    while (edges < n - 1) {
        int min = 999, a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] != 0 &&
                        cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << a << " - " << b << " : " << min << endl;
        mincost += min;
        visited[b] = 1;
        edges++;
    }

    cout << "Minimum cost = " << mincost;

    return 0;
}

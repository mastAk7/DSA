#include <bits/stdc++.h>

using namespace std;

struct State {
    int x, y, steps;
    bitset<26> used;

    // Custom comparison for set
    bool operator<(const State& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return used.to_ulong() < other.used.to_ulong();
    }
};

int minMoves(vector<string>& matrix) {
    int m = matrix.size(), n = matrix[0].size();

    // Store all teleport portals
    unordered_map<char, vector<pair<int, int>>> portals;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (isupper(matrix[i][j]))
                portals[matrix[i][j]].emplace_back(i, j);

    queue<State> q;
    set<tuple<int, int, unsigned long>> visited;

    bitset<26> initial;
    q.push({0, 0, 0, initial});
    visited.insert({0, 0, initial.to_ulong()});

    vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    while (!q.empty()) {
        State cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, steps = cur.steps;
        bitset<26> used = cur.used;

        if (x == m - 1 && y == n - 1)
            return steps;

        // Move in all directions
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] != '#') {
                auto key = make_tuple(nx, ny, used.to_ulong());
                if (!visited.count(key)) {
                    visited.insert(key);
                    q.push({nx, ny, steps + 1, used});
                }
            }
        }

        // Handle teleportation
        char cell = matrix[x][y];
        if (isupper(cell) && !used[cell - 'A']) {
            bitset<26> newUsed = used;
            newUsed.set(cell - 'A');

            for (auto& [tx, ty] : portals[cell]) {
                if (tx == x && ty == y) continue;
                auto key = make_tuple(tx, ty, newUsed.to_ulong());
                if (!visited.count(key)) {
                    visited.insert(key);
                    q.push({tx, ty, steps, newUsed});
                }
            }
        }
    }

    return -1;
}

int main() {
    vector<string> grid = {
        ".#...",".#.#.",".#.#.","...#."
    };
    cout << minMoves(grid) << endl;
    return 0;
}

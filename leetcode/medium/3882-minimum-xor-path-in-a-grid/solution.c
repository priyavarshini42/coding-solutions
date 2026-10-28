int minCost(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int dp[1000][1024] = {0};
    int vis[1000][1024] = {0};

    dp[0][grid[0][0]] = 1;
    vis[0][grid[0][0]] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                continue;

            for (int x = 0; x < 1024; x++) {
                if (vis[i * n + j - 1][x] && j > 0) {
                    int v = x ^ grid[i][j];
                    dp[i * n + j][v] = 1;
                    vis[i * n + j][v] = 1;
                }

                if (i > 0 && vis[(i - 1) * n + j][x]) {
                    int v = x ^ grid[i][j];
                    dp[i * n + j][v] = 1;
                    vis[i * n + j][v] = 1;
                }
            }
        }
    }

    for (int x = 0; x < 1024; x++) {
        if (vis[(m - 1) * n + (n - 1)][x])
            return x;
    }

    return 0;
}
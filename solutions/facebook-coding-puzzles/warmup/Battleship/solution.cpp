#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

double getHitProbability(int R, int C, vector<vector<int>> G) {
  double totalBattleShips = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                totalBattleShips += G[i][j];

        return totalBattleShips / (R * C);
}


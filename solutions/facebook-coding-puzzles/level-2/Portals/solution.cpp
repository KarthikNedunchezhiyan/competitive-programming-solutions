#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

typedef pair<int, int> coordinate;

int getSecondsRequired(int R, int C, vector<vector<char>> G) {
       // Write your code here
       map<char, vector<coordinate>> edges;
        int si, sj;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (G[i][j] == '.' || G[i][j] == '#')
                    continue;
                if (G[i][j] == 'S') {
                    si = i, sj = j;
                    continue;
                }
                auto it = edges.find(G[i][j]);
                if (it == edges.end())
                    edges[G[i][j]] = {{i, j}};
                else
                    it->second.emplace_back(i, j);
            }

        queue<coordinate> bfsQ;
        bfsQ.emplace(si, sj);
        int bfsLevel = 0;
        vector<coordinate> directions = {{-1, 0},
                                         {0,  -1},
                                         {0,  1},
                                         {1,  0}};
        while (!bfsQ.empty()) {
            int QSize = bfsQ.size();

            while (QSize-- > 0) {
                coordinate cCell = bfsQ.front();
                bfsQ.pop();

                if (cCell.first < 0 || cCell.second < 0 || cCell.first >= R || cCell.second >= C ||
                    G[cCell.first][cCell.second] == '*' || G[cCell.first][cCell.second] == '#')
                    continue;

                char cCellValue = G[cCell.first][cCell.second];

                G[cCell.first][cCell.second] = '*';

                if (cCellValue == 'E')
                    return bfsLevel;

                for (coordinate dir: directions)
                    bfsQ.emplace(cCell.first + dir.first, cCell.second + dir.second);


                if (cCellValue >= 'a' && cCellValue <= 'z')
                    for (coordinate portal: edges[cCellValue])
                        bfsQ.emplace(portal.first, portal.second);
            }

            bfsLevel++;
        }

        return -1;
}


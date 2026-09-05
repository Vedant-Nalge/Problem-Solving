class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();

        int old = image[sr][sc];

        if (old == color)
            return image;

        queue<pair<int, int>> q;

        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty()) {
            auto node = q.front();
            int r = node.first;
            int c = node.second;
            q.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nc = c + dc[i];
                int nr = r + dr[i];

                if (nr < n && nc < m && nr >= 0 && nc >= 0 &&
                    image[nr][nc] == old) {
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
};
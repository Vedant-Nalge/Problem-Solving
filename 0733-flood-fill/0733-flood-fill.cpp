class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int initialColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans;
        ans = image;
        if (initialColor == color)
            return image;
        queue < pair < int, int >> q;

        image[sr][sc] = color;
        q.push({sr, sc});

        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            auto node = q.front();
            int r = node.first;
            int c = node.second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == initialColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};
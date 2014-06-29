// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:

// a) Insert a character
// b) Delete a character
// c) Replace a character

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if(!m) return n;
        if(!n) return m;
        vector< vector<int> > dist(2, vector<int>(n+1, 0));
        for(int i = 1; i <= n; ++i)
            dist[0][i] = i;
        bool curRow = true;
        for(int i = 1; i <= m; ++i) {
            dist[curRow][0] = i;
            for(int j = 1; j <= n; ++j) {
                if(word1[i-1] == word2[j-1]) {
                    dist[curRow][j] = dist[!curRow][j-1];
                } else {
                    dist[curRow][j] = min(dist[!curRow][j-1], min(dist[curRow][j-1], dist[!curRow][j]))+1;
                }
            }
            curRow = !curRow;
        }
        return dist[!curRow][n];
    }
};

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int len = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += len) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + len - i < n)
                    ret += s[j + len - i];
            }
        }
        return ret;
    }
};

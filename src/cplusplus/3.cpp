class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int g_len = s.length();
        
        if (g_len == 0)
            return 0;
        
        std::unordered_map<char, int> g_map;
        std::unordered_map<char, int>::iterator g_map_iter;
        
        int g_longest = 0;

        for (int i = 0, j = 0; j < g_len; ++j)
        {
            g_map_iter = g_map.find(s[j]);
                        
            if (g_map_iter != g_map.end())
            {
                i = std::max(i, g_map_iter->second + 1);    
            }

             g_map[s[j]] =  j;            
             g_longest = std::max(g_longest, j - i + 1);
                          
        }
        
        return g_longest;
    }
};

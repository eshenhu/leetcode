class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int g_len_words = words.size();
        
        if (g_len_words == 0)
            return {};
        
        
        // double check the pre-conditions as in the Example 2, actually,
        // it does not meet the pre-condition.
        int g_len_word = words[0].size();
        
        for (const auto& word : words)
        {
            if (word.size() != g_len_word)
                return {};
        }
            
        // construct the map like <key, number_of_match_in_words>
        /*   ["abc", 1]
        *    ["bcd", 2]
        *    ["def", 1]
        */
        std::unordered_map<string, int> g_map;
        // construct the map
        for (const auto& word : words)
            ++g_map[word];
        
        vector<int> g_vec_idx;
        
        for (auto iter_per_c = s.begin(); iter_per_c < s.end() - g_len_word * g_len_words + 1; ++iter_per_c)
        {
            std::unordered_map<string, int> g_map_mark;
            
            int k = 0;
            for (; k < g_len_words; ++k)
            {
                auto iter_start = iter_per_c + k * g_len_word;
                
                string str(iter_start, iter_start + g_len_word);
    
                auto iter_find = g_map.find(str);
                if (iter_find != g_map.end())
                {
                    ++g_map_mark[str];
                    
                    if (g_map_mark[str] > g_map[str])
                        break;
                }
                else
                {
                    break;
                }
            }
            
            if (k == g_len_words)
                g_vec_idx.push_back(iter_per_c - s.begin());
        }
        
        return g_vec_idx;
            
    }
};

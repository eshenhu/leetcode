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
            
        // construct the map like
        /*   ["abc", 1]
        *    ["bcd", 2]
        *    ["def", 3]
        */
        int cnt_v = 0;
        int g_accu = 0;
        std::unordered_map<string, int> g_map;
        for (const auto& word : words)
        {
            bool is_inside = false;
            std::unordered_map<string, int>::iterator iter; 
            std::tie(iter, is_inside) = g_map.emplace(word, cnt_v);
            g_accu += iter->second;
            if (is_inside)
                ++cnt_v;
        }
        
        
        // construct the g_array
        std::vector<int> g_array(s.size());
        
        for (auto iter = s.cbegin(); (iter + g_len_word - 1) < s.cend(); ++iter)
        {
            std::string lookfor(iter, iter + g_len_word);
            //std::cout << "lookfor " << lookfor << '\n';
            auto iter_found = g_map.find(lookfor);
            if (iter_found != g_map.end())
                g_array[iter - s.cbegin()] = g_map.at(lookfor);
        }
        
        vector<int> g_vec_idx;
        for (auto iter = g_array.cbegin(); (iter + g_len_word - 1) < g_array.cend(); ++iter)
        {
            //int sum = std::accumulate(iter, iter + g_len_word - 1, 0);
            int sum = 0;
            for (int i = 0; i < g_len_words; ++i)
            {
                if ((iter + i * g_len_word) < g_array.cend())
                {
                    //std::cout << "sum += " << *(iter + i * g_len_word) << '\n';
                    sum += *(iter + i * g_len_word);
                }
                else
                    break;
            }
            
            if (sum == g_accu)
                g_vec_idx.push_back(iter - g_array.cbegin());
        }
        
        
        return g_vec_idx;
            
    }
};

class Solution {
public:   
    int myAtoi(string str) {
        char a;
        int g_idx = 0;
        int g_sign = false;
        const int g_len = str.length();
        long g_fin = 0; 
    
        
        while(g_idx < g_len)
        {     
            a = str.at(g_idx);
            
            if (a == ' ')
            {
                ++g_idx;
                continue;
            }           
            
            if (a == '-')
            {
                ++g_idx;
                g_sign = true;
                break;
            }
            
            if (a == '+')
            {
                ++g_idx;
                break; 
            }                         
            
            if (std::isdigit(a))
                break;
            
            //throw std::runtime_error("%s : exception when trim header\n", __function__);
            return 0;
        }
        
        // then it should start with digit, such like '1234', '01234', '1234p', '1234 p'
        const unsigned int g_limit = g_sign ? std::abs(std::numeric_limits<int>::min()) : std::numeric_limits<int>::max();
        
        while(g_idx < g_len)
        {
            a = str.at(g_idx);
            if (!std::isdigit(a) || std::isspace(a) || a == '.')
                break;

            g_fin = g_fin * 10 + ((int)a - (int)'0'); 
            
            if (g_fin > g_limit)
                return g_sign ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();                
            
            ++g_idx;
        }
        
        return g_sign ? (int)-g_fin : (int)g_fin;
    }
};

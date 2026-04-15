class TimeMap {
public:

    //map<key, {{time1, value1}, {time2, value2}}>
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> uMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        uMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        auto itr = uMap.find(key);
        if(itr == uMap.end())
            return "";
        
        auto& vec = itr->second;

        int l = 0;
        int r = vec.size()-1;

        std::string value = "";
        int i = 0;
        while(l <= r)
        {
            int m = l + ((r-l)/2);

            //store the current timestamp if it is smaller than the target.
            if(timestamp >= vec[m].first)
            {
                value = vec[m].second;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return value;
    }
};

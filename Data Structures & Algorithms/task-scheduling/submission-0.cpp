class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        std::unordered_map<char, int> charFreqMap;
        for(auto task : tasks)
        {
            charFreqMap[task]++;
        }

        std::priority_queue<int> tasksFreqQueue;
        auto itr = charFreqMap.begin();
        while(itr!=charFreqMap.end())
        {
            tasksFreqQueue.push(itr->second);
            itr++;    
        }

        //A queue to keep the tasks waiting for their cooldown period to finish.
        std::queue<std::pair<int, int>> cooldownQueue;

        int cpuCycle = 0;
        while(!tasksFreqQueue.empty() || !cooldownQueue.empty())
        {
            cpuCycle++;
            if(tasksFreqQueue.size())
            {
                int taskFreq = tasksFreqQueue.top();
                tasksFreqQueue.pop();
                
                taskFreq--;
                if(taskFreq)
                {
                    cooldownQueue.push({taskFreq, cpuCycle + n});
                }
            }
            
            if(cooldownQueue.size() && (cooldownQueue.front().second == cpuCycle))
            {
                tasksFreqQueue.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return cpuCycle;
    }
};

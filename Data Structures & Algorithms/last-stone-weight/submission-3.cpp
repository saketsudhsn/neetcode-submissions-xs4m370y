class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        std::priority_queue<int> pQ;
        for(auto stone : stones)
            pQ.push(stone);

        while(pQ.size() > 1)
        {
            int stone1 = pQ.top();
            pQ.pop();
            int stone2 = pQ.top();
            pQ.pop();

            if(stone1 > stone2)
                pQ.push(stone1 - stone2);
        }

        return pQ.size()?pQ.top():0;
    }
};

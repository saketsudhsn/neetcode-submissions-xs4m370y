class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        auto cmp = [](const std::vector<int>& point1, const std::vector<int> point2)->bool
        {
            return (point1[0] * point1[0]) + (point1[1] * point1[1]) < (point2[0] * point2[0]) + (point2[1] * point2[1]);
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> pQueue(cmp);
        for(auto point : points)
        {
            pQueue.push(point);
            if(pQueue.size() > k)
                pQueue.pop();
        }

        std::vector<std::vector<int>> res;
        while(pQueue.size())
        {
            res.push_back(pQueue.top());
            pQueue.pop();
        }

        return res;
    }
};

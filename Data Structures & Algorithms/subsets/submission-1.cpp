class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        // Start with an empty subset already a part of the subsets
        vector<vector<int>> res = {{}};

        // Iterate through all the elements of the input vector
        for (int num : nums) {
            // Storing the size of the result vector so that we can 
            int size = res.size();
            std::cout << "curr res size: " << size << ": ";
            for(int i = 0; i < res.size(); i++)
            {
                if(i == 0)
                    std::cout << "{";
                if(res[i].empty())
                    std::cout << "{}";
                else
                {
                    for(int j = 0; j < res[i].size(); j++)
                    {
                        if(j==0)
                            std::cout << "{";

                        std::cout << res[i][j];
                        
                        if(j != res[i].size()-1)
                            std::cout << ", ";
                        else
                            std::cout << "}";
                    }
                }

                if(i != res.size()-1)
                        std::cout << ", ";
                else
                    std::cout << "}\n";
            }

            for (int i = 0; i < size; i++) 
            {
                //Creating a vector equivalent to the current iterating subset.
                vector<int> subset = res[i];
                
                std::cout << "Initial subset: ";
                for(int i = 0 ; i < subset.size(); i++)
                {
                    if(i==0)
                        std::cout << " {";

                    std::cout << subset[i];
                    
                    if(i != subset.size()-1)
                        std::cout << ", ";
                    else
                        std::cout << "}";
                }

                subset.push_back(num);
                std::cout << "\nPushing " << num << " to subset: ";
                for(int i = 0 ; i < subset.size(); i++)
                {
                    if(i==0)
                        std::cout << " {";

                    std::cout << subset[i];
                    
                    if(i != subset.size()-1)
                        std::cout << ", ";
                    else
                        std::cout << "}";
                }

                res.push_back(subset);

                std::cout << "\nFinal subset: ";
                for(int i = 0 ; i < subset.size(); i++)
                {
                    if(i==0)
                        std::cout << " {";
                    
                    std::cout << subset[i];

                    if(i != subset.size()-1)
                        std::cout << ", ";
                    else
                        std::cout << "}\n";
                }
                
                std::cout << "\n";
            }
        }

        return res;
    }
};
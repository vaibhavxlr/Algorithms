class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int smallest, largest, result;
        smallest = arrays[0][0];
        largest = arrays[0][arrays[0].size() - 1];

        for(int i = 1; i < arrays.size(); i++) {
            int arrSize = arrays[i].size();
            result = max(result, max(largest - arrays[i][0], arrays[i][arrSize - 1] - smallest));
            largest = max(largest, arrays[i][arrSize - 1]);
            smallest = min(smallest, arrays[i][0]);
        }

        return result;
    }
};
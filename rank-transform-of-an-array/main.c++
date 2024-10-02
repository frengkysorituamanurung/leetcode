#include <vector>
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Create a sorted copy of the original array
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        // Use a map to store the rank of each unique element
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        // Assign ranks to each element, avoiding duplicates
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank;
                rank++;
            }
        }
        
        // Transform the original array using the rank map
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        
        return result;
    }
};

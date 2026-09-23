class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.length();

        if (p.size() > s.size()) return {};

        unordered_map<char,int> S_map;
        unordered_map<char,int> P_map;
        vector<int> result;


        for(auto x : p){
            P_map[x]++;
        }
        
        int left = 0;
        int right = 0;
        while(right < k){
            S_map[s[right]]++;
            right++;
        }
        while(right < s.size()){
                if(S_map == P_map){
                    result.push_back(left);
                }
                S_map[s[left]]--;
                if (S_map[s[left]] == 0) {
                    S_map.erase(s[left]);
                }
                S_map[s[right]]++;
                left++;
                right++;
            }
            if(S_map == P_map) result.push_back(left);
        return result;
    }
};
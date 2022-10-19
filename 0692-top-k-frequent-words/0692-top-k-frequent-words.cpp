struct Comparator{
    bool operator()(pair <string ,int> a, pair <string, int> b){
        if(a.second != b.second) return !(a.second < b.second);
        return !(a.first > b.first);
    }
};
class Solution {
public:
    static bool cmp(pair <string, int> a, pair <string, int> b){
        if(a.second != b.second) return a.second > b.second;;
        return a.first < b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        priority_queue < pair <string, int>, vector < pair <string, int> >, Comparator > v;
        for(int i = 0; i < words.size(); i++){
            m[words[i]]++;
        }
        map<string, int> :: iterator i = m.begin();
        while(i != m.end()){
            if(v.size() < k){
                v.push(*i);
            }else if(v.top().second < i->second){
                v.pop();
                v.push(*i);
            }else if(v.top().second == i->second && v.top().first > i->first){
                v.pop();
                v.push(*i);
            }
            i++;
        }
        vector <string> res;
        while(!v.empty()){
            pair <string, int> temp = v.top();
            v.pop();
            res.push_back(temp.first);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
template<typename T>
class Multiset{
    map<T, int> m;
    public:
    Multiset(){ m.clear(); }
    void insert(T v){ m[v]++; }
    void erase(T v){
        if(m.find(v)!=m.end()){
            m[v]--;
            if(!m[v])
                m.erase(v);
        }
    }
    int rbegin(){
        return m.rbegin()->first;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<int>> m;
        for(auto &i:buildings){
            m[i[0]].push_back(i[2]);
            m[i[1]].push_back(-i[2]);
        }

        vector<vector<int>> r;
        Multiset<int> s;
        s.insert(0);
        int prv = 0, cur;
        for(auto &i:m){
            vector<int> &v = i.second;
            int l=0;
            while(l<v.size() && v[l]<0)
                s.erase(-v[l++]);
            while(l<v.size())
                s.insert(v[l++]);
            cur = s.rbegin();
            if(cur != prv)
                r.push_back({i.first, cur});
            prv = cur;
        }
        return r;
    }
};
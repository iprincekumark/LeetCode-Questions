class Solution {
public:
    int getParent(int node, map <int, int>& parent){
        if(!parent.count(node) || parent[node] == node) return node;
        return parent[node] = getParent(parent[node], parent);
    }
    int removeStones(vector<vector<int>>& stones) {
        map <int, int> parent;
        int next = 1e4 + 1;
        int ret = 0;
        set <int> islands;
        for(auto& it : stones){
            parent[getParent(it[0], parent)] = getParent(it[1] + next, parent);
        }
        for(auto& it : stones){
            islands.insert(getParent(it[0], parent));
            islands.insert(getParent(it[1] + next, parent));
        }
        ret = stones.size() - islands.size();
        return ret;
        
    }
};
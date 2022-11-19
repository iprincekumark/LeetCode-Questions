class Solution {
public:
    static bool cmp(vector <int>& a, vector <int>& b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    bool crossProduct(vector <int>& a, vector <int>& b, vector <int>& c){
        int y1 = a[1] - b[1];
        int x1 = a[0] - b[0];
        int x2 = a[0] - c[0];
        int y2 = a[1] - c[1];
        return (y2 * x1 - x2 * y1) < 0;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector < vector <int> > ret;
        sort(points.begin(), points.end(), cmp);
        int n = points.size();
        for(int i = 0; i < n; i++){
            while(ret.size() > 1 && crossProduct(ret[ret.size() - 2], ret.back(), points[i])) ret.pop_back();
            ret.push_back(points[i]);
        }
        if(ret.size() == n) return ret;
        for(int i = n - 2; i >= 0; i--){
            while(ret.size() > 1 && crossProduct(ret[ret.size() - 2], ret.back(), points[i])) ret.pop_back();
            ret.push_back(points[i]);
        }
        ret.pop_back();
        return ret;
    }
};
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& p) {
        unordered_map <string, vector <string> > m;
        vector < vector <string> > ret;
        for(int i = 0; i < p.size(); i++){
            string root = "";
            int j = 0;
            while(p[i][j] != ' '){
                root += p[i][j];
                
                j++;
            }
            j++;
            while(j < p[i].size()){
                string text = "";
                for(; j < p[i].size() && p[i][j] !='('; j++){
                    text += p[i][j];
                }
                j++;
                string name = "";
                for(; j < p[i].size() && p[i][j] !=')'; j++){
                    name += p[i][j];
                }
                j++;
                j++;
                m[name].push_back(root + "/" + text);
            }
         //   cout << root << endl;
        }
        
        
        unordered_map <string, vector <string> > :: iterator it = m.begin();
        while(it != m.end()){
            if(it->second.size() > 1){
                ret.push_back(it->second);
            }
            it++;
        }
        return ret;
    }
};
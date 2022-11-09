class StockSpanner {
public:
    vector <int> st;
    int counter;
    vector <int> v;
    StockSpanner() {
        counter = 0;
    }
    
    int next(int price) {
        counter++;
        while(!st.empty() && price >= v[st.back() - 1])st.pop_back();
        int ans = st.empty() ? counter : counter - st.back();
        //cout << price << endl;
        //for(int i = 0; i < st.size(); i++)cout << st[i] << " ";
        //cout << endl;
        v.push_back(price);
        st.push_back(counter);
        return ans ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
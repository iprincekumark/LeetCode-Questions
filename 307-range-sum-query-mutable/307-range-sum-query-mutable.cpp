class NumArray {
public:
    static const int N = 1e5+2;
    vector<int> a;
    int tree[4*N];
    int size;
    
    void solve(int node,int st,int en){
        if(st==en)
        {
            tree[node]=a[st];
            return;
        }
        int mid=(st+en)/2;
        solve(2*node,st,mid);
        solve((2*node)+1,mid+1,en);
        tree[node]=tree[2*node]+tree[(2*node)+1];
    }
    void solveupdater(int node,int st,int en,int idx,int val){
        if(st==en)
        {
            a[st]=val;
            tree[node]=val;
            return;
        }
        int mid=(st+en)/2;
        if(idx<=mid)
        {
            solveupdater(2*node,st,mid,idx,val);
        }
        else
        {
            solveupdater((2*node)+1,mid+1,en,idx,val);   
        }
        tree[node]=tree[2*node]+tree[(2*node)+1];
    }
    int solverrange(int node,int st,int en,int l,int r){
        if(st>r || en<l)
        {
            return 0;
        }
        if(st>=l && en<=r)
        {
            return tree[node];
        }
        int mid=(st+en)/2;
        int k1=solverrange(2*node,st,mid,l,r);
        int k2=solverrange((2*node)+1,mid+1,en,l,r);
        return k1+k2;
    }
    NumArray(vector<int>& nums) {
        a=nums;
        size=nums.size()-1;
        solve(1,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        solveupdater(1,0,size,index,val);
    }
    
    int sumRange(int left, int right) {
        return solverrange(1,0,size,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
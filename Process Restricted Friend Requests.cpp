class UnionFind {
    vector<int> arr;
public:
    UnionFind(int n): arr(n){
        iota(begin(arr),end(arr),0);
    }
    void connect(int a,int b){
        arr[find(a)]=find(b);
    }
    int find(int a){
        return arr[a]==a?a:(arr[a]=find(arr[a]));
    }
    int connected(int a,int b){
        return find(a)==find(b);
    }
};

class Solution{
    public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        UnionFind uf(n);
        for(auto &r:requests){
            int p=uf.find(r[0]),q=uf.find(r[1]);
            bool valid=true;
            if(!uf.connected(p,q)){
                for(auto &b: restrictions){
                    int x=uf.find(b[0]),y=uf.find(b[1]);
                    if((x==p and y==q)or(x==q and y==p)){
                        valid=false;
                        break;
                    }
                }
            }
            ans.push_back(valid);
            if(valid) uf.connect(p,q);
        }
        return ans;
    }
};

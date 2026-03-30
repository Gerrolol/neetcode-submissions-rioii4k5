class DSU{
    private:
        vector<int>parent;
        vector<int>rank;
        
    public:
        bool flag = false;
        DSU(int n) :rank(n, 0), parent(n){
            for(int i=0; i<n; i++){
                parent[i] = i; 
            }
        }
        
        void Union(int a, int b){
            int parentA = findParent(a);
            int parentB = findParent(b);
            if(parentA != parentB){
                if(rank[parentA] > rank[parentB]){
                    parent[parentB] = parentA;
                }else if(rank[parentB] > rank[parentA]){
                    parent[parentA] = parentB;
                }else{
                    parent[parentB] = parentA;
                    rank[parentA]++;
                }
            }else{
                flag = true;
            }
        }
        int findParent(int a){
            if(parent[a] == a){
                return a;
            }else{
                parent[a] = findParent(parent[a]);
            }
            return parent[a];
        }  
};


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU graph(n);
        for(auto& edge: edges){
            graph.Union(edge[0], edge[1]);
        }
        int p = graph.findParent(0);
        for(int i=1; i<n; i++){
            if(graph.findParent(i) != p){
                graph.flag = true;
            }
        }

        if(graph.flag == true){
            return false;
        }
        return true;
    }
};

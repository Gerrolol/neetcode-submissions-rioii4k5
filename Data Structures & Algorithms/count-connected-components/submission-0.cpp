
class DSU{
    private:
        vector<int>parent;
        vector<int>rank;
        
    public:
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
    int countComponents(int n, vector<vector<int>>& edges) {
       DSU graph(n);
        for(auto& edge: edges){
            graph.Union(edge[0], edge[1]);
        } 
        
        int counter = 0;
        unordered_set<int>calc;
        for(int i=0; i<n; i++){
            int p = graph.findParent(i);
            if(calc.find(p) == calc.end()){
                counter++;
                calc.insert(p);
            }
        }
        return counter;
    }
};




class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create adjacency list
        vector<list<pair<int,int>>>adjlist(n+1);
        for(auto& row : times){
            adjlist[row[0]].push_back({row[1], row[2]});
        }

        //set up for dijkstras
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
        unordered_set<int>visited;
        vector<int>distances(n+1, INT_MAX);
        distances[k] = 0;
        pq.push({0,k});
        
        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();

            if(visited.find(node) != visited.end()){
                continue;
            }

            visited.insert(node);
            
            for(auto neigh: adjlist[node]){
                int dest = neigh.first;
                int w = neigh.second;
                if(dist + w < distances[dest]){
                    distances[dest] = dist + w;
                    pq.push({distances[dest], dest});
                }
            }
        }

        int res = 0;
        for(int i=1; i<n+1; i++){
            if(distances[i] == INT_MAX){
                return -1;
            }else if(distances[i] == 0){
                continue;
            }else{
                res = max(res, distances[i]);
            }
        }
        return res;
    }
};

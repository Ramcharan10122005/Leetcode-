class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double>dis(n,-1);
        dis[start_node]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto [currProb,currNode]=pq.top();
            pq.pop();

            if(currProb<dis[currNode])
            continue;
            for(auto pair:adj[currNode]){
                auto [node,prob]=pair;
                double newProb=currProb*prob;
                if(newProb>dis[node]){
                    dis[node]=newProb;
                    pq.push({newProb,node});
                }
            }
        }
        return dis[end_node]==-1?0:dis[end_node];
    }
};
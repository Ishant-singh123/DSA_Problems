class Solution {
public:
// Cheapest Flights Within K Stops is a very important graph pattern because it looks like Dijkstra, but the k stops constraint changes the pattern.
// The key pattern is:
// Shortest path + limited number of edges/stops → Bellman-Ford / layered shortest path / DP

// Graph
//  ↓
// Directed weighted graph
//  ↓
// Minimum cost
//  ↓
// Shortest Path
//  ↓
// BUT there is a limit on stops/edges
//  ↓
// Bounded Shortest Path
//  ↓
// Bellman-Ford with K+1 relaxations
// Time = O(K × E)
// Space = O(V)

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        for(int i=0;i<k+1;i++){
            vector<int>temp=dist;
            for(int j=0;j<flights.size();j++){
                int curr=flights[j][0];
                int neigh=flights[j][1];
                int cost=flights[j][2];
                if(dist[curr]==INT_MAX){
                    continue;
                }
                if(temp[neigh]>dist[curr]+cost){
                    temp[neigh]=dist[curr]+cost;
                }
            }
            dist=temp;
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};
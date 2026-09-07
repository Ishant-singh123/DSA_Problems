class Solution {
public:
//     What is an MST?
// An MST connects all vertices with the minimum possible total edge weight and no cycles.
// For n points, an MST always has exactly n − 1 edges.

// Kruskal + DSU ⭐
// This is probably the best approach to learn first because you have already been practicing DSU.

// Step 1: Build all possible edges
// For every pair of points:
// cost = abs(x1 - x2) + abs(y1 - y2);
// Why?
// Because the problem uses Manhattan distance.

// For example:
// (0,0) → (2,3)
// cost = |0-2| + |0-3| = 5
// Since every point can connect to every other point, the graph is complete.

// Step 2: Sort edges by cost
// (0,1,1)
// (1,2,2)
// (0,2,3)
// ...

// Step 3: Use DSU
// For each edge:
// if (find(u) != find(v)) {
//     unite(u, v);
//     ans += cost;
// }

// Why?
// If they are in different components, connecting them is useful.
// If they are already in the same component, adding the edge creates a cycle.
// Step 4: Stop after n - 1 edges

// Because an MST has exactly n - 1 edges.
// Time: O(n² log n²) ≈ O(n² log n)
// Space: O(n²)


// How to identify Prim vs Kruskal?
// Both solve MST, but their thinking is different.

// Kruskal
// Sort edges → keep connecting different components.
// Use when:
// You can easily generate all edges.
// You want to practice DSU.
// The graph is given as an edge list.

// Prim
// Start from one vertex → repeatedly add the cheapest edge to an unvisited vertex.

// Use when:
// You want to grow one connected tree.
// The graph is dense.
// You can calculate the cheapest connection to the current tree efficiently.


    int find(vector<int>&parent,int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent,parent[x]);
    }

    void unite(vector<int>&parent,vector<int>&rank,int a,int b){
        a=find(parent,a);
        b=find(parent,b);

        if(a==b){
            return ;
        }
        if(rank[a]>=rank[b]){
            parent[b]=a;
            rank[a]++;
        }
        else{
            parent[a]=b;
            rank[b]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        vector<tuple<int,int,int>>edges;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({cost,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int used=0;
        int totalcost=0;
        for(auto [cost,u,v]:edges){
            if(find(parent,u)!=find(parent,v)){  // checking that u and v are in different component 
                unite(parent,rank,u,v);
                totalcost=totalcost+cost;
                used++;
            }
            if(used==n-1){
                return totalcost;
            }
        }
        return totalcost;
    }
};
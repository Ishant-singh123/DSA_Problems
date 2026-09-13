class Solution {
public:
    // here belman ford is fail because of time complexicity O(V*E)
//     vector<double> prob(n, 0.0);
// prob[start] = 1.0;

// for(int i = 0; i < n-1; i++) {

//     vector<double> next = prob;

//     for(int j = 0; j < edges.size(); j++) {

//         int u = edges[j][0];
//         int v = edges[j][1];
//         double p = succProb[j];

//         if(prob[u] * p > next[v])
//             next[v] = prob[u] * p;

//         if(prob[v] * p > next[u])
//             next[u] = prob[v] * p;
//     }

//     prob = next;
// }

// but dijkastra can work here O((V+E)logE) (priority_queue)

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
           vector<vector<pair<int,double>>>graph(n);
           for(int i=0;i<edges.size();i++){
                graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
                graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
           }
            vector<double>max_pro(n,0.0);
            max_pro[start_node]=1.0;

            priority_queue<pair<double,int>>pq;  //max heap
            pq.push({max_pro[start_node],start_node});

            while(pq.size()>0){
                int curr=pq.top().second;
                double currProb=pq.top().first;
                pq.pop();
                for(auto neigh:graph[curr]){
                    if(max_pro[neigh.first]<max_pro[curr]*neigh.second){
                        max_pro[neigh.first]=max_pro[curr]*neigh.second;
                        pq.push({max_pro[neigh.first],neigh.first});
                    }
                }
            }
           return max_pro[end_node];

    }
};
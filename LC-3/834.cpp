class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> ance(N);
        vector<vector<int>> graph(N);
        vector<int> v(N);
        vector<int> dist(N);
        for(int i = 0; i < edges.size(); i++){
            int s = edges[i][0];
            int t = edges[i][1];
            graph[s].push_back(t);
            graph[t].push_back(s);
        }
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        ance[0] = -1;
        while(!q.empty()){
            auto tp = q.front();
            v[tp.first] =1 ;
            dist[tp.first] = tp.second;
            q.pop();
            for(int next: graph[tp.first]){
                if(!v[next]) {
                    q.push(make_pair(next, tp.second + 1));
                    ance[next] = tp.first;
                }
            }
        }

        //LCA computing
        vector<int> distance(N);
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                int pi = i, pj = j;
                if(dist[i] > dist[j]){
                    for(int s = 0; s < dist[i] - dist[j]; s++)
                        pi = ance[pi];
                }
                else{
                    for(int s = 0; s < dist[j] - dist[i]; s++)
                        pj = ance[pj];
                }
                while(pi != pj){
                    pi = ance[pi];
                    pj = ance[pj];
                }
                distance[i] += (dist[i] - dist[pi]) + (dist[j] - dist[pj]);
                distance[j] += (dist[i] - dist[pi]) + (dist[j] - dist[pj]);
            }
        }
        return distance;
    }
};
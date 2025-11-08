// BFS Solution 

class Solution {
public:

    bool isNeighbor(string &s1, string &s2){
        int cnt = 0;
        for(int i=0; i<s1.length(); i++){
            cnt += (s1[i] != s2[i]);
        }
        return (cnt == 1);
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        queue<pair<string, int> > q; // node, len
        map<string, bool> vis;

        q.push({startGene, 0});
        vis[startGene] = 1;


        while(!q.empty()){
            string node = q.front().first;
            int len = q.front().second;
            q.pop();

            if(node == endGene)return len;

            for(string cur: bank){
                if(vis[cur])continue;

                if(isNeighbor(node, cur)){
                    vis[cur] = 1;
                    q.push({cur, len + 1});
                }
            }
        }

        return -1;

    }
};
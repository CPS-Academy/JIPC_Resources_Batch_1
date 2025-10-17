class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();

        int graph[26][26];

        vector<int> vis(26, 0);

        for(auto ii: words[0]) vis[ii-'a'] = 1;
        

        for(int i=1; i<n; i++){

            string word1 = words[i-1];
            string word2 = words[i];

            if(word2.size() < word1.size() && word1.substr(0, word2.size()) == word2){
                return "";
            }
            
            for(auto ii:word1)vis[ii - 'a'] = 1;
            for(auto ii:word2)vis[ii - 'a'] = 1;

            int p1 = 0, p2 = 0;
            while(p1 < word1.size() && p2 < word2.size()){
                if(word1[p1] != word2[p2]){
                    int x = word1[p1] - 'a';
                    int y = word2[p2] - 'a';

                    graph[x][y] = 1;
                    break;
                }
                p1++;
                p2++;
            }

        }
        
        vector<int> indeg(26, 0);

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(graph[i][j]){
                    indeg[j]++;
                }
            }
        }


        queue<int> q;

        for(int i=0; i<26; i++){
            if(vis[i] > 0 && indeg[i] == 0)q.push(i);
        }

        string res = "";

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node + 'a');
            vis[node] = 0;

            for(int v = 0; v < 26; v++){
                if(graph[node][v]){
                    indeg[v]--;
                    if(indeg[v] == 0){
                        q.push(v);
                    }
                }
            }
        }

        for(int i=0; i<26; i++){
            if(indeg[i]){
                return "";
            }
            if(vis[i]){
                res.push_back(i + 'a');
            }
        }

        return res;



    }
};
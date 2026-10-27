class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        //dirs vector to simulate adjacent spread like fire/flood
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        
        //visited vector and queue for bfs 
        vector<vector<int>> vis(m, vector<int>(n, 0));   
        queue<pair<int,int>> q;
        
        // push starting node in queue and mark it visited
        q.push({sr ,sc});
        vis[sr][sc] = 1 ;

        // taking copy of  og color and updating image vector
        int og = image[sr][sc];
        image[sr][sc]=color;

        //the logic thingyyy
        while(!q.empty()){
            int size = q.size();
               
                //take elemnt at front in form {x,y}
                 auto[x , y] = q.front();
                // pop it as its used
                 q.pop();
                
                // loop for neighbours of x and y and checking them 
                 for(auto [dx , dy] : dirs){
                    int i = x + dx ;
                    int j = y + dy ;
                    //check bounds of i and j ,  if they are visited , and if they had same og color 
                    if(i>=0 && i<m && j>=0 && j<n && !vis[i][j] && image[i][j] == og){
                        //mark this neighbour as visited
                         vis[i][j] = 1 ;
                         // update image
                         image[i][j] = color ;
                         //push this visited neighbour in queue
                         q.push({i,j}) ;

                    }
                 }
        }
        return image;
    }
};
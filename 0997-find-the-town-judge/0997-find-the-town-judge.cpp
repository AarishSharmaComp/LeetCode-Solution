class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        // Quick response for simple case
        if( 1 == n ){
            return 1;
        }
        
        // first cell is dummy, just for the convenience of indexing start from 1 to N
        vector< int > trustScore(n+1);
        
        // General cases:
        for( auto trustVector : trust){
            
            int p1 = trustVector[0], p2 = trustVector[1];
            
			// decrease one point from p1 when p1 trusts other people
            trustScore[ p1 ] -= 1;
			
			// increase one point to p2 when p2 is trusted by others
            trustScore[ p2 ] += 1;
        }
        
        for( int personID = 1 ; personID <= n ; personID++ ){
            
			// town judge will be trusted by other N-1 people, and town judge trust nobody.
            if( (n - 1) == trustScore[personID]  ){
                return personID;
            }
        }
        
        return -1;
    }
};
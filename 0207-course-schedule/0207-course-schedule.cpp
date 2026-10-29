class Solution {
public:

    bool canFinish(
        int numCourses,
        vector<vector<int>>& prerequisites
    ) {

        // Build the directed graph.
        // prerequisites[i] = {course, prerequisite}
        //
        // Example:
        // {0, 1} means course 0 depends on course 1.
        vector<vector<int>> edge(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {

            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];

            edge[course].push_back(prerequisite);
        }

        // 0 -> Not visited
        // 1 -> Currently active in DFS
        // 2 -> Completely processed
        vector<int> status(numCourses, 0);

        // Check every course for a cycle
        for (int i = 0; i < numCourses; i++) {

            // Start DFS only from an unvisited course
            if (status[i] == 0) {

                // If a cycle is found, courses cannot be completed
                if (dfsLoop(edge, i, status)) {
                    return false;
                }
            }
        }

        // No cycle found
        return true;
    }

    bool dfsLoop(
        vector<vector<int>>& edge,
        int i,
        vector<int>& status
    ) {

        // Mark current course as active.
        // It is now part of the current DFS path.
        status[i] = 1;

        // Visit all prerequisite courses
        for (int j = 0; j < edge[i].size(); j++) {

            int next = edge[i][j];

            // If this node is already active,
            // we have returned to a node in the
            // current DFS path -> cycle detected.
            if (status[next] == 1) {
                return true;
            }

            // If this node has not been visited,
            // explore it using DFS.
            else if (status[next] == 0) {

                if (dfsLoop(edge, next, status)) {
                    return true;
                }
            }

            // If status == 2, this node has already
            // been completely processed and does not
            // need to be explored again.
        }

        // All prerequisites have been processed.
        // Mark this course as completely processed.
        status[i] = 2;

        return false;
    }
};
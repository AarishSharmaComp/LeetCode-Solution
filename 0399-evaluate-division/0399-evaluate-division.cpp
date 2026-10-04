class Solution {
public:
    double dfs(
        string curr,
        string target,
        unordered_map<string, vector<pair<string, double>>>& graph,
        unordered_set<string>& visited
    ) {
        if (curr == target)
            return 1.0;

        visited.insert(curr);

        for (auto& [next, value] : graph[curr]) {
            if (visited.count(next))
                continue;

            double result = dfs(next, target, graph, visited);

            if (result != -1.0)
                return value * result;
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];

            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0 / value});
        }

        vector<double> answer;

        // Process queries
        for (auto& query : queries) {
            string start = query[0];
            string target = query[1];

            if (!graph.count(start) || !graph.count(target)) {
                answer.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;

            answer.push_back(
                dfs(start, target, graph, visited)
            );
        }

        return answer;
    }
};
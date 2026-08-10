class Solution {
public:
    int find(int x, vector<int>& par) {
        if (x == par[x])
            return x;

        return par[x] = find(par[x], par);
    }

    void unite(int x1, int x2, vector<int>& par, vector<int>& rank) {
        int p1 = find(x1, par);
        int p2 = find(x2, par);

        if (p1 == p2)
            return;

        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts
    ) {
        int n = accounts.size();

        vector<int> par(n);
        vector<int> rank(n, 1);

        for (int i = 0; i < n; i++)
            par[i] = i;

        // email -> account index
        unordered_map<string, int> mpp;

        // Step 1: Union accounts having common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (mpp.count(email)) {
                    unite(i, mpp[email], par, rank);
                }
                else {
                    mpp[email] = i;
                }
            }
        }

        // Step 2: Group emails according to their DSU leader
        vector<vector<string>> emailGroup(n);

        for (auto& [email, index] : mpp) {
            int leader = find(index, par);
            emailGroup[leader].push_back(email);
        }

        // Step 3: Build answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (emailGroup[i].empty())
                continue;

            sort(emailGroup[i].begin(), emailGroup[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (string& email : emailGroup[i])
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};
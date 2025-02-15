//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    static bool comp(vector<int>& v1, vector<int>& v2) {
        return v1[2] > v2[2]; // Sorting by profit in descending order
    }

    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        int n = id.size();
        vector<vector<int>> jobs(n);
        
        for (int i = 0; i < n; i++) {
            jobs[i] = {id[i], deadline[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end(), comp);
        
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i][1]);
        }
        
        vector<int> slot(maxDeadline + 1, -1);
        int countJobs = 0, totalProfit = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i][1]; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = jobs[i][0];
                    countJobs++;
                    totalProfit += jobs[i][2];
                    break;
                }
            }
        }
        
        return {countJobs, totalProfit};
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int atleastK(string& s, int k){
        map<int,int> mp;
        int n = s.length();
        int j = 0;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            while( j < n && mp.size() < k){
                mp[s[j++]]++;
            }
            // cout<<i<<" "<<j<<endl;
            if(mp.size() == k) cnt+= n - j +1;
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
        }
        
        return cnt;
    }
    
    int countSubstr(string& s, int k) {
        return atleastK(s,k) - atleastK(s,k+1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
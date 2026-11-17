#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    string removeConsecutive(string s) {
        bool flag = true;
        while (flag) {
            flag = false;
            int i = 0;
            for (int j = 0; j <= s.length(); j++) {
                if (j == s.length() || s[j] != s[i]) {
                    if (j - i >= 3) {
                        s.erase(i, j - i);
                        flag = true;
                        break;
                    }
                    i = j;
                }
            }
        }
        return s;
    }

    int solve(string board, unordered_map<char, int>& hand, unordered_map<string, int>& memo) {
        board = removeConsecutive(board);
        if (board == "") return 0;
        
        string key = board + "_" + to_string(hand['R']) + to_string(hand['Y']) +
                     to_string(hand['B']) + to_string(hand['G']) + to_string(hand['W']);
        
        if (memo.find(key) != memo.end()) return memo[key];
        
        int ans = INT_MAX;
        int n = board.length();
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && board[j] == board[i]) j++;
            char color = board[i];
            int len = j - i;
            int req = max(0, 3 - len);
            
            if (hand[color] >= req) {
                hand[color] -= req;
                string next_board = board.substr(0, i) + board.substr(j);
                int res = solve(next_board, hand, memo);
                if (res != -1) {
                    ans = min(ans, res + req);
                }
                hand[color] += req;
            }
            i = j;
        }
        
        memo[key] = (ans == INT_MAX) ? -1 : ans;
        return memo[key];
    }

public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> hand_count;
        for (char c : hand) hand_count[c]++;
        unordered_map<string, int> memo;
        return solve(board, hand_count, memo);
    }
};

int main() {
    Solution obj;
    string board = "WWRRBBWW";
    string hand = "WRBRW";
    cout << "Output: " << obj.findMinStep(board, hand) << endl;
    return 0;
}
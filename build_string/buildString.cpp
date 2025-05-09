// Greg wants to build a string, S of length N. Starting with an empty string, he can perform 2 operations:

// Add a character to the end of S for A dollars.
// Copy any substring of S, and then add it to the end of S for B dollars.
// Calculate minimum amount of money Greg needs to build .

// Input Format

// The first line contains number of testcases .

// The  subsequent lines each describe a test case over  lines:
// The first contains  space-separated integers, N,  A, and B, respectively.
// The second contains  (the string Greg wishes to build).

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int buildString(int a, int b, string s)
{
    int cost = 0;
    vector<string> substrings;
    int i = 0;
    while (i < s.size() - 1)
    {
        string substringToAppend = "";
        string longestSubstring = "";
        for (int l = substrings.size() - 1; l > 0; l--)
        {
            string substring = substrings[l];
            if(longestSubstring.size() > substring.size()){
                break;
            }
            int startPoint = 0;
            for (int j = 0; j < substring.size(); j++)
            {
                if (substring[j] == s[i])
                {
                    startPoint = j;
                    break;
                }
            }
            int k = 0;
            for (int j = startPoint; j < substring.size(); j++)
            {
                if (substring[j] == s[i + k])
                {
                    substringToAppend += s[i + j];
                }
                else
                {
                    break;
                }
                k++;
            }
            if (substringToAppend.size() > longestSubstring.size())
            {
                longestSubstring = substringToAppend;
            }
        }

        if (longestSubstring.size() == 0)
        {
            longestSubstring += s[i];
        }

        int letterCost = longestSubstring.size() * a;
        if (letterCost > b)
        {
            cost += b;
        }
        else
        {
            cost += letterCost;
        }
        if (substrings.size() != 0)
        {
            string newSubstring = substrings[substrings.size() - 1] + longestSubstring;
            substrings.push_back(newSubstring);
        }
        else
        {
            substrings.push_back(longestSubstring);
        }

        i += longestSubstring.size();
    }
    cout << cost << endl;

    return cost;
}





int main(int argc, char *argv[])
{
    // string firstStr = "aabaacaba";
    // int letterCost = 4;
    // int substringCost = 5;
    // buildString(letterCost, substringCost, firstStr);

    string str2 = "bacbacacb";
    int letterCost2 = 8;
    int substringCost2 = 9;
    buildString(letterCost2, substringCost2, str2);

    return 0;
}
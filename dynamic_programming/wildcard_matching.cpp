/*
problem statement: https://leetcode.com/problems/wildcard-matching/

sample input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
*/

#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) {
    
    int p1=-1,p2=-1;
    
    int i =0,j=0;
    
    int len_s = s.size();
    int len_p = p.size();

    while(1)
    {
        if(i>=len_s)
        {
            while(j<len_p && p[j]=='*') j++;
            break;
        }
        if(j>=len_p)
        {
            if(p1!=-1)
            {
                j = p1+1;
                i = ++p2;
                continue;
            }
            else break;
        }
        
        if(p[j]=='?' || s[i]==p[j])
        {
            i++;
            j++;
        }
        else if(p[j]=='*')
        {
            p1 = j++;
            p2 = i;
        }
        else if(s[i]!=p[j] )
        {
            if(p1!=-1)
            {
                j= p1+1;
            i = ++p2;
            }
            else break;
            
        }
        
    }
    if(i==len_s && j==len_p) return true;
    
    return false;
    
}

int main()
{
    string s,p;
    cin >> s >> p;
    cout << isMatch(s,p) << endl;

    return 0;
}

//Reverse words in string
#include<bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
       reverse(s.begin(), s.end());
       for(int i=0;i<n;i++){
        string words = "";
       while(i<n && s[i]!=' '){
            words+=s[i];
            i++;
       }

       reverse(words.begin(), words.end());
       if(words.length()>0){
            ans+=" "+words;
       }

       }

        return ans.substr(1);
    }
};





//Largest Odd Number in String

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};


//Longest common prefix

//Brute Force
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string a = strs[0];
        
        string ans = "";
        for(int i=1;i<=strs.size()-1;i++){
            string b = strs[i];
            string c = "";
            if(!b.empty() && !b.empty()){
            for(int j=0;j<=min(a.size(),b.size())-1;j++){
                if(a[j]==b[j]){
                    c+=b[j];
                }
                else{
                    break;
                }
            }
            }
                a=c;
        }

        if(a.empty()){
            return "";
        }

        return a;
    }
};




// Optimal Solution

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string a = strs[0];
        string b = strs[strs.size()-1];

        string ans = "";
        if(!a.empty() && !b.empty()){
        for(int i=0;i<min(a.size(), b.size());i++){
            if(a[i]!=b[i]){
                break;
            }
            else{
                ans+=a[i];
            }
        }

        }

        if(ans.empty()){
            return "";
        }

        return ans;

    }
};




//Isomorphic string

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.size()!=t.size()) return false;
        int  n = s.size();
        unordered_map<char, char> mp;
        unordered_map<char, char> mp2;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
            else if(mp2.find(t[i])!=mp.end()){
                if(mp2[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
                mp[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
             
        }
        return true;
        
    }
};


//valid anagrams

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;

        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;

        for(int i=0;i<n;i++){
            mp[s[i]]+=1;
            mp2[t[i]]+=1;
        }

        return mp==mp2;
    }
};








//Rotated String

//Brute Force  
class Solution {
public:
    bool rotateString(string st, string goal) {
        int n = st.size();
        string s = st;
        for(int i=0;i<n;i++){
            reverse(s.begin(), s.begin()+i+1);
            reverse(s.begin()+i+1, s.end());
            reverse(s.begin(), s.end());

            cout<<s;

            if(s==goal){
                return true;
            }
            else{
                s=st;
            }
        }

        return false;
    }
};



//OPTIMAL 

class Solution {
public:
    bool rotateString(string st, string goal) {
        int n = st.size();
        if(st.size()!=goal.size()) return false;
        string s = st+st;
        return s.find(goal) != string::npos;
    }
};






//Remove outermost parenthesis

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        int c =0;
        for(int i=0;i<n;i++){
            if(s[i]==')') c--;
            if(c!=0) ans.push_back(s[i]);
            if(s[i]=='(') c++;
        }

        return ans;
    }
};










//Roman to Integer

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(mp[s[i]]>=mp[s[i+1]]) ans+=mp[s[i]];
            else   ans-=mp[s[i]];
        }

        return ans+mp[s[n-1]];
    }
};




//ATOI
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if(n == 0) return 0;
        
        int i = 0;
        while(i < n && s[i] == ' ') i++;  // skip spaces
        
        if(i == n) return 0;  // all spaces
        
        int sign = 1;
        if(s[i] == '-') {
            sign = -1;
            i++;
        } else if(s[i] == '+') {
            i++;
        }
        
        long ans = 0;
        while(i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if(sign == 1 && ans > INT_MAX) return INT_MAX;
            if(sign == -1 && -ans < INT_MIN) return INT_MIN;
            i++;
        }
        
        return static_cast<int>(ans * sign);
    }
};
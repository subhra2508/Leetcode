//Given an array of strings words and an integer k, return the k most frequent strings.

//Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.


//Example 1:

//Input: words = ["i","love","leetcode","i","love","coding"], k = 2
//Output: ["i","love"]
//Explanation: "i" and "love" are the two most frequent words.
//Note that "i" comes before "love" due to a lower alphabetical order.

class Solution {
public:
   static  bool sortBysec(pair<string,int>&a,pair<string,int>&b){
        if(a.second != b.second){
            return (a.second > b.second);
        }
       else{
           return (a.first < b.first);
       }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto wrd:words){
            mp[wrd]++;
        }
        vector<pair<string,int>>v;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
           v.push_back(make_pair(itr->first,itr->second));
        }
        sort(v.begin(),v.end(),sortBysec);
        vector<string>str;
        int count = 0;
        for(auto wrds:v){
            if(count < k){
                str.push_back(wrds.first);
                count++;
            }
        }
        return str;
    }
};
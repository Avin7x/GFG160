class Solution {
  public:
//   function to compute lps 
  void findLps(string& s2, vector<int>& lps, int pre, int suf){
      
      while(suf < s2.size()){
          if(s2[pre] == s2[suf]){
              lps[suf] = pre+1;
              pre++, suf++;
          }
          else{
              if(pre == 0){
                  lps[suf] = 0;
                  suf++;
              }
              else{
                  pre = lps[pre-1];
              }
          }
      }
  }
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        
        //concatenate the string s1 twice 
        //and store it in a temp string
        
        //now check if string s2 is present inside 
        //this temp string using kmp algorithm 
        
        string temp = s1+s1;
      
        
        
        //compute the lps array for s2 string  
        vector<int>lps(s2.size(), 0);
        findLps(s2, lps, 0, 1);
        
        //check if string s2 in present in temp
        int left =0, right =0;
        
        while(left < temp.size() && right < s2.size()){
            if(temp[left] == s2[right]){
                left++, right++;
            }
            
            else{
                if(right == 0){
                    left++;
                }
                else{
                    right = lps[right-1];
                }
            }
            
            if(right == s2.size()){
                return true;
            }
        }
        
        return false;
        
    }
};

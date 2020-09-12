class Solution {
public:
    int compress(vector<char>& chars) {
        
        if(chars.size() <= 1)return chars.size();
        
        int consecutiveCharacters = 0;
        string compressedString = "";
        for(int i=0;i<(int) chars.size();i++){
            consecutiveCharacters++;
            
            if(i+1 >= chars.size() || chars[i] != chars[i+1]){
                compressedString += (chars[i]);
                if(consecutiveCharacters>1)compressedString += std::to_string(consecutiveCharacters);
                consecutiveCharacters = 0 ;
            }
        }
        
        chars.erase(chars.begin(),chars.end());
        for(int i=0;i<(int)compressedString.size();i++)chars.push_back(compressedString[i]);
        return chars.size();
    }
};

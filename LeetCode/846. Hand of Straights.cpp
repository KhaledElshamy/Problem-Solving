bool flag = false ;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
       
        if(hand.size() % W != 0)return false ;
        
        map<int,int> m;
        
        for(int i=0;i<(int)hand.size();i++){
            m[hand[i]]++;
        }
        
        
        while(m.size()>0){
            int min_val = m.begin()->first;
            for(int card = min_val; card < min_val + W;card++){
                if(m[card]==0) return false; 
                int count = m [card];
                if(count == 1){
                    m.erase(card);
                }else m[card]--;
            }
        }
        
        return true ;
    }
};

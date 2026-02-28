class Solution {
public:
    int numberOfSubstrings(string s) {

        int count = 0;
        int lastSeen[3] = {-1, -1, -1};
        // a , b , c

        for( int i = 0 ; i < s.size() ; i++) {
            lastSeen[s[i] - 'a'] = i;  // convert a -> 0 and so b = 1 , c = 2
            // stored last seen index
            
            // if all 3 are seen
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count = count + (1 + min( min(lastSeen[0], lastSeen[1]) , lastSeen[2]));
                // IF ALL 3 ARE FOUND, ALL PREVIOUS SUBSTRING WILL BE VALID TOO

                //  EG: ab"abc"  --( VALID 1 )
                /*
                    "babc" also valid  --( VALID 2 )
                    "ababc" also valid   --( VALID 3 )

                    last seen minimum => a => index = "2"
                    count += 3 (1 + "2")   for that eg

                */
            }
        }

        return count;
    }
};
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int ret = low;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int val = guess(mid);
            // cout << mid << " " << val << endl;
            if(val == -1){
                high = mid - 1;
            }else if(val == 1){
                low = mid + 1;
                
            }else{
                return mid;
            }
        }
        return ret;
    }
};
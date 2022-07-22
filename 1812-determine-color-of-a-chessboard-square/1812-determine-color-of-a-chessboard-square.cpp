class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = (int)coordinates[0], y = (int)coordinates[1];
        return (((x+y)% 2) == 0)? false : true;
    }
};
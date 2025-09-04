class Solution {
public:
    int findClosest(int x, int y, int z) {

        if (x == y)
        {
            return 0;
        }
        
        if (x == z)
        {
            return 1;
        }

        if (y == z)
        {
            return 2;
        }
        
        while (true)
        {
            if (x > z) { x--;} 
            else { x++; }

            if (y > z) { y--; }
            else { y++; }

            //Check
            if (x == y)
            {
                return 0;
            }
            
            if (x == z)
            {
                return 1;
            }

            if (y == z)
            {
                return 2;
            }
        }
    }
};
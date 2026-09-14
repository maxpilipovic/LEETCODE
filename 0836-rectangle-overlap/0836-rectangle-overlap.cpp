class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        
        int a_x1 = rec1[0];
        int a_x2 = rec1[2];
        int a_y1 = rec1[1];
        int a_y2 = rec1[3];

        int b_x1 = rec2[0];
        int b_x2 = rec2[2];
        int b_y1 = rec2[1];
        int b_y2 = rec2[3];

        //rec1 is entirely to the left of rec2
        if (a_x2 <= b_x1) 
        {
            return false;
        }

        //rec1 is entirely to the right of rec2
        if (a_x1 >= b_x2) 
        {  
            return false;
        }

        //rec1 is entirely below rec2
        if (a_y2 <= b_y1) 
        {
            return false;
        }

        //rec1 is entirely above rec2
        if (a_y1 >= b_y2) 
        {   
            return false;
        }

        return true;
    }
};
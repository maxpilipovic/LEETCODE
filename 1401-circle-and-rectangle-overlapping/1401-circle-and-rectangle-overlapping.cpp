class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) 
    {
        //Clamp
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        //Pythag theorem. x^2 + y^2 <= r2
        return (dx * dx) + (dy * dy) <= radius * radius;
    }

private:

};
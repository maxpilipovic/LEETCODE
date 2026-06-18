class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        double minuteAngle = minutes * 6; //6degrees each minute.
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5; //each hour = 30 degrees

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = hour;
        double minu = minutes;
        double hourAngle = h * 30 + ((minu * 6) / 360) * 30;
        double minutesAngle = (minu * 6);

        return min(abs(hourAngle - minutesAngle), 360 - abs(hourAngle - minutesAngle));
    }
};
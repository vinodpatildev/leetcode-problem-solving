class Solution {
public:
    int dimConstraint = 1e4;
    int volumeConstraint = 1e9;
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false, heavy = false;
        if(length >= dimConstraint || width >= dimConstraint || height >= dimConstraint) bulky = true;
        else{
            long long volume = (long long)length * width * height;
            if(volume >= volumeConstraint) bulky = true;
        }
        if(mass >= 100) heavy = true;
        if(bulky && heavy) return "Both";
        else if(bulky) return "Bulky";
        else if(heavy) return "Heavy";
        return "Neither";
    }
};
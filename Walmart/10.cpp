// submission link: https://leetcode.com/submissions/detail/631035057/

class Solution {
public:
    
    double x,y,r;

    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double len;
        double theta;
        
        double rand_no = (double) rand() / RAND_MAX;
        theta = 2*rand_no*3.141592653589793238;
        
        rand_no = (double) rand() / RAND_MAX; 
        len =  sqrt(rand_no) * r;
        
        double xx = x+len*cos(theta);
        double yy = y+len*sin(theta);
        // add xx and yy as points may or may not be at the origin         
        
        return vector<double>{xx, yy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
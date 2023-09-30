#include <algorithm>
#include <iostream>

class Point{
public: 
    const int x;
    const int y;
public:
    Point() : x(0), y(0) { }
    Point(const int x, const int y) : x(x), y(y) { }
public:
    Point minx(Point const & rhs) const {
        Point ans = Point(std::min(x, rhs.x), y);
        return ans;
    }
    Point maxx(Point const & rhs) const {
        Point ans = Point(std::max(x, rhs.x), y);
        return ans;
    }
    Point miny(Point const & rhs) const {
        Point ans = Point(x, std::min(rhs.y, y));
        return ans;
    }
    Point maxy(Point const & rhs) const {
        Point ans = Point(x, std::max(rhs.y, y));
        return ans;
    }
};

int main(){
    auto a = Point(1, 2);
    auto b = Point(2, 1);
    a.maxy(b);
    a.miny(b);
    a.maxx(b);
    a.minx(b);
    return 0;
}
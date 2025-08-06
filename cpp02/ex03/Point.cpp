#include "Point.hpp"


Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(Point const &src) : _x(src._x), _y(src._y) {}

Point::~Point() {}

Point &Point::operator=(Point const &rhs) {
    (void)rhs; // const members cannot be assigned
    return *this;
}

Fixed const &Point::getX() const {
    return _x;
}

Fixed const &Point::getY() const {
    return _y;
}

// Helper function to calculate the area of a triangle using cross product
static Fixed area(Point const a, Point const b, Point const c) {
    Fixed area = ((a.getX() * (b.getY() - c.getY())) + 
                  (b.getX() * (c.getY() - a.getY())) + 
                  (c.getX() * (a.getY() - b.getY()))) / 2;
    
    return (area < 0) ? area * -1 : area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = area(a, b, c);
    Fixed areaPBC = area(point, b, c);
    Fixed areaAPC = area(a, point, c);
    Fixed areaABP = area(a, b, point);
    
    // If any of the sub-areas is 0, the point is on an edge or vertex
    if (areaPBC == 0 || areaAPC == 0 || areaABP == 0)
        return false;
    
    // If the sum of sub-areas equals the main triangle area, point is inside
    return (areaPBC + areaAPC + areaABP == areaABC);
}




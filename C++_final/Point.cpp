#include <cmath>

#include <cmath>
#include <iostream>
#include "Point.hpp"

namespace Engine {
    Point::Point() : Point(0, 0) {}
    Point::Point(float x, float y) : x(x), y(y) {}
    bool Point::operator==(const Point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool Point::operator!=(const Point& rhs) const {
        return !operator==(rhs);
    }
    Point Point::operator+(const Point& rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point Point::operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point Point::operator*(const float& rhs) const {
        return Point(x * rhs, y * rhs);
    }
    Point Point::operator/(const float& rhs) const {
        return Point(x / rhs, y / rhs);
    }
    Point Point::Normalize() const {
        if (Magnitude() == 0)
            return Point();
        return Point(x, y) / Magnitude();
    }
    float Point::Dot(const Point& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    float Point::MagnitudeSquared() const {
        return x * x + y * y;
    }
    float Point::Magnitude() const {
        return std::sqrt(MagnitudeSquared());
    }
	float Point::operator%( const Point & rhs ) const{
		return sqrt(pow( x - rhs.x, 2 )  + pow( y - rhs.y, 2 )) ;
	}
    
    Point operator*(const float& lhs, const Point& rhs) {
        return rhs * lhs;
    }

    Point Point::normalR() {
        return Point(y, -x);
    }
    float Point::projectLengthOnto(Point& p) {
        return (x * p.x + y * p.y) / p.Magnitude();
    }
	
	std::ostream& operator<<(std::ostream& os, Engine::Point p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
}

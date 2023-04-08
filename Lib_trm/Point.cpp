#include "Point.h"
#include <iostream>
#include<math.h>

Point::Point()
{
	
}
Point::Point(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;

}

void Point::setX(double x) {
	this->x = x;
}

double Point::getX()const {
	return this->x;
}

void Point::setY(double y) {
	this->y = y;
}

double Point::getY()const {
	return this->y;
}

void Point::setZ(double z) {
	this->z = z;
}

double Point::getZ() const {
	return this->z;
}

bool Point::operator==(const Point& other) const {
	if (this->x == other.x && this->y == other.y && this->z == other.z)
		return true;
	else
		return false;
}







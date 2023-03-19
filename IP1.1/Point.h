#pragma once
class Point
{
private:
	double x, y, z;
public:
	
	Point();
	Point(double,double,double);

	void setX(double x);
	double getX() const;

	void setY(double y);
	double getY() const;

	void setZ(double z);
	double getZ() const;

	bool operator==(const Point& p) const;
	const double distance(const Point&);
};


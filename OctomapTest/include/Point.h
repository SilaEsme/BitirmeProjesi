#pragma once
class Point
{
private:
	double x, y, z;
public:

	Point();
	Point(double, double, double);

#pragma region Sets
	void setX(double x);
	void setY(double y);
	void setZ(double z);
#pragma endregion

#pragma region Gets
	double getX() const;
	double getY() const;
	double getZ() const;
#pragma endregion

	bool operator==(const Point& p) const;
};
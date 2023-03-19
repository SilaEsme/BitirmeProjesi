#include "Point.h"
#include <iostream>
#include<math.h>

using namespace std;
//Constructor fonksiyonu

Point::Point()
{
	
}
Point::Point(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;

}

//Bu fonk. point s�n�f� i�indeki x de�i�kenine atama i�lemi yapar.
void Point::setX(double x) {
	this->x = x;
}
//Bu fonk poin s�n�f� i�indeki x de�i�kenine eri�im imkan� sa�lar.
double Point::getX()const {
	return this->x;
}

//Bu fonk. point s�n�f� i�indeki y de�i�kenine atama i�lemi yapar.
void Point::setY(double y) {
	this->y = y;
}
//Bu fonk poin s�n�f� i�indeki y de�i�kenine eri�im imkan� sa�lar.
double Point::getY()const {
	return this->y;
}
//Bu fonk. point s�n�f� i�indeki z de�i�kenine atama i�lemi yapar.
void Point::setZ(double z) {
	this->z = z;
}
//Bu fonk poin s�n�f� i�indeki z de�i�kenine eri�im imkan� sa�lar.
double Point::getZ() const {
	return this->z;
}
//Bu fonksiyon iki pointin birbirine e�it olup olmad���n� kontrol eder. E�itse true d�nd�r�r, de�ilse false.
bool Point::operator==(const Point& other) const {
	if (this->x == other.x && this->y == other.y && this->z == other.z)
		return true;
	else
		return false;
}

//Bu fonk iki adet Pointin birbirine uzakl���n� hesaplar ve d�nd�r�r.
const double Point::distance(const Point& pcl) {

	return sqrt(pow((this->x - pcl.x), 2) + pow((this->y - pcl.y), 2) + pow((this->z - pcl.z), 2));
}






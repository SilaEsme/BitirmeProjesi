#include <iostream>
#include <fstream>
#include "PointCloud.h"


PointCloud::PointCloud()
{
}

PointCloud::PointCloud(std::string path)
{
	SetPath(path);
}
PointCloud::PointCloud(std::string path, std::vector<std::vector<double>> rotMatrix, Eigen::Vector3d translationMatrix)
{
	SetPath(path);
	ReadCloudFromFile();
	SetRotationMatrix(rotMatrix);
	SetTranslationMatrix(translationMatrix);
	CreateTransformationMatrix();
}
void PointCloud::SetPath(std::string path)
{
	_path = path;
}
void PointCloud::SetRotationMatrix(std::vector<std::vector<double>> matrix)
{
	_rotationMatrix = matrix;
}
void PointCloud::SetTranslationMatrix(Eigen::Vector3d matrix)
{
	_translationMatrix = matrix;
}
std::vector<Point> PointCloud::GetPointCloud()
{
	return _pointCloud;
}
std::string PointCloud::GetPath()
{
	return _path;
}
//std::vector<std::vector<double>> PointCloud::GetRotationMatrix()
//{
//	return _rotationMatrix;
//}
//Eigen::Vector3d PointCloud::GetTranslationMatrix()
//{
//	return _translationMatrix;
//}
Eigen::Matrix4d PointCloud::GetTransformationMatrix()
{
	return _transformationMatrix;
}
void PointCloud::CreateTransformationMatrix()
{
	if (_rotationMatrix.empty() or !_translationMatrix.size())
	{
		std::cerr << "Invalid operation. First define and set rotation and translation matrices." << std::endl;
		return;
	}
	
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			_transformationMatrix(i, j) = _rotationMatrix[i][j];
		}
	}
	_transformationMatrix(3, 0) = 0;
	_transformationMatrix(3, 1) = 0;
	_transformationMatrix(3, 2) = 0;
	_transformationMatrix(3, 3) = 1;
	_transformationMatrix(0, 3) = _translationMatrix[0];
	_transformationMatrix(1, 3) = _translationMatrix[1];
	_transformationMatrix(2, 3) = _translationMatrix[2];

}
void PointCloud::ReadCloudFromFile()
{
	std::ifstream file(_path);

	std::string tempString;
	Point P;
	if (file.is_open()) {

		// Read first 2 line for no reason (First two line)
		getline(file, tempString);
		getline(file, tempString);

		// Read whole file
		while (!file.eof())
		{
			file >> tempString;
			P.setX(stod(tempString));

			file >> tempString;
			P.setY(stod(tempString));

			file >> tempString;
			P.setZ(stod(tempString));

			_pointCloud.push_back(P);


			// Read 3 times for no reason (RGB)
			file >> tempString;
			file >> tempString;
			file >> tempString;

		} // end-while
		file.close();
	} // end-if
}
void PointCloud::PrintPointCloud()
{
	for (auto v : _pointCloud)
	{
		std::cout << "X:" << v.getX() << " Y: " << v.getY() << " Z: " << v.getZ() << std::endl;
	}
}
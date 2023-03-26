#include <iostream>
#include <fstream>
#include "PointCluster.h"


PointCluster::PointCluster()
{
}

PointCluster::PointCluster(std::string path)
{
	SetPath(path);
}
PointCluster::PointCluster(std::string path, std::vector<std::vector<double>> rotMatrix, Eigen::Vector3d translationMatrix)
{
	SetPath(path);
	ReadClusterFromFile();
	SetRotationMatrix(rotMatrix);
	SetTranslationMatrix(translationMatrix);
	CreateTransformationMatrix();
}
void PointCluster::SetPath(std::string path)
{
	_path = path;
}
void PointCluster::SetRotationMatrix(std::vector<std::vector<double>> matrix)
{
	_rotationMatrix = matrix;
}
void PointCluster::SetTranslationMatrix(Eigen::Vector3d matrix)
{
	_translationMatrix = matrix;
}
std::vector<Point> PointCluster::GetPointCluster()
{
	return _pointCluster;
}
std::string PointCluster::GetPath()
{
	return _path;
}
//std::vector<std::vector<double>> PointCluster::GetRotationMatrix()
//{
//	return _rotationMatrix;
//}
//Eigen::Vector3d PointCluster::GetTranslationMatrix()
//{
//	return _translationMatrix;
//}
Eigen::Matrix4d PointCluster::GetTransformationMatrix()
{
	return _transformationMatrix;
}
void PointCluster::CreateTransformationMatrix()
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
void PointCluster::ReadClusterFromFile()
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

			_pointCluster.push_back(P);


			// Read 3 times for no reason (RGB)
			file >> tempString;
			file >> tempString;
			file >> tempString;

		} // end-while
		file.close();
	} // end-if
}

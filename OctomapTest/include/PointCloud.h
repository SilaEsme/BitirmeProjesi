#pragma once
#include <vector>
#include <string>
#include <eigen3/Eigen/Dense>
#include "Point.h"

class PointCloud //txt
{
private:
	std::vector<Point> _pointCloud;
	std::vector<std::vector<double>> _rotationMatrix;
	Eigen::Vector3d _translationMatrix;
	Eigen::Matrix4d _transformationMatrix;
	std::string _path;
public:
	PointCloud();
	PointCloud(std::string path);
	PointCloud(std::string path, std::vector<std::vector<double>> rotMatrix, Eigen::Vector3d translationMatrix);

#pragma region Sets
	void SetPath(std::string path);
	void SetRotationMatrix(std::vector<std::vector<double>> matrix);
	//void SetRotationMatrix();
	void SetTranslationMatrix(Eigen::Vector3d matrix);
	//void SetTranslationMatrix();
#pragma endregion

#pragma region Gets
	std::vector<Point> GetPointCloud();
	std::string GetPath();
	//std::vector<std::vector<double>> GetRotationMatrix();
	//Eigen::Vector3d GetTranslationMatrix();
	Eigen::Matrix4d GetTransformationMatrix();
#pragma endregion
	void CreateTransformationMatrix();
	void ReadCloudFromFile();
	void PrintPointCloud();
};

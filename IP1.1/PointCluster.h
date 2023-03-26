#pragma once
#include <vector>
#include <string>
#include <Eigen/Dense>
#include "Point.h"

class PointCluster //txt
{
private:
	std::vector<Point> _pointCluster;
	std::vector<std::vector<double>> _rotationMatrix;
	Eigen::Vector3d _translationMatrix;
	Eigen::Matrix4d _transformationMatrix;
	std::string _path;
public:
	PointCluster();
	PointCluster(std::string path);
	PointCluster(std::string path, std::vector<std::vector<double>> rotMatrix, Eigen::Vector3d translationMatrix);

	#pragma region Sets
		void SetPath(std::string path);
		void SetRotationMatrix(std::vector<std::vector<double>> matrix);
		//void SetRotationMatrix();
		void SetTranslationMatrix(Eigen::Vector3d matrix);
		//void SetTranslationMatrix();
	#pragma endregion

	#pragma region Gets
		std::vector<Point> GetPointCluster();
		std::string GetPath();
		//std::vector<std::vector<double>> GetRotationMatrix();
		//Eigen::Vector3d GetTranslationMatrix();
		Eigen::Matrix4d GetTransformationMatrix();
	#pragma endregion
	void CreateTransformationMatrix();
	void ReadClusterFromFile();
};


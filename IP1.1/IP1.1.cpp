// IP1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Point.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Eigen/Dense>


std::vector<Point> ReadPointsFromFile(std::string fileDir);
void PrintPointCloud(std::vector<Point> list);
std::vector<std::vector<double>> SelectRotationMatrix(int selector);
Eigen::Vector3d SelectTranslationMatrix(int selector);
Eigen::Matrix4d CreateTransMatrix(std::vector<std::vector<double>> rotationMatrix, Eigen::Vector3d translationMatrix);
std::vector<Point> DoTransform(std::vector<Point> pointCloud, Eigen::Matrix4d transMatrix);
void CreateCloudFile(std::vector<Point> pointCloud, std::string fileDir);

int main()
{
	std::cout << "Process starting..." << std::endl;
	std::vector<Point> p1 = ReadPointsFromFile("Clouds/cam.txt");
	std::vector<Point> p2 = ReadPointsFromFile("Clouds/cam1.txt");
	std::vector<Point> p3 = ReadPointsFromFile("Clouds/cam2.txt");
	std::vector<Point> p4 = ReadPointsFromFile("Clouds/cam3.txt");

	CreateCloudFile(DoTransform(p1, CreateTransMatrix(SelectRotationMatrix(0), SelectTranslationMatrix(0))),"Clouds/cam_transformed.txt");
	CreateCloudFile(DoTransform(p2,CreateTransMatrix(SelectRotationMatrix(1),SelectTranslationMatrix(1))), "Clouds/cam1_transformed.txt");
	CreateCloudFile(DoTransform(p3,CreateTransMatrix(SelectRotationMatrix(2),SelectTranslationMatrix(2))), "Clouds/cam2_transformed.txt");
	CreateCloudFile(DoTransform(p4,CreateTransMatrix(SelectRotationMatrix(3),SelectTranslationMatrix(3))), "Clouds/cam3_transformed.txt");

	std::cout << "The end." << std::endl;

	return 0;
}

std::vector<Point> ReadPointsFromFile(std::string fileDir)
{
	std::ifstream file(fileDir);

	std::string tempString;
	Point P;
	std::vector<Point> pointList;
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

			pointList.push_back(P);


			// Read 3 times for no reason (RGB)
			file >> tempString;
			file >> tempString;
			file >> tempString;

		} // end-while
		file.close();
	} // end-if
	
	return pointList;
}
void PrintPointCloud(std::vector<Point> list)
{
	for (auto v : list)
	{
		std::cout << "X:" << v.getX() << " Y: " << v.getY() << " Z: " << v.getZ() << std::endl;
	}
}
std::vector<std::vector<double>> SelectRotationMatrix(int selector)
{
	std::vector<std::vector<double>> camRot = {
		{ -0.7076050, 0.0065031, -0.7065783},
		{ 0.7066082, 0.0065134, -0.7075750},
		{ 0.0000008, -0.9999576, -0.0092041}

	};
	std::vector<std::vector<double>> cam1Rot = {
		 { -0.6638364, -0.0068830, 0.7478462},
		 { -0.7478778, 0.0061099, -0.6638082},
		 { -0.0000002, -0.9999576, -0.0092036}

	};
	std::vector<std::vector<double>> cam2Rot = {
		 {0.8762180, 0.0044351, -0.4818945 },
		 {0.4819149, -0.0080638, 0.8761809},
		{0.0000001, -0.9999577, -0.0092030}

	};
	std::vector<std::vector<double>> cam3Rot = {
		 { 0.3597052, -0.0085871, 0.9330265 },
		 {-0.9330660, -0.0033108, 0.3596900},
		 {0.0000003, -0.9999576, -0.0092033}
	};
	switch (selector)
	{
		case 0:
			return camRot;
		case 1:
			return cam1Rot;
		case 2:
			return cam2Rot;
		case 3:
			return cam3Rot;
		default:
			break;
	}
}
Eigen::Vector3d SelectTranslationMatrix(int selector)
{
	Eigen::Vector3d camTr(1.95704, 1.9300, 1.05707);
	Eigen::Vector3d cam1Tr(-1.91288, 1.94412, 1.05465);
	Eigen::Vector3d cam2Tr(1.96978, -1.94622, 1.05264);
	Eigen::Vector3d cam3Tr(-1.87445, -1.95027, 1.06432);
	switch (selector)
	{
	case 0:
		return camTr;
	case 1:
		return cam1Tr;
	case 2:
		return cam2Tr;
	case 3:
		return cam3Tr;
	default:
		break;
	}
}
Eigen::Matrix4d CreateTransMatrix(std::vector<std::vector<double>> rotationMatrix, Eigen::Vector3d translationMatrix)
{
	Eigen::Matrix4d transMatrix;

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			transMatrix(i, j) = rotationMatrix[i][j];
		}
	}
	transMatrix(3, 0) = 0;
	transMatrix(3, 1) = 0;
	transMatrix(3, 2) = 0;
	transMatrix(3, 3) = 1;
	transMatrix(0, 3) = translationMatrix[0];
	transMatrix(1, 3) = translationMatrix[1];
	transMatrix(2, 3) = translationMatrix[2];

	return transMatrix;

}
std::vector<Point> DoTransform(std::vector<Point> pointCloud, Eigen::Matrix4d transMatrix)
{
	Eigen::Vector4d eigenPoint;
	Eigen::Vector4d transEigenPoint;
	std::vector<Point> transformedCloud;

	for (auto v: pointCloud)
	{
		Eigen::Vector4d eigenPoint(v.getX(), v.getY(), v.getZ(), 1);

		transEigenPoint = transMatrix * eigenPoint;

		Point transformedPoint(transEigenPoint(0), transEigenPoint(1), transEigenPoint(2));
		transformedCloud.push_back(transformedPoint);
	}
	return transformedCloud;

}
void CreateCloudFile(std::vector<Point> pointCloud,std::string fileDir) 
{
	std::ofstream outputFile(fileDir);

	if (outputFile.is_open())
	{
		for (auto v : pointCloud)
		{
			outputFile << v.getX() << " " << v.getY() << " " << v.getZ() << std::endl;
		}
		outputFile.close();
	}
}
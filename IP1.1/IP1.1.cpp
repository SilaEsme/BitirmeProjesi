// IP1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Point.h"
#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Dense>
#include "PointCluster.h"
#include "Transform.h"

void PrintPointCloud(std::vector<Point> list);

int main()
{
	std::cout << "Process starting..." << std::endl;
	#pragma region Rotation
	std::vector<std::vector<double>> rot = {
	{ -0.7076050, 0.0065031, -0.7065783},
	{ 0.7066082, 0.0065134, -0.7075750 },
	{ 0.0000008, -0.9999576, -0.0092041 } };

	std::vector<std::vector<double>> rot1 = {
		{ -0.6638364, -0.0068830, 0.7478462},
		{ -0.7478778, 0.0061099, -0.6638082},
		{ -0.0000002, -0.9999576, -0.0092036}
	};
	std::vector<std::vector<double>> rot2 = {
		{0.8762180, 0.0044351, -0.4818945 },
		{0.4819149, -0.0080638, 0.8761809},
		{0.0000001, -0.9999577, -0.0092030}
	};
	std::vector<std::vector<double>> rot3 = {
		{ 0.3597052, -0.0085871, 0.9330265 },
		{-0.9330660, -0.0033108, 0.3596900},
		{0.0000003, -0.9999576, -0.0092033}
	};
#pragma endregion

	#pragma region Translation
	Eigen::Vector3d tr(1.95704, 1.9300, 1.05707);
	Eigen::Vector3d tr1(-1.91288, 1.94412, 1.05465);
	Eigen::Vector3d tr2(1.96978, -1.94622, 1.05264);
	Eigen::Vector3d tr3(-1.87445, -1.95027, 1.06432);
#pragma endregion

	PointCluster cl("Clouds/cam.txt", rot, tr);
	PointCluster cl1("Clouds/cam1.txt", rot1, tr1);
	PointCluster cl2("Clouds/cam2.txt", rot2, tr2);
	PointCluster cl3("Clouds/cam3.txt", rot3, tr3);

	Transform t(cl, "Clouds/tr_cam.txt");
	Transform t1(cl1, "Clouds/tr_cam1.txt");
	Transform t2(cl2, "Clouds/tr_cam2.txt");
	Transform t3(cl3, "Clouds/tr_cam3.txt");

	#pragma region Old
	//std::vector<Point> p1 = ReadPointsFromFile("Clouds/cam.txt");
	//std::vector<Point> p2 = ReadPointsFromFile("Clouds/cam1.txt");
	//std::vector<Point> p3 = ReadPointsFromFile("Clouds/cam2.txt");
	//std::vector<Point> p4 = ReadPointsFromFile("Clouds/cam3.txt");

	//CreateCloudFile(DoTransform(p1, CreateTransMatrix(SelectRotationMatrix(0), SelectTranslationMatrix(0))),"Clouds/cam_transformed.txt");
	//CreateCloudFile(DoTransform(p2,CreateTransMatrix(SelectRotationMatrix(1),SelectTranslationMatrix(1))), "Clouds/cam1_transformed.txt");
	//CreateCloudFile(DoTransform(p3,CreateTransMatrix(SelectRotationMatrix(2),SelectTranslationMatrix(2))), "Clouds/cam2_transformed.txt");
	//CreateCloudFile(DoTransform(p4,CreateTransMatrix(SelectRotationMatrix(3),SelectTranslationMatrix(3))), "Clouds/cam3_transformed.txt");
	#pragma endregion

	std::cout << "The end." << std::endl;

	return 0;
}

void PrintPointCloud(std::vector<Point> list)
{
	for (auto v : list)
	{
		std::cout << "X:" << v.getX() << " Y: " << v.getY() << " Z: " << v.getZ() << std::endl;
	}
}
#include "Point.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Eigen/Dense>
#include "PointCloud.h"
#include "Transform.h"
#include <octomap/OcTree.h>

int main()
{
	std::cout << "Process starting..." << std::endl;
//#pragma region Rotation
//	std::vector<std::vector<double>> rot = {
//	{ -0.7076050, 0.0065031, -0.7065783},
//	{ 0.7066082, 0.0065134, -0.7075750 },
//	{ 0.0000008, -0.9999576, -0.0092041 } };
//	std::vector<std::vector<double>> rot1 = {
//		{ -0.6638364, -0.0068830, 0.7478462},
//		{ -0.7478778, 0.0061099, -0.6638082},
//		{ -0.0000002, -0.9999576, -0.0092036}
//	};
//	std::vector<std::vector<double>> rot2 = {
//		{0.8762180, 0.0044351, -0.4818945 },
//		{0.4819149, -0.0080638, 0.8761809},
//		{0.0000001, -0.9999577, -0.0092030}
//	};
//	std::vector<std::vector<double>> rot3 = {
//		{ 0.3597052, -0.0085871, 0.9330265 },
//		{-0.9330660, -0.0033108, 0.3596900},
//		{0.0000003, -0.9999576, -0.0092033}
//	};
//#pragma endregion
//#pragma region Translation
//	Eigen::Vector3d tr(1.95704, 1.9300, 1.05707);
//	Eigen::Vector3d tr1(-1.91288, 1.94412, 1.05465);
//	Eigen::Vector3d tr2(1.96978, -1.94622, 1.05264);
//	Eigen::Vector3d tr3(-1.87445, -1.95027, 1.06432);
//#pragma endregion
//
//	PointCloud cl("Clouds/cam.txt", rot, tr);
//	PointCloud cl1("Clouds/cam1.txt", rot1, tr1);
//	PointCloud cl2("Clouds/cam2.txt", rot2, tr2);
//	PointCloud cl3("Clouds/cam3.txt", rot3, tr3);
//
//	Transform t(cl, "Clouds/tr_cam.txt");
//	Transform t1(cl1, "Clouds/tr_cam1.txt");
//	Transform t2(cl2, "Clouds/tr_cam2.txt");
//	Transform t3(cl3, "Clouds/tr_cam3.txt");
// 
	// OCTOMAP IMPLEMENTATION

	octomap::Pointcloud* pcl = new octomap::Pointcloud();

	// Read files and and to the octomap::Pointcloud.
	std::ifstream file("Clouds/tr_cam.txt");
	std::string tempString;
	octomath::Vector3 tempVector;
	if (file.is_open()) {

		// Read first 2 line for no reason (First two line)
		std::getline(file, tempString);
		std::getline(file, tempString);

		// Read whole file
		while (!file.eof())
		{
			file >> tempString;
			tempVector.x() = stof(tempString);

			file >> tempString;
			tempVector.y() = stof(tempString);

			file >> tempString;
			tempVector.z() = stof(tempString);

			pcl->push_back(tempVector);

			// Read 3 times for no reason (RGB)
			file >> tempString;
			file >> tempString;
			file >> tempString;

		} // end-while
		file.close();
	} // end-if

	//void octomap::MapCollection< MAPNODE >::insertScan(const Pointcloud & scan,
	//	const octomap::point3d & sensor_origin,
	//	double 	maxrange = -1.,
	//	bool 	pruning = true,
	//	bool 	lazy_eval = false
	//)
	//octomap::ScanGraph::addNode(pcl, new octomap::point3d(0, 0, 0));
	//octomap::OcTree* ocTree = new octomap::OcTree(1);
	//ocTree->insertPointCloud(pcl, new octomap::point3d(0,0,0), (-1.0), false, false, false);
	

	std::cout << "The end." << std::endl;
}
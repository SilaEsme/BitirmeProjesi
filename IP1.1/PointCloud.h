#pragma once
#include <vector>
#include <Eigen/Dense>
#include "Point.h"
#include "PointCluster.h"
class PointCloud
{
private:
	/// <summary>
	/// Vector of all discrete point clusters.
	/// </summary>
	std::vector<PointCluster> _pointCloud;

public:
	#pragma region Cons
		PointCloud();
		PointCloud(std::vector<PointCluster> pointCloud);
	#pragma endregion

	#pragma region Sets
		void SetPointCloud(std::vector<PointCluster> pointCloud);
	#pragma endregion

	#pragma region Gets
		std::vector<PointCluster> GetPointCloud();
	#pragma endregion

	void AddPointsToCloud(PointCluster points);
	

};
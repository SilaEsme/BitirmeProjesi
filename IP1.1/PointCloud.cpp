#include "PointCloud.h"
PointCloud::PointCloud()
{
}

PointCloud::PointCloud(std::vector<PointCluster> pointCloud)
{
	SetPointCloud(pointCloud);
}

void PointCloud::SetPointCloud(std::vector<PointCluster> pointCloud)
{
	_pointCloud = pointCloud;
}

std::vector<PointCluster> PointCloud::GetPointCloud()
{
	return _pointCloud;
}

void PointCloud::AddPointsToCloud(PointCluster points)
{
	_pointCloud.push_back(points);
}

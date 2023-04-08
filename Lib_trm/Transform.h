#pragma once
#include <string>
#include "PointCloud.h"
class Transform
{
private:
	std::string _path;
	PointCloud _pointCloud;
	std::vector<Point> _transformedCloud;
	void CreateCloudFile();
public:
	Transform();
	Transform(PointCloud cloud, std::string path);
#pragma region Sets
	void SetPath(std::string path);
	void SetPointCloud(PointCloud pointCloud);
#pragma endregion

	void DoTransform();
};

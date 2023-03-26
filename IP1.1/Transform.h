#pragma once
#include <string>
#include "PointCloud.h"
class Transform
{
private:
	int _countOfTransformed = 1;
	std::string _path = "Clouds/";
	PointCluster _pointCluster;
	std::vector<Point> _transformedCluster;
	void CreateCloudFile();
public:
	Transform();
	Transform(PointCluster cluster, std::string path);
	void SetPath(std::string path);
	void DoTransform();
};


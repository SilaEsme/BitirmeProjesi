#include <fstream>
#include "Transform.h"

Transform::Transform()
{
}
Transform::Transform(PointCloud cloud, std::string path)
{
	SetPath(path);
	SetPointCloud(cloud);
	DoTransform();
}
void Transform::SetPath(std::string path)
{
	_path = path;
}
void Transform::SetPointCloud(PointCloud pointCloud)
{
	_pointCloud = pointCloud;
}
void Transform::CreateCloudFile()
{
	std::ofstream outputFile(_path);

	if (outputFile.is_open())
	{
		// TODO: create file with .pcd
		for (auto v : _transformedCloud)
		{
			outputFile << v.getX() << " " << v.getY()<< " " << v.getZ()<< std::endl;
		}
		outputFile.close();
	}
}

void Transform::DoTransform()
{
	Eigen::Vector4d eigenPoint;
	Eigen::Vector4d transEigenPoint;

	for (auto v : _pointCloud.GetPointCloud())
	{
		Eigen::Vector4d eigenPoint(v.getX(), v.getY(), v.getZ(), 1);

		transEigenPoint = _pointCloud.GetTransformationMatrix() * eigenPoint;

		Point transformedPoint(transEigenPoint(0), transEigenPoint(1), transEigenPoint(2));
		_transformedCloud.push_back(transformedPoint);
	}
	CreateCloudFile();
}
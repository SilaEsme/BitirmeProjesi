#include <fstream>
#include "Transform.h"

Transform::Transform()
{

}
Transform::Transform(PointCluster cluster, std::string path)
{
	SetPath(path);
	// TODO: Set method
	_pointCluster = cluster;

	DoTransform();
}
void Transform::SetPath(std::string path)
{
	_path = path;
}
void Transform::CreateCloudFile()
{
	std::ofstream outputFile(_path);

	if (outputFile.is_open())
	{
		for (auto v : _transformedCluster)
		{
			outputFile << v.getX() << " " << v.getY() << " " << v.getZ() << std::endl;
		}
		outputFile.close();
	}
	_countOfTransformed++;
}

void Transform::DoTransform()
{
	Eigen::Vector4d eigenPoint;
	Eigen::Vector4d transEigenPoint;

	for (auto v : _pointCluster.GetPointCluster())
	{
		Eigen::Vector4d eigenPoint(v.getX(), v.getY(), v.getZ(), 1);

		transEigenPoint = _pointCluster.GetTransformationMatrix() * eigenPoint;

		Point transformedPoint(transEigenPoint(0), transEigenPoint(1), transEigenPoint(2));
		_transformedCluster.push_back(transformedPoint);
	}
	CreateCloudFile();
}

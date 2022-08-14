#include "MeshModel.h"

MeshModel::MeshModel(std::vector<Face> faces, std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, const std::string& model_name) :
	faces(faces),
	vertices(vertices),
	normals(normals)
{
	calcmax_min();
}

MeshModel::~MeshModel()
{
}

const Face& MeshModel::GetFace(int index) const
{
	return faces[index];
}

int MeshModel::GetFacesCount() const
{
	return faces.size();
}
std::vector<glm::vec3> MeshModel::get_vertices()const
{
	return vertices;
}
std::vector<glm::vec3> MeshModel::get_normals()const
{
	return normals;
}
const std::string& MeshModel::GetModelName() const
{
	return model_name;
}
void MeshModel::calcmax_min()  {
	max_x = vertices[0].x;max_y = vertices[0].y;max_z = vertices[0].z;min_x = vertices[0].x;min_y = vertices[0].y;min_z = vertices[0].z;
	for (int i = 0; i < faces.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			glm::vec3 ver = vertices[faces[i].GetVertexIndex(j) - 1];
			max_x = (ver[0] > max_x) ? ver[0] : max_x;
			max_y = (ver[1] > max_y) ? ver[1] : max_y;
			max_z = (ver[2] > max_z) ? ver[2] : max_z;
			min_x = (ver[0] < min_x) ? ver[0] : min_x;
			min_y = (ver[1] < min_y) ? ver[1] : min_y;
			min_z = (ver[2] < min_z) ? ver[2] : min_z;
		}
		
	}
	
}
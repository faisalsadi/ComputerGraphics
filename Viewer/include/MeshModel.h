#pragma once
#include <glm/glm.hpp>
#include <string>
#include "Face.h"

class MeshModel
{
public:
	MeshModel(std::vector<Face> faces, std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, const std::string& model_name);
	virtual ~MeshModel();
	const Face& GetFace(int index) const;
	void printFaceAt(int index) const;
	int GetFacesCount() const;
	const std::string& GetModelName() const;
	std::vector<glm::vec3> get_vertices()const;
	std::vector<glm::vec3> get_normals()const;
	void calcmax_min();
	float min_x, min_y, min_z, max_x, max_y, max_z;
private:
	std::vector<Face> faces;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::string model_name;
	

};

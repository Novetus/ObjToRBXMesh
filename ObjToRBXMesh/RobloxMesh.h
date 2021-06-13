#pragma once

#include <cstdint>
#include <vector>
#include <fstream>

class RobloxMesh
{
public:
	struct Vertex
	{
		float vx, vy, vz;
		float nx, ny, nz;
		float tu, tv, tw;
	};

	struct Face
	{
		uint32_t a, b, c;
	};

	std::vector<Vertex> vertices;

	std::vector<Face> faces;

	void Write(std::ostream& stream);
};


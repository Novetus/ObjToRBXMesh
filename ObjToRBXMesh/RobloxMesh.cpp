#include "RobloxMesh.h"

void RobloxMesh::Write(std::ostream& stream)
{
	stream << "version 1.00" << std::endl;
	stream << faces.size() << std::endl;

	for (int i = 0; i < vertices.size(); ++i)
	{
		Vertex vert = vertices[i];

		stream << "[";
		stream << vert.vx * 2 << ",";
		stream << vert.vy * 2 << ",";
		stream << vert.vz * 2 << "]";

		stream << "[";
		stream << vert.nx << ",";
		stream << vert.ny << ",";
		stream << vert.nz << "]";

		stream << "[";
		stream << vert.tu << ",";
		stream << vert.tv << ",";
		stream << "0]";
	}
}

#include <iostream>

#include "RobloxMesh.h"
#include "OBJ_Loader.h"

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];

		objl::Loader obj;
		if (!obj.LoadFile(arg))
		{
			std::cout << "ERROR: Could not load \"" << arg << "\"!";
			return EXIT_FAILURE;
		}

		RobloxMesh rbxMesh;

		for (auto& objVertex : obj.LoadedVertices)
		{
			RobloxMesh::Vertex meshVertex;

			meshVertex.vx = objVertex.Position.X;
			meshVertex.vy = objVertex.Position.Y;
			meshVertex.vz = objVertex.Position.Z;

			meshVertex.nx = objVertex.Normal.X;
			meshVertex.ny = objVertex.Normal.Y;
			meshVertex.nz = objVertex.Normal.Z;

			meshVertex.tu = objVertex.TextureCoordinate.X;
			meshVertex.tv = objVertex.TextureCoordinate.Y;

			rbxMesh.vertices.push_back(meshVertex);
		}

		for (size_t i = 0; i < obj.LoadedIndices.size(); i += 3)
		{
			RobloxMesh::Face meshFace;

			meshFace.a = obj.LoadedIndices[i];
			meshFace.b = obj.LoadedIndices[i + 1];
			meshFace.c = obj.LoadedIndices[i + 2];

			rbxMesh.faces.push_back(meshFace);
		}

		std::ofstream output(arg + ".mesh", std::ios::binary);
		rbxMesh.Write(output);
		output.close();
	}
}

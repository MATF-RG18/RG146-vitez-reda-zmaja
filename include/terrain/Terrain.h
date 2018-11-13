#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include "../model/RawModel.h"
#include "../texture/ModelTexture.h"
#include "../texture/TerrainTexturePack.h"
#include "../core/VaoLoader.h"
#include "../utility/Math.h"

#include <Magick++.h>
#include <math.h>
#include <glm/vec3.hpp>
#include <glm/glm.hpp> 

#define SIZE  800
#define MAX_PIXEL_COLOUR 256*256*256
#define MAX_HEIGHT 40

using namespace model;
using namespace texture;
using namespace core;
using namespace glm;
using namespace Magick;

namespace terrain {

    class Terrain {

        private:
            float x;
            float z;
            RawModel *model;
            TerrainTexturePack *texturePack;
            TerrainTexture *blendMap;
            float **heights;
            int heightsLength;
            int VERTEX_COUNT;
        public:
            Terrain(float gridX, float gridZ, VaoLoader *vaoLoader, TerrainTexturePack *texturePack, TerrainTexture *blendMap,const char *heightMap);
            ~Terrain();
            RawModel *getModel();
            TerrainTexturePack *getTexturePack();
            TerrainTexture *getBlendMap();
            float getX();
            float getZ();
            float getHeightOfTerrain(int worldX, int worldZ);
        private:
            vec3 calculateNormal(Image image, int x, int y);
            float getHeight(Image image, int x, int y);
            RawModel *generateTerrain(VaoLoader *vaoLoader,Image image);
    };
}

#endif
#include "../../include/terrain/Terrain.h"

// Klasa je implementirana po uzoru na video tutorijal 
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace terrain {

    Terrain::Terrain(float gridX, float gridZ, VaoLoader *vaoLoader, TerrainTexturePack *texturePack, TerrainTexture *blendMap,const char *heightMap) {

        this->texturePack = texturePack;
        this->x = gridX * SIZE;
        this->z = gridZ * SIZE;

        InitializeMagick(NULL);
        Image image(heightMap);

        int height = image.rows();

        this->VERTEX_COUNT = height;

        this->heights = new float*[VERTEX_COUNT];
        for (int i = 0; i < VERTEX_COUNT; i++) {
            heights[i] = new float[VERTEX_COUNT];
        }   

        this->heightsLength = VERTEX_COUNT;

        this->model = generateTerrain(vaoLoader, image);
        this->blendMap = blendMap;
    }

    Terrain::~Terrain() {

    }

    RawModel * Terrain::getModel() {
        return this->model;
    }

    TerrainTexturePack * Terrain::getTexturePack() {
        return this->texturePack;
    }

    TerrainTexture * Terrain::getBlendMap() {
        return this->blendMap;
    }

    float Terrain::getX() {
        return this->x;
    }

    float Terrain::getZ() {
        return this->z;
    }

    RawModel * Terrain::generateTerrain(VaoLoader *vaoLoader, Image image) {

        int count = VERTEX_COUNT * VERTEX_COUNT;
        float *vertices = new float[count*3];
        float *textures = new float[count*2];
        float *normals = new float[count*3];
        int *indices = new int[6*(VERTEX_COUNT-1)*(VERTEX_COUNT-1)];

        int vertexIndex = 0;
        for (int i = 0; i < VERTEX_COUNT; i++) {
            for (int j = 0; j < VERTEX_COUNT; j++) {
                float h = getHeight(image, i, j);
                this->heights[i][j] = h;
                vertices[vertexIndex*3] = float(j)/float(VERTEX_COUNT-1)*SIZE;
                vertices[vertexIndex*3 + 1] = h;
                vertices[vertexIndex*3 + 2] = float(i)/float(VERTEX_COUNT-1)*SIZE;
                vec3 normal= calculateNormal(image, i, j);
                normals[vertexIndex*3] = normal.x;
                normals[vertexIndex*3 + 1] = normal.y;
                normals[vertexIndex*3 + 2] = normal.z;
                textures[vertexIndex*2] = float(j)/float(VERTEX_COUNT-1);
                textures[vertexIndex*2 + 1] = float(i)/float(VERTEX_COUNT-1);
                vertexIndex++;
            }
        }

        int index = 0;
        for(int gridZ = 0; gridZ < VERTEX_COUNT-1; gridZ++) {
            for(int gridX = 0; gridX < VERTEX_COUNT-1; gridX++) {
                int topLeft = (gridZ*VERTEX_COUNT)+gridX;
                int topRight = topLeft+1;
                int bottomLeft = ((gridZ+1)*VERTEX_COUNT)+gridX;
                int bottomRight = bottomLeft+1;
                indices[index++] = topLeft;
                indices[index++] = bottomLeft;
                indices[index++] = topRight;
                indices[index++] = topRight;
                indices[index++] = bottomLeft;
                indices[index++] = bottomRight;
            }
        }

        return vaoLoader->loadToVao(vertices, count*3,
                                  indices, 6*(VERTEX_COUNT-1)*(VERTEX_COUNT-1),
                                  textures, count*2,
                                  normals, count*3);
    }

    vec3 Terrain::calculateNormal(Image image, int x, int y) {

        float heightLeft = getHeight(image, x-1, y);
        float heightRight = getHeight(image, x+1, y);
        float heightDown = getHeight(image, x, y-1);
        float heightUp = getHeight(image, x, y+1);

        vec3 normals(heightLeft-heightRight, 2, heightDown - heightUp);
        return normalize(normals);
    }

    float Terrain::getHeight(Image image, int x, int y) {

        int w = image.columns();
        int h = image.rows();

        if (x<0 || x>=h || y<0 || y>=h) {
            return 0;
        }
        
        PixelPacket *pixels = image.getPixels(0, 0, w, h);
        
        Color color = pixels[ w * x+ y];
        ColorRGB c = color;
        float height = c.red() * c.green()* c.blue();
        height *= MAX_HEIGHT;
        return height;

    }

    float Terrain::getHeightOfTerrain(int worldX, int worldZ) {

        int terrainX = worldX - this->x;
        int terrainZ = worldZ - this->z;
        int gridSquareSize = abs(SIZE / (this->heightsLength - 1));
        int gridX = floor(terrainX/gridSquareSize);
        int gridZ = floor(terrainZ/gridSquareSize);
        if (gridX >= heightsLength-1 || gridZ >= heightsLength-1 || gridX<0 || gridZ<0) {
            return 0;
        }
        int xCoord = (terrainX%gridSquareSize)/gridSquareSize;
        int zCoord = (terrainZ%gridSquareSize)/gridSquareSize;
        
        float answer;

        if (xCoord <= 1 - zCoord) {
            answer = barryCentric(vec3(0, heights[gridX][gridZ], 0),
                                  vec3(1, heights[gridX+1][gridZ], 0),
                                  vec3(0, heights[gridX][gridZ+1], 1),
                                  vec2(xCoord, zCoord));
        } else {
            answer = barryCentric(vec3(1, heights[gridX+1][gridZ], 0),
                                  vec3(1, heights[gridX+1][gridZ+1], 1),
                                  vec3(0, heights[gridX][gridZ+1], 1),
                                  vec2(xCoord, zCoord));
        }
        return answer;
    }
}
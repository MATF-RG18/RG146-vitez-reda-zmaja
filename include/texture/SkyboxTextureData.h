#ifndef _SKYBOX_TEXTURE_DATA_H_
#define _SKYBOX_TEXTURE_DATA_H_

#include <vector>

using namespace std;

namespace texture {

    class SkyboxTextureData {

        private:
            int width;
            int height;
            unsigned char *buffer;
        public:
            SkyboxTextureData(int width, int height, unsigned char *buffer);
            ~SkyboxTextureData();
            int getWidth();
            int getHeight();
            unsigned char *getBuffer();
    };
}

#endif
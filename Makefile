PROGRAM = Test
CC = g++
CXXFLAGS = -g -Wall -Wextra -I/usr/include/freetype2

LDFLAGS = -W -lGL -lGLU -lglut -lpng -g -lGraphicsMagick++ -lfreetype
DEPS = include/model/RawModel.h \
			 include/model/TexturedModel.h \
			 include/core/Engine.h \
			 include/core/Render.h \
			 include/core/MainRenderer.h \
			 include/core/TerrainRenderer.h \
			 include/core/SkyboxRenderer.h \
			 include/core/VaoLoader.h \
			 include/core/ObjLoader.h \
			 include/shader/Shader.h \
			 include/shader/TerrainShader.h \
			 include/shader/SkyboxShader.h \
			 include/shader/HudShader.h \
			 include/shader/FontShader.h \
			 include/texture/ModelTexture.h \
			 include/texture/TerrainTexture.h \
			 include/texture/TerrainTexturePack.h \
			 include/texture/SkyboxTextureData.h \
			 include/entity/Entity.h \
			 include/entity/Camera.h \
			 include/entity/Light.h \
			 include/entity/Player.h \
			 include/utility/Math.h \
			 include/utility/FpsData.h \
			 include/external_libs/tiny_obj_loader.h \
			 include/terrain/Terrain.h \
			 include/hud/HudTexture.h \
			 include/hud/HudRenderer.h \
			 include/font/Font.h \
			 include/font/Text.h \
			 include/font/FontData.h \
			 include/font/FontRenderer.h


OBJ = test/$(PROGRAM).o \
			src/core/Engine.o \
			src/model/RawModel.o \
			src/model/TexturedModel.o \
			src/core/Render.o \
			src/core/MainRenderer.o \
			src/core/TerrainRenderer.o \
			src/core/SkyboxRenderer.o \
			src/core/VaoLoader.o \
			src/core/ObjLoader.o \
			src/shader/Shader.o \
			src/shader/TerrainShader.o \
			src/shader/SkyboxShader.o \
			src/shader/HudShader.o \
			src/shader/FontShader.o \
			src/texture/ModelTexture.o \
			src/texture/TerrainTexture.o \
			src/texture/TerrainTexturePack.o \
			src/texture/SkyboxTextureData.o \
			src/entity/Entity.o \
			src/entity/Camera.o \
			src/entity/Light.o \
			src/entity/Player.o \
			src/utility/Math.o \
			src/utility/FpsData.o \
			src/terrain/Terrain.o \
			src/hud/HudTexture.o \
			src/hud/HudRenderer.o \
			src/font/Font.o \
			src/font/Text.o \
			src/font/FontData.o \
			src/font/FontRenderer.o

%.o: %.c $(DEPS)
	$(CC) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

$(PROGRAM): $(OBJ)
	$(CC) $(CXXFLAGS)  -o $@ $^ $(LDFLAGS)

.PHONY : clean
clean :
	-rm $(OBJ)

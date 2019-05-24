PROGRAM = Test
CC = g++
CXXFLAGS = -g -Wall -Wextra -std=c++11 -I/usr/include/freetype2

LDFLAGS = -W -lGL -lGLU -lglut -lpng -g -lGraphicsMagick++ -lfreetype -lassimp
DEPS = include/model/RawModel.h \
			 include/model/TexturedModel.h \
			 include/model/AnimatedModel.h \
			 include/model/Bone.h \
			 include/core/Engine.h \
			 include/core/Render.h \
			 include/core/MainRenderer.h \
			 include/core/TerrainRenderer.h \
			 include/core/SkyboxRenderer.h \
			 include/core/AnimatedModelRenderer.h \
			 include/core/VaoLoader.h \
			 include/core/Loader.h \
			 include/shader/Shader.h \
			 include/shader/TerrainShader.h \
			 include/shader/SkyboxShader.h \
			 include/shader/HudShader.h \
			 include/shader/FontShader.h \
			 include/shader/AnimatedModelShader.h \
			 include/texture/Texture.h \
			 include/texture/TerrainTexture.h \
			 include/texture/TerrainTexturePack.h \
			 include/texture/SkyboxTextureData.h \
			 include/entity/Entity.h \
			 include/entity/AnimatedEntity.h \
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
			 include/font/FontRenderer.h \
			 include/animation/Animation.h \
			 include/animation/Animator.h \
			 include/animation/KeyFrame.h \
			 include/animation/BoneTransform.h


OBJ = test/$(PROGRAM).o \
			src/core/Engine.o \
			src/model/RawModel.o \
			src/model/TexturedModel.o \
			src/model/AnimatedModel.o \
			src/model/Bone.o \
			src/core/Render.o \
			src/core/MainRenderer.o \
			src/core/TerrainRenderer.o \
			src/core/SkyboxRenderer.o \
			src/core/AnimatedModelRenderer.o \
			src/core/VaoLoader.o \
			src/core/Loader.o \
			src/shader/Shader.o \
			src/shader/TerrainShader.o \
			src/shader/SkyboxShader.o \
			src/shader/HudShader.o \
			src/shader/FontShader.o \
			src/shader/AnimatedModelShader.o \
			src/texture/Texture.o \
			src/texture/TerrainTexture.o \
			src/texture/TerrainTexturePack.o \
			src/texture/SkyboxTextureData.o \
			src/entity/Entity.o \
			src/entity/AnimatedEntity.o \
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
			src/font/FontRenderer.o \
			src/animation/Animation.o \
			src/animation/Animator.o \
			src/animation/KeyFrame.o \
			src/animation/BoneTransform.o

%.o: %.c $(DEPS)
	$(CC) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

$(PROGRAM): $(OBJ)
	$(CC) $(CXXFLAGS)  -o $@ $^ $(LDFLAGS)

.PHONY : clean
clean :
	-rm $(OBJ)

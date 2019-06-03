#include "../../include/core/VaoLoader.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

// Pomoc pri koriscenju biblioteka za ucitavanje slika
// https://imagemagick.org/Magick++/Documentation.html
// http://www.libpng.org/pub/png/book/chapter13.html

using namespace std;

namespace core {

  VaoLoader::VaoLoader() {

  }

  VaoLoader::~VaoLoader() {

    cleanUp();
  }

  GLint VaoLoader::loadToVao(GLfloat positions[], GLint positionsSize,
  GLint indices[], GLint indicesSize,
  GLfloat textureCoords[], GLint textureSize,
  GLfloat normals[], GLint normalsSize) {
    vaoID = createVao();
    storeDataInIndicesBuffer(indices, indicesSize);
    storeDataInVertexBuffer(0, 3, positions, positionsSize);
    storeDataInVertexBuffer(1, 2, textureCoords, textureSize);
    storeDataInVertexBuffer(2, 3, normals, normalsSize);
    unbindVao();

    return vaoID;
  }

  GLint VaoLoader::loadToVao(GLfloat positions[], GLint positionsSize, GLint indices[], GLint indicesSize,
  GLfloat textureCoords[], GLint textureSize,
  GLfloat normals[], GLint normalsSize,
  GLint boneIndices[], GLint boneIndicesSize,
  GLfloat weights[], GLint weightsSize) {

    vaoID = createVao();
    storeDataInIndicesBuffer(indices, indicesSize);
    storeDataInVertexBuffer(0, 3, positions, positionsSize);
    storeDataInVertexBuffer(1, 2, textureCoords, textureSize);
    storeDataInVertexBuffer(2, 3, normals, normalsSize);
    storeDataInVertexBuffer(3, 4, boneIndices, boneIndicesSize);
    storeDataInVertexBuffer(4, 4, weights, weightsSize);
    unbindVao();

    return vaoID;
  }

  GLint VaoLoader::loadToVao(GLfloat positions[], GLint positionsSize, int dimensions) {
    // Prostiji model ucitavanja gde su nam potrebne samo pozicije bez tekstura i normala
    GLuint vaoID = createVao();
    storeDataInVertexBuffer(0, dimensions, positions, positionsSize);
    unbindVao();

    return vaoID;

  }

  // Kod za ucitavanje png datoteke preuzet sa
  // https://blog.nobel-joergensen.com/2010/11/07/loading-a-png-as-texture-in-opengl-using-libpng/
  int VaoLoader::loadTexture(const char *fileName) {


    png_byte header[8];

    FILE *fp = fopen(fileName, "rb");
    if (fp == 0)
    {
        perror(fileName);
        return 0;
    }

    // Citanje zaglavlja fajla
    fread(header, 1, 8, fp);

    if (png_sig_cmp(header, 0, 8))
    {
        fprintf(stderr, "[!] Err: %s nije png fajl.\n", fileName);
        fclose(fp);
        return 0;
    }

    png_structp pngPointer = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!pngPointer)
    {
        fprintf(stderr, "[!] Err: png_create_read_struct returned 0.\n");
        fclose(fp);
        return 0;
    }

    // Kreiranje png info strukture
    png_infop infoPointer = png_create_info_struct(pngPointer);
    if (!infoPointer)
    {
        fprintf(stderr, "[!] Err: png_create_info_struct returned 0.\n");
        png_destroy_read_struct(&pngPointer, (png_infopp)NULL, (png_infopp)NULL);
        fclose(fp);
        return 0;
    }

    png_infop endInfo = png_create_info_struct(pngPointer);
    if (!endInfo)
    {
        fprintf(stderr, "error: png_create_info_struct returned 0.\n");
        png_destroy_read_struct(&pngPointer, &infoPointer, (png_infopp) NULL);
        fclose(fp);
        return 0;
    }

    // Izvrsava se ako dodje do greske u libpng biblioteci
    if (setjmp(png_jmpbuf(pngPointer))) {
        fprintf(stderr, "[!] Err: libpng\n");
        png_destroy_read_struct(&pngPointer, &infoPointer, &endInfo);
        fclose(fp);
        return 0;
    }

    // Inicijalizacija citanja
    png_init_io(pngPointer, fp);

    // Obavestavanje da smo prethodno procitali prvih 8 bajtova
    png_set_sig_bytes(pngPointer, 8);

    // Citanje svih informacija do podataka slike
    png_read_info(pngPointer, infoPointer);

    // Promenljive koje se prosledjuju za dobijanje informacija
    int bitDepth, colorType;
    png_uint_32 tempWidth, tempHeight;

    // Citamo informacije o slici
    png_get_IHDR(pngPointer, infoPointer, &tempWidth, &tempHeight, &bitDepth, &colorType,
        NULL, NULL, NULL);


    if (bitDepth != 8)
    {
        fprintf(stderr, "%s: Unsupported bit depth %d.  Must be 8.\n", fileName, bitDepth);
        return 0;
    }

    GLint format;
    switch(colorType)
    {
    case PNG_COLOR_TYPE_RGB:
        format = GL_RGB;
        break;
    case PNG_COLOR_TYPE_RGB_ALPHA:
        format = GL_RGBA;
        break;
    default:
        fprintf(stderr, "%s: Unknown libpng color type %d.\n", fileName, colorType);
        return 0;
    }

    // Azurira se info struktura
    png_read_update_info(pngPointer, infoPointer);

    // Velicina reda u bajtovima
    int rowbytes = png_get_rowbytes(pngPointer, infoPointer);

    rowbytes += 3 - ((rowbytes-1) % 4);

    // Alociranje memorije za sliku
    png_byte * imageData = (png_byte *)malloc(rowbytes * tempHeight * sizeof(png_byte)+15);
    if (imageData == NULL)
    {
        fprintf(stderr, "[!] Err: nije moguce alocirati memoriju\n");
        png_destroy_read_struct(&pngPointer, &infoPointer, &endInfo);
        fclose(fp);
        return 0;
    }

    // rowPointers pokazuje na imageData za citanje png fajla
    png_byte ** rowPointers = (png_byte **)malloc(tempHeight * sizeof(png_byte *));
    if (rowPointers == NULL)
    {
        fprintf(stderr, "[!] Errr: Nije moguce alocirati memoriju\n");
        png_destroy_read_struct(&pngPointer, &infoPointer, &endInfo);
        free(imageData);
        fclose(fp);
        return 0;
    }

    for (unsigned int i = 0; i < tempHeight; i++)
    {
        rowPointers[tempHeight - 1 - i] = imageData + i * rowbytes;
    }

    png_read_image(pngPointer, rowPointers);

    // Generisanje OpenGL teksture
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, format, tempWidth, tempHeight, 0, format, GL_UNSIGNED_BYTE, imageData);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, -1);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    png_destroy_read_struct(&pngPointer, &infoPointer, &endInfo);
    free(imageData);
    free(rowPointers);
    fclose(fp);

    textures.push_back(texture);

    return texture;
  }

  int VaoLoader::createVao(void) {

    glGenVertexArrays(1, &vaoID);
    vaos.push_back(vaoID);
    glBindVertexArray(vaoID);

    return vaoID;
  }

  void VaoLoader::storeDataInVertexBuffer(GLint attributeNumber, int coordinateSize, GLfloat data[], GLint dataSize) {

    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    vector<GLfloat> buffer = storeDataInFloatBuffer(data, dataSize);
    glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), &(buffer[0]), GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, coordinateSize, GL_FLOAT, false, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return;
  }

  void VaoLoader::storeDataInVertexBuffer(GLint attributeNumber, int coordinateSize, GLint data[], GLint dataSize) {

    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    vector<GLint> buffer = storeDataInIntBuffer(data, dataSize);
    glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(int), &(buffer[0]), GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, coordinateSize, GL_INT, false, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return;
  }

  void VaoLoader::storeDataInIndicesBuffer(GLint data[], GLint dataSize) {

    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
    vector<int> buffer = storeDataInIntBuffer(data, dataSize);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, buffer.size() * sizeof(int), &(buffer[0]), GL_STATIC_DRAW);

    return;
  }

  void VaoLoader::unbindVao(void) {

    glBindVertexArray(0);

    return;
  }

  vector<float> VaoLoader::storeDataInFloatBuffer(GLfloat data[], GLint dataSize) {
    vector<float> buffer;
    for (int i = 0; i < dataSize; i++) {
      buffer.push_back(data[i]);
    }

    return buffer;
  }

  vector<int> VaoLoader::storeDataInIntBuffer(GLint data[], GLint dataSize) {

    vector<int> buffer;
    for (int i = 0; i < dataSize; i++) {
      buffer.push_back(data[i]);
    }

    return buffer;
  }

  GLuint VaoLoader::loadCubeMap(vector<const char *> textureFiles) {

    // Inicijalizujemo biblioteku
    InitializeMagick(NULL);

    // Generisemo teksturu koja se sastoji od 6 delova svaki nalepljen na jedan deo kocke
    GLuint textureID;
    glGenTextures(1, &textureID);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    // Vrsimo iteraciju kroz svih sest tekstura i lepimo ih na kocku
    for (int i = 0; i < textureFiles.size(); i++) {

      SkyboxTextureData *data = decodeTextureFile(textureFiles[i]);

      // Greska je bila poslednji argument gde je bio dat pokazivac na klasu umesto bafera
      glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, data->getWidth(), data->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, data->getBuffer());
      glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    }

    this->textures.push_back(textureID);
    return textureID;
  }

  SkyboxTextureData *VaoLoader::decodeTextureFile(const char *fileName) {

    // Ucitavanje texture
    Image image(fileName);

    // Uzimamo visinu i sirinu slike
    int height = image.rows();
    int width = image.columns();

    // Ucitavamo podatke o svim pikselima
    PixelPacket *pixels = image.getPixels(0, 0, width, height);

    vector<unsigned char> buffer;

    // Prolazimo kroz sve piksele i citamo podatke o njima
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        Color color = pixels[ width * i + j];
        ColorRGB c = color;
        // Mnozimo sa 255 jer su povratne vrednosti u intervalu [0,1]

        buffer.push_back(c.red()*255.0);
        buffer.push_back(c.green()*255.0);
        buffer.push_back(c.blue()*255.0);
        buffer.push_back(c.alpha()*255.0);

      }
    }

    image.~Image();
    return new SkyboxTextureData(width, height, buffer.data());

  }

  void VaoLoader::cleanUp() {

    unique(vaos.begin(), vaos.end());
    for (GLuint vao : vaos) {
      glDeleteVertexArrays(1, &vao);
    }

    unique(vbos.begin(), vbos.end());
    for (GLuint vbo : vbos) {
      glDeleteBuffers(1, &vbo);
	  }

    unique(textures.begin(), textures.end());
    for (GLuint texture : textures) {
      glDeleteTextures(1, &texture);
    }

    return;
  }

} // core

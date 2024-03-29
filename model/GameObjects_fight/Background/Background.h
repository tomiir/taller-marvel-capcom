#ifndef TALLER_MARVEL_CAPCOM_BACKGROUND_H
#define TALLER_MARVEL_CAPCOM_BACKGROUND_H

#include "../GameObject/GameObject.h"
#include "../../../utils/TextureManager/TextureManager.h"

using namespace std;

class Background : public GameObject{

public:
    Background(const char* imagePath, string name_, int z_index,SDL_Renderer* rend,  int width_image, int height_image, int screenWidth, int screenHeight);
    ~Background();

    void render() override;
    void updatePos(int posX, int posY);


private:
    int CAMERA_WIDTH, CAMERA_HEIGHT, CAMERA_X_POS, CAMERA_Y_POS;

    int imgWight, imgHeight;

    SDL_Rect camera;
};


#endif //TALLER_MARVEL_CAPCOM_BACKGROUND_H


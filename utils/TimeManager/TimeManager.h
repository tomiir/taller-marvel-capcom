//
// Created by magali on 08/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_TIMEMANAGER_H
#define TALLER_MARVEL_CAPCOM_TIMEMANAGER_H

#include "SDL2/SDL.h"
#include "../../model/GameObjects_fight/GameObject/GameObject.h"
#include <vector>
#include <map>

class TimeManager: public Renderable {
public:
    void render() override;
    int getZIndex() override;
    TimeManager(int z, vector<GameObject*> unityNumbers, vector<GameObject*> tenNumbers, vector<GameObject*> rounds);
    void setUnity(int unityNew);
    void setTen(int ten);
    void setRound(int roundNew);

    ~TimeManager() = default;


private:
    int z;
    //uso un vector para la decena y otro para la unidad, pq no se puede renderizar dos veces un mismo GO.
    vector<GameObject*> tenNumbers;
    vector<GameObject*> unityNumbers;
    int round;
    vector <GameObject*> rounds;
    int unity;
    int ten;
    int roundTimer;

};

#endif //TALLER_MARVEL_CAPCOM_TIMEMANAGER_H

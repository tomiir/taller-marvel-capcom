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
    TimeManager(int z, GameObject* unityNumbers, GameObject* tenNumbers, GameObject* roundFight,
            map<int, vector<int>> sourcePosition);
    void setUnity(int unityNew);
    void setTen(int ten);
    void setRound(int roundNew);
    void updateShouldFight(int shouldFight);

    ~TimeManager() = default;


private:
    int z;
    //uso un vector para la decena y otro para la unidad, pq no se puede renderizar dos veces un mismo GO.
    GameObject* tenNumbers;
    GameObject* unityNumbers;
    GameObject* roundFight;
    map <int, vector<int>> sourcePosition;
    map<int, vector<int>>::iterator sourcePosition_itr;
    int round;
    int unity;
    int ten;
    int roundTimer;
    bool shouldFight;

};

#endif //TALLER_MARVEL_CAPCOM_TIMEMANAGER_H

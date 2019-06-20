#ifndef BOSS_HPP
#define BOSS_HPP
#include <string>
#include "Point.hpp"
#include "Fighter.hpp"
#include "Enemy.hpp"

class MainScene;
using namespace std;

class Boss : public Enemy {
private:
public:
    static enum {RANDOM, LINEAR, LOOP} movingVectorType;
    static map<string, int> movingVectorTypeMap;

    int stopPoint;
    int dialogueIndex = 0;
    int dialogueSkipCount = 0;
    vector<string> dialogueA;  // dialogue before battle
    vector<string> dialogueB;  // dialogue after boss is beated
    int timeLimit;
    int time;

    explicit Boss(const string& sprite, float hp, int timeLimit,
        vector<map<string, float>>& v, vector<map<string, float>>& s,
        vector<string>& dialogueA, vector<string>dialogueB,
        MainScene*);
    ~Boss() = default;

    void changeMovingVector(int index);

    void update(float deltaTime);
    void draw();

};

#endif
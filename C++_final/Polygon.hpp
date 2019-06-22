#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <list>
#include <iostream>
#include "Point.hpp"
#include "Util.hpp"

class Bullet;

using namespace std;

class Polygon {
private:
public:
    Polygon() = default;
    ~Polygon() = default;

    list<Engine::Point> vertex;
    Bullet* parent;
    Polygon(Bullet* parent, list<Engine::Point> vertex);

    list<Engine::Point> vertex_real;  // vertics' real position
    void updateVertics();
    list<Engine::Point> norms;  // right normal vectors of vectors connected by two neighbor vertex
    void updateNorms();
    void getProjectedMinMax(float* p_max, float* p_min, Engine::Point& norm);
};

ostream& operator<<(ostream& os, Polygon& polygon);

#endif
#include "Polygon.hpp"
#include "Bullet.hpp"


Polygon::Polygon(Bullet* parent, list<Engine::Point> vertex) {
	this->vertex = vertex;
	this->parent = parent;
	this->vertex_real.resize(vertex.size());
	this->norms.resize(vertex.size());
}

// calculate the real position of vertics considering rotation of parent(bullet)
// this calculation only works with anchor = (0.5, 0.5)
void Polygon::updateVertics() {
	auto it = this->vertex.begin();
	auto it2 = this->vertex_real.begin();
	for (; it != this->vertex.end(); it++, it2++) {
		// rotate reference position = parent's position
		// rotate angle = parent's angle
		it2->x =
			it->x * Math::cos(this->parent->angle + 180) -
			it->y * Math::sin(this->parent->angle + 180) +
			this->parent->position.x;
			//0;
		it2->y =
			-(it->x * Math::sin(this->parent->angle + 180) +
			it->y * Math::cos(this->parent->angle + 180)) +
			this->parent->position.y;
			//0;
	}
}


void Polygon::updateNorms() {
	auto it = this->vertex_real.begin();
	auto prev = this->vertex_real.end();
	auto it2 = this->norms.begin();
	for (; it != this->vertex_real.end(); prev = it, it++, it2++) {
		if (it == this->vertex_real.begin()) {
			*it2 = (this->vertex_real.back() - *it).normalR();
		}
		else {
			*it2 = (*prev - *it).normalR();
		}
	}
}

void Polygon::getProjectedMinMax(float* p_max, float* p_min, Engine::Point& norm){
	auto it = this->vertex_real.begin();
	float min = it->projectLengthOnto(norm);
	float max = min;
	for (it++; it != this->vertex_real.end(); it++) {
		float l = it->projectLengthOnto(norm);
		if (l < min) min = l;
		if (l > max) max = l;
	}
	*p_min = min;
	*p_max = max;
}
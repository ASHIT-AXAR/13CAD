/**
 * @file cell.cpp
 * @brief Source file for the Cell class and subclasses
 * @author Zong Lei
 * @author Nandi Guo
 * @version 1.0 20/11/18
 */

// a cell is defined by a line beginning with a 'c'. The second parameter
// the cell index, the third is a character (either h - hexahedral, p -
// pyramid, t - tetrahedral). Thie 4th in the index of a material that the
// cell is made of and the remaining  numbers state which node defines
// each corner.

#include <sstream>
#include "cell.h"
#include "iostream"
#include <vector>
#include "vector3d.h"

Cell::Cell() {}
Cell::~Cell() {}


Pyramid::Pyramid(std::vector<Vector3D> &vertices) {
    for (int i = 0; i < 5; i++) {
        this->vertices.push_back(vertices[i]);
    }
}

Pyramid::Pyramid() {}
Pyramid::~Pyramid() {}

//double Pyramid::getVolume() {
//    //length = vertices[0].distance(vertices[1]);
//    //width = vertices[1].distance(vertices[2]);
//    //height = 
//}

Hexahedron::Hexahedron(std::vector<Vector3D> &vertices) {
    for (int i = 0; i < 8; i++) {
        this->vertices.push_back(vertices[i]);
    }
}

Hexahedron::Hexahedron() {}
Hexahedron::~Hexahedron() {}

Tetrahedron::Tetrahedron(std::vector<Vector3D> &vertices) {
    for (int i = 0; i < 4; i++) {
        this->vertices.push_back(vertices[i]);
    }
}

Tetrahedron::Tetrahedron() {}
Tetrahedron::~Tetrahedron() {}

double Tetrahedron::getVolume() {
    // Source: http://mathworld.wolfram.com/Tetrahedron.html

    Vector3D va = this->vertices[1] - this->vertices[0];
    Vector3D vb = this->vertices[2] - this->vertices[0];
    Vector3D vc = this->vertices[3] - this->vertices[0];

    Vector3D vCross = vb.cross(vc);

    double scalar = va.dot(vCross);

    double volume = scalar/6;

    return volume;
}

/*
std::ostream &operator<<(std::ostream &os, const Cell &cell)
{
    os << cell.shape << "cell made of " << cell.material << "with " << cell.vertices.size() << "vertices";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Shape &shape)
{
    switch (shape) {
		case Shape::HEXAHEDRAL:
            os << "Hexahedral";
            break;
		case Shape::PYRAMIDAL:
            os << "Pyramidal";
            break;
		case Shape::TETRAHEDRAL:
            os << "Tetrahedral";
            break;
		default:
            os << "Broken shape";
    }
    return os;
}

std::istream &operator>>(std::istream &in, Material &out)
{
    in >> out.density;
    in >> out.colour;
    in >> out.name;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Material &mat)
{
    out << mat.name << "with a density of " << mat.density << "with colour " <<  mat.colour;
    return out;
}
*/
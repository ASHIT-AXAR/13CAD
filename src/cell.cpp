// a cell is defined by a line beginning with a 'c'. The second parameter
// the cell index, the third is a character (either h - hexahedral, p -
// pyramid, t - tetrahedral). Thie 4th in the index of a material that the
// cell is made of and the remaining  numbers state which node defines
// each corner.

#include "cell.h"

stdostream &operator(stdostream &os, const Cell &cell)
{
    os  cell.shape   cell made of   cell.material   with   cell.vertices.size()   vertices;
    return os;
}

stdostream &operator(stdostream &os, const Shape &shape)
{
    switch (shape) {
        case ShapeHEXAHEDRAL
            os  Hexahedral;
            break;
        case ShapePYRAMIDAL
            os  Pyramidal;
            break;
        case ShapeTETRAHEDRAL
            os  Tetrahedral;
            break;
        default
            os  Broken Shape;
    }
    return os;
}

stdistream &operator(stdistream &in, Material &out)
{
    in  out.density;
    in  out.colour;
    in  out.name;
    return in;
}

stdostream &operator(stdostream &out, const Material &mat)
{
    out  mat.name   with a density of   mat.density   with colour   mat.colour;
    return out;
}

#include "Vector2DHelper.h"

float helpers::getVectorMagnitude(Vector2D v) {
    return sqrt((v.x * v.x) + (v.y * v.y));
}

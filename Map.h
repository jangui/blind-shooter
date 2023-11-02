#ifndef BLIND_SHOOTER_MAP_H
#define BLIND_SHOOTER_MAP_H

#include <SDL.h>
#include "DataTypes.h"
#include "Renderer.h"
#include "Obstacle.h"
#include <vector>
#include <map>

class Map {
    int width;
    int height;
    Renderer *renderer;
    MapSettings settings;
    std::vector<MapEntity*> mapEntities;
    std::map<Coordinates, MapEntity*> mapCoordinates;

public:
    Map(int width, int height, MapSettings settings, Renderer *renderer);
    ~Map();
    void initObstacles();
    void render() const;
    void update();
};

#endif //BLIND_SHOOTER_MAP_H

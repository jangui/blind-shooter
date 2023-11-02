
#include "Map.h"

Map::Map(int width, int height, MapSettings settings, Renderer *renderer) :
    width(width), height(height), settings(settings), renderer(renderer)
{
    initObstacles();
}

Map::~Map() {
    for (auto entity : mapEntities) {
        if (entity) {delete entity; entity = nullptr;}
        // TODO deconstructors
    }
}

void Map::initObstacles() {
    // create border
    int borderLongWidth = width - settings.borderWidth - settings.borderSpacer;
    int borderLongHeight = height - settings.borderHeight - settings.borderSpacer;
    Obstacle *topBorder = new Obstacle(settings.borderSpacer, settings.borderSpacer, borderLongWidth, settings.borderHeight, settings.borderColor, renderer);
    Obstacle *bottomBorder = new Obstacle(settings.borderSpacer, height-settings.borderHeight-settings.borderSpacer, borderLongWidth, settings.borderHeight, settings.borderColor, renderer);
    Obstacle *leftBorder = new Obstacle(settings.borderSpacer, settings.borderSpacer, settings.borderWidth, borderLongHeight, settings.borderColor, renderer);
    Obstacle *rightBorder = new Obstacle(width-settings.borderWidth-settings.borderSpacer, settings.borderSpacer, settings.borderWidth, borderLongHeight, settings.borderColor, renderer);
    mapEntities.push_back(topBorder);
    mapEntities.push_back(bottomBorder);
    mapEntities.push_back(leftBorder);
    mapEntities.push_back(rightBorder);

    // TODO add obstacles coordinates to coordinate map

    // create other obstacles
    mapEntities.push_back(new Obstacle(width/2-100, height/2-100, 100, 40, settings.borderColor, renderer));
}

void Map::render() const {
    // clear screen
    renderer->clearScreen(settings.bgColor);

    // render obstacles
    for (auto entity : mapEntities) {
        entity->render();
    }
}

void Map::update() {}


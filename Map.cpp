//
// Created by Jaime on 10/30/23.
//

#include "Map.h"

Map::Map(int width, int height, Renderer *renderer) :
    width(width), height(height), renderer(renderer), borderWidth(20), borderHeight(20)
    {
    bgColor = {40, 0, 0, 255};
    borderColor = {0, 0, 50, 255};
}

Map::~Map() {

}

void Map::render() const {
    // clear screen
    renderer->clearScreen(bgColor);

    // render map
    renderBorder();
}

void Map::update() {

}

void Map::renderBorder() const {
    // top border
    renderer->drawRect(0, 0, width, borderHeight, borderColor);
    // bottom border
    renderer->drawRect(0, height-borderHeight, width, borderHeight, borderColor);
    // left border
    renderer->drawRect(0, 0, borderWidth, height, borderColor);
    // right border
    renderer->drawRect(width-borderWidth, 0, borderWidth, height, borderColor);
}

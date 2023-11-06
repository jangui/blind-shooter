#ifndef BLIND_SHOOTER_DATATYPES_H
#define BLIND_SHOOTER_DATATYPES_H

struct Coordinates {
    int x, y;
};

struct Color {
    int r, g, b, a;
};

struct MapSettings {
    Color bgColor;
    Color borderColor;
    int borderWidth;
    int borderHeight;
    int borderSpacer;
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

#endif //BLIND_SHOOTER_DATATYPES_H

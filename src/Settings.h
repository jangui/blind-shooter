#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings {
public:
    Settings();
    std::string title;
    int screenWidth;
    int screenHeight;
    std::string spriteSheetFilePath;
    int spriteSheetDimensions;
    int spriteCount;
    int fps;
    int frameDelay;
};

#endif //SETTINGS_H

#include "Player.h"

Player::Player(const char *textureFilePath, int x, int y, SDL_Renderer *renderer) : Entity(textureFilePath, x, y, renderer) {
    rect.w = rect.w / 8;
    rect.h = rect.h / 8;
    xVelocity = 0;
    yVelocity = 0;
    speed = 7;
    return;
}

void Player::update() {
    rect.x += xVelocity;
    rect.y += yVelocity;
    xVelocity = 0;
    yVelocity = 0;
}

void Player::modifyXVelocity(int velocity) {
    xVelocity += velocity * speed;
}

void Player::modifyYVelocity(int velocity) {
    yVelocity += velocity * speed;
}

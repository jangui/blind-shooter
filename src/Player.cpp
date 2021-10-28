#include "Player.h"

Player::Player(int x, int y, Texture *texture, SDL_Rect *clip) : Entity(x, y, texture, clip) {
    xVelocity = 0;
    yVelocity = 0;
    speed = 7;
    return;
}

void Player::update() {
    x += xVelocity;
    y += yVelocity;
    xVelocity = 0;
    yVelocity = 0;
}

void Player::modifyXVelocity(int velocity) {
    xVelocity += velocity * speed;
}

void Player::modifyYVelocity(int velocity) {
    yVelocity += velocity * speed;
}

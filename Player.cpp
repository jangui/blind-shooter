

#include "Player.h"

Player::Player(int x, int y, Color color, Renderer *renderer) :
    x(x), y(y), color(color), renderer(renderer) {}

Player::~Player() {}

void Player::render() {
    renderer->drawRect(x, y, 20, 20, color);
}

void Player::update() {
    float vMagnitude = sqrt(vx*vx + vy*vy);
    if (vx != 0) {
        vx = vx * speed / vMagnitude;
    }
    if (vy != 0) {
        vy = vy * speed / vMagnitude;
    }
    x += vx;
    y += vy;
    vx = 0;
    vy = 0;
}

void Player::shoot() {}

void Player::move(Direction direction) {
    if (direction == UP) {
        vy -= 1;
    } else if (direction == DOWN) {
        vy += 1;
    } else if (direction == LEFT) {
        vx -= 1;
    } else if (direction == RIGHT) {
        vx += 1;
    }
}

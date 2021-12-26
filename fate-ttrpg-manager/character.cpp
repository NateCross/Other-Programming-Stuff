#include <iostream>
#include <string>
#include "character.hpp"

Character::Character() {
    aspectNum = 0;
    setName("");
    setFatePts(3);
    for (int i = 0; i < ASPECT_MAX; i++)
        setAspect("", i);
}

Character::Character(const std::string& name) : Character() {
    setName(name);
}

Character::Character(const std::string& name, const int& fp)
    : Character(name) {
        setFatePts(fp);
    }

void Character::setName(const std::string& name) {
    characterName = name;
}

void Character::setAspect(const std::string& asp, const int& pos) {
    aspect[pos] = asp;
    countAspects();
}

void Character::setFatePts(const int& fp = 3) {
    fatePts = fp;
}

const std::string Character::getName() {
    return characterName;
}

const std::string Character::getAspect(const int& pos) {
    return aspect[pos];
}

const int Character::getFatePts() {
    return fatePts;
}

const int Character::getAspectNum() {
    return aspectNum;
}

void Character::addAspect(const std::string& asp) {
    aspect[aspectNum] = asp;
    countAspects();
}

void Character::swapAspect(const int& pos1, const int& pos2) {
    aspect[pos1].swap(aspect[pos2]);
}

void Character::countAspects() {
    aspectNum = 0;
    for (int i = 0; i < ASPECT_MAX; i++) {
        if (aspect[i] != "")
            ++aspectNum;
    }
}

const void Character::displayAllAspects() {
    for (int i = 0; i < ASPECT_MAX; i++) {
        if (aspect[i] != "")
            std::cout << i << ": " << aspect[i] << "\n";
    }
}

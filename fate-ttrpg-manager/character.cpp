#include <iostream>
#include <string>
#include "character.hpp"

Character::Character() {
    setName("");
    setFatePts(3);
    for (int i = 0; i < ASPECT_MAX; i++)
        setAspect("", i);
    for (int i = 0; i < ASPECT_MAX; i++)
        setStunt("", i);
    aspectCount = 0;
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
    if (aspect[pos] == "")
        ++aspectCount;
    aspect[pos] = asp;
    // countAspects();
}

void Character::setStunt(const std::string& stn, const int& pos) {
    if (stunt[pos] == "")
        ++stuntCount;
    stunt[pos] = stn;
}

void Character::setFatePts(const int& fp = 3) {
    fatePts = fp;
}

const std::string& Character::getName() {
    return characterName;
}

const std::string& Character::getAspect(const int& pos) {
    return aspect[pos];
}

const std::string& Character::getStunt(const int& pos) {
    return stunt[pos];
}

const int Character::getFatePts() {
    return fatePts;
}

const int Character::getAspectNum() {
    return aspectCount;
}

void Character::addAspect(const std::string& asp) {
    setAspect(asp, aspectCount);
    // aspect[aspectNum] = asp;
    // countAspects();
}

bool Character::deleteAspect(const int& pos) {
    if (aspect[pos] == "")
        return false;
    aspect[pos] = "";
    --aspectCount;
    return true;
}

void Character::swapAspect(const int& pos1, const int& pos2) {
    aspect[pos1].swap(aspect[pos2]);
}

// void Character::countAspects() {
//     aspectNum = 0;
//     for (int i = 0; i < ASPECT_MAX; i++) {
//         if (aspect[i] != "")
//             ++aspectNum;
//     }
// }

const void Character::displayAllAspects() {
    for (int i = 0; i < ASPECT_MAX; i++) {
        if (aspect[i] != "")
            std::cout << i << ": " << aspect[i] << "\n";
    }
}

void Character::addStunt(const std::string& stn) {
    setStunt(stn, stuntCount);
    // aspect[aspectNum] = asp;
    // countAspects();
}

bool Character::deleteStunt(const int& pos) {
    if (stunt[pos] == "")
        return false;
    stunt[pos] = "";
    --stuntCount;
    return true;
}

void Character::swapStunt(const int& pos1, const int& pos2) {
    stunt[pos1].swap(stunt[pos2]);
}

const void Character::displayAllStunts() {
    for (int i = 0; i < ASPECT_MAX; i++) {
        if (stunt[i] != "")
            std::cout << i << ": " << stunt[i] << "\n";
    }
}

void Character::addFatePoint() {
    ++fatePts;
}

void Character::removeFatePoint() {
    --fatePts;
}

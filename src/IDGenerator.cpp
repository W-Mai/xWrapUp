//
// Created by W-Mai on 2023/2/28.
//

#include "IDGenerator.h"

IDGenerator::IDGenerator(IDType stp) {
    IDGenerator::step = stp;
    current           = 0;
}
IDGenerator::operator IDType() { return current += step; }
IDGenerator &IDGenerator::operator=(IDGenerator::IDType val) {
    if (current > val) {
        current += step;
    } else {
        current = val;
    }
    return *this;
}
IDGenerator &IDGenerator::instance() {
    if (gen == nullptr) { gen = new IDGenerator(STEP); }
    return *gen;
}

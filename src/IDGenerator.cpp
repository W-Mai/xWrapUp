//
// Created by W-Mai on 2023/2/28.
//

#include "IDGenerator.h"

IDGenerator::IDGenerator(IDType stp) {
    IDGenerator::step = stp;
    current           = 0;
}
IDGenerator::operator IDType() { return get(); }
IDGenerator &IDGenerator::operator=(IDGenerator::IDType val) {
    set(val);
    return *this;
}
IDGenerator &IDGenerator::instance() {
    static auto ins = new IDGenerator(STEP);
    return *ins;
}
IDGenerator::IDType IDGenerator::get() { return instance().current++; }
IDGenerator::IDType IDGenerator::set(IDGenerator::IDType val) {
    instance().current = val;
    return instance().current;
}
IDGenerator::IDType IDGenerator::bump() {
    instance().current += instance().step;
    return instance().current;
}

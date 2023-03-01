//
// Created by W-Mai on 2023/2/28.
//

#ifndef XWRAPUP_IDGENERATOR_H
#define XWRAPUP_IDGENERATOR_H
#include <cinttypes>

class IDGenerator {
public:
    using IDType = int32_t;


private:
    IDType step;
    IDType current;

public:
    explicit IDGenerator(IDType stp);

    explicit operator IDType();
    IDGenerator &operator=(IDType val);

    static IDType get();
    static IDType set(IDType val);
    static IDType bump();

    static IDGenerator &instance();
};

static const IDGenerator::IDType STEP = 100;

#endif//XWRAPUP_IDGENERATOR_H

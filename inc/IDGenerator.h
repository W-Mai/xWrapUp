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
    static IDType step;
    static IDType current;
    IDGenerator *gen = nullptr;

public:
    explicit IDGenerator(IDType stp);

    explicit operator IDType();
    IDGenerator &operator=(IDType val);

    IDGenerator &instance();
};

static const IDGenerator::IDType STEP = 100;

#endif//XWRAPUP_IDGENERATOR_H

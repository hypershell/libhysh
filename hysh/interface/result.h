
#pragma once

#include <stdint.h>

typedef uint64_t hyresult;

#define RETURN_IF_FAIL(res) \
    if(res != HY_OK) return res;

#define HY_DEFINE_RESULT(name, code) \
    static const hyresult name = code

HY_DEFINE_RESULT(HY_OK,                 0x00);
HY_DEFINE_RESULT(HY_NOT_IMPLEMENTED,    0x02);
HY_DEFINE_RESULT(HY_NULL_PTR,           0x05);
HY_DEFINE_RESULT(HY_FAIL,               0x10);
HY_DEFINE_RESULT(HY_NOT_FOUND,          0x11);
HY_DEFINE_RESULT(HY_CONSTRUCTOR_ERROR,  0x12);
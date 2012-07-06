
#pragma once

#include <stdint.h>

typedef uint64_t hyresult;

#define HY_IS_SUCCESS(res) \
    (res & 0xFFFFFFFF == HY_OK)

#define RETURN_IF_FAIL(res) \
    if(!HY_IS_SUCCESS(res)) { return res; }
    
#define TRACE_IF_FAIL(tracer, res)

#define HY_DEFINE_RESULT(name, code) \
    static const hyresult name = code

HY_DEFINE_RESULT(HY_OK,                 0x00);
HY_DEFINE_RESULT(HY_FAIL,               0x01);
HY_DEFINE_RESULT(HY_NOT_IMPLEMENTED,    0x02);
HY_DEFINE_RESULT(HY_NULL_PTR,           0x05);
HY_DEFINE_RESULT(HY_NOT_FOUND,          0x11);
HY_DEFINE_RESULT(HY_CONSTRUCTOR_ERROR,  0x12);
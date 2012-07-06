
#pragma once

extern "C" {
#include <hysh/interface/result.h>
}

class Result {
  public:
     Result() :
        Result(HY_OK)
    { }
    
    Result(hyresult result) :
        mResult(result)
    { }
    
    Result(const Result& other) :
        mResult(other.mResult)
    { }

    bool IsSuccess() {
        return ResultCode() == HY_OK;
    }

    /*
     * 32-bit result code
     */
    uint32_t ResultCode() {
        return mResult & 0xFFFFFFFF;
    }
    
    /*
     * 8-bit result category
     */
    uint8_t ResultCategory() {
        return (mResult >> 32) & 0xFF;
    }
    
    /*
     * 24-bit result tag
     */
    uint32_t ResultTag() {
        return (mResult >> 36) & 0xFFFFFF;
    }
    
    operator bool() {
        return IsSuccess();
    }
    
    operator hyresult() {
        return mResult;
    }
    
    Result& operator =(Result result) {
        mResult = result;
        
        return *this;
    }
    
  private:
    hyresult mResult;
};
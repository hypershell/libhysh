
#pragma once

#include <hysh/interface/data_buffer.h>
#include <hysh/impl_wrapper/SimpleRefcounted.hpp>
#include <hysh/impl_wrapper/AllocatorImpl.hpp>

#define SimpleDataBufferCid 0x19d2f349b66a9911

namespace hysh {

class SimpleDataBuffer : 
    public hy_data_buffer,
    public SimpleRefcounted<SimpleDataBuffer>,
    public DestructorImpl<SimpleDataBuffer>
{
  public:
    static const hy_cid ClassId = SimpleDataBufferCid;
      
    SimpleDataBuffer();
    
    hyresult Init(char *buffer, size_t size, DeallocatorPtr buffer_dealloc);
    
    hyresult Buffer(const char **retval);

    hyresult Size(uint64_t *retval);
    
    hyresult QueryInterface(hy_iid iid, hy_object **retval);
    
    hyresult Uninit();
    
    ~SimpleDataBuffer();
    
  private:
    char        *mBuffer;
    uint64_t    mSize;
    DeallocatorPtr mBufferDealloc;
};

}
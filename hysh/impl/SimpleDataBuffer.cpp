
// #include <hysh/impl_wrapper/QueryInterface.hpp>
#include <hysh/impl_wrapper/DataBufferImpl.hpp>
#include <hysh/impl/SimpleDataBuffer.hpp>

namespace hysh {

SimpleDataBuffer::SimpleDataBuffer() :
    mBuffer(0),
    mSize(0)
{ 
    DataBufferImpl<SimpleDataBuffer>::Init(this, this);
}

hyresult SimpleDataBuffer::Init(char *buffer, size_t size, DeallocatorPtr dealloc) {
    mBuffer = buffer;
    mSize = size;
    mBufferDealloc = dealloc;
    
    return HY_OK;
}

hyresult SimpleDataBuffer::Buffer(const char **retval) {
    *retval = mBuffer;
    return HY_OK;
}

hyresult SimpleDataBuffer::Size(uint64_t *retval) {
    *retval = mSize;
    return HY_OK;
}

hyresult SimpleDataBuffer::QueryInterface(hy_iid iid, hy_object **retval) {
    // return QueryInterface<SimpleDataBuffer, DataBuffer>(this, iid, retval);
    return HY_NOT_IMPLEMENTED;
}

hyresult SimpleDataBuffer::Uninit() {
    return mBufferDealloc.Deallocate(mBuffer);
}

SimpleDataBuffer::~SimpleDataBuffer() {

}

}
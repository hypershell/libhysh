
extern "C" {    
#include <hysh/impl/default_allocator.h>
}

#include <new>
#include <hysh/wrapper/Allocator.hpp>
#include <hysh/wrapper/DataBuffer.hpp>
#include <hysh/wrapper/DataBufferFactory.hpp>
#include <hysh/impl_wrapper/Constructor.hpp>
#include <hysh/impl/SimpleDataBuffer.hpp>

using namespace hysh;

int main(int argc, char **argv) {
    const size_t test_size = 1024;
    
    hyresult res;
    AllocatorPtr alloc;
    char *buffer;
    
    res = hy_default_allocator(alloc.EditPtr());
    
    res = alloc.Allocate(test_size, (void**) &buffer);
    
    SimpleDataBuffer *data_buffer;
    res = Construct<SimpleDataBuffer>(alloc, &data_buffer);
    
    res = data_buffer->Init(buffer, test_size, alloc);
    
    DataBufferPtr buffer_ptr = data_buffer;
}
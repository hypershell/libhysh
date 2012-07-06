
#include <hysh/impl_wrapper/ObjectImpl.hpp>

namespace hysh {

template <typename Parent>
class SimpleRefcounted
{
  public:
    SimpleRefcounted() :
        mCount(0)
    { }
      
    hyresult AddRef() {
        ++mCount;
        return HY_OK;
    }
    
    hyresult DeRef() {
        Result res;
        
        TracerPtr tracer;
        res = This()->GetTracer(tracer.EditPtr());
        
        if(mCount > 0) {
            --mCount;
        }
        
        if(mCount == 0) {
            res = This()->Destruct();
            RETURN_IF_FAIL(res, tracer);
        }
        
        return res;
    }
    
    static hyresult Destructor(void *self) {
        return ((Parent*)self)->DeRef();
    }
    
  private:
    Parent* This() {
        return static_cast<Parent*>(this);
    }
      
    uint32_t mCount;
};

}
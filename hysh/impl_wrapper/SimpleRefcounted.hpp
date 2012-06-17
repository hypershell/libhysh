
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
        hyresult res = HY_OK;
        
        if(mCount > 0) {
            --mCount;
        }
        
        if(mCount == 0) {
            res = static_cast<Parent*>(this)->Destruct();
        }
        
        return res;
    }
    
    static hyresult Destructor(void *self) {
        return ((Parent*)self)->DeRef();
    }
    
  private:
    uint32_t mCount;
};

}
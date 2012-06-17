
#pragma once

namespace hysh {

template <typename Class>
hyresult QueryInterface(Class *obj, hy_iid iid, hy_object **retval) {
    return HY_NOT_FOUND;
}

template <typename Class, typename Interface, typename... Rest>
hyresult QueryInterface(Class *obj, hy_iid iid, hy_object **retval) {
    if(iid == Interface::InterfaceId) {
        *retval = static_cast<hy_object*>(static_cast<typename Interface::CType*>(obj));
        return HY_OK;
    } else {
        return QueryInterface<Class, Rest...>(obj, iid, retval);
    }
}

}
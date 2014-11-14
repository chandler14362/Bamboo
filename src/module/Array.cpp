// Filename: Array.cpp
#include "Array.h"
using namespace std;
namespace bamboo
{


Array::Array(Type *element_type, const NumericRange& size) : m_element_type(element_type)
{
    if(m_element_type == nullptr) {
        m_element_type = Type::None;
    }

    // Set array bounds
    if(!size.is_nan() && size.min == size.max) {
        m_array_size = (unsigned int)size.min;
    } else {
        m_array_size = 0;
        m_array_range = size;
    }

    // Set subtype
    if(m_element_type->subtype() == kTypeChar) {
        m_subtype = kTypeString;
    } else if(m_element_type->subtype() == kTypeUint8) {
        m_subtype = kTypeBlob;
    } else {
        m_subtype = kTypeArray;
    }

    // Set bytesize
    if(m_array_size > 0 && m_element_type->has_fixed_size()) {
        m_size = m_array_size * m_element_type->fixed_size();
    } else {
        m_size = 0;
    }
}

Array::Array(Type *element_type, const string& alias) : Type(alias), m_element_type(element_type)
{
    if(m_element_type == nullptr) {
        m_element_type = Type::None;
    }

    // Set subtype
    if(m_element_type->subtype() == kTypeChar) {
        m_subtype = kTypeString;
    } else if(m_element_type->subtype() == kTypeUint8) {
        m_subtype = kTypeBlob;
    } else {
        m_subtype = kTypeArray;
    }
}

Array *Array::as_array()
{
    return this;
}

const Array *Array::as_array() const
{
    return this;
}


} // close namespace bamboo

/************************************************************************************
*                                                                                   *
*   Copyright (c) 2014, 2015 Axel Menzel <info@axelmenzel.de>                       *
*                                                                                   *
*   This file is part of RTTR (Run Time Type Reflection)                            *
*   License: MIT License                                                            *
*                                                                                   *
*   Permission is hereby granted, free of charge, to any person obtaining           *
*   a copy of this software and associated documentation files (the "Software"),    *
*   to deal in the Software without restriction, including without limitation       *
*   the rights to use, copy, modify, merge, publish, distribute, sublicense,        *
*   and/or sell copies of the Software, and to permit persons to whom the           *
*   Software is furnished to do so, subject to the following conditions:            *
*                                                                                   *
*   The above copyright notice and this permission notice shall be included in      *
*   all copies or substantial portions of the Software.                             *
*                                                                                   *
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
*   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
*   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
*   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
*   SOFTWARE.                                                                       *
*                                                                                   *
*************************************************************************************/

#include "rttr/property.h"

#include "rttr/detail/property/property_wrapper_base.h"
#include "rttr/variant.h"
#include "rttr/argument.h"
#include "rttr/instance.h"
#include "rttr/enumeration.h"

using namespace std;

namespace rttr
{

/////////////////////////////////////////////////////////////////////////////////////////

property::property(const detail::property_wrapper_base* container)
:   m_container(container)
{

}

/////////////////////////////////////////////////////////////////////////////////////////

bool property::is_valid() const
{
    return (m_container ? true : false);
}

/////////////////////////////////////////////////////////////////////////////////////////

property::operator bool() const
{
    return (m_container ? true : false);
}

/////////////////////////////////////////////////////////////////////////////////////////

bool property::is_readonly() const
{
    if (is_valid())
        return m_container->is_readonly();
    else
        return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

bool property::is_static() const
{
    if (is_valid())
        return m_container->is_static();
    else
        return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

bool property::is_enumeration() const
{
    if (is_valid())
        return m_container->get_type().is_enumeration();
    else
        return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

enumeration property::get_enumeration() const
{
    if (is_valid())
        return m_container->get_type().get_enumeration();
    else
        return detail::get_invalid_type().get_enumeration();
}

/////////////////////////////////////////////////////////////////////////////////////////

bool property::is_array() const
{
    if (is_valid())
        return m_container->is_array();
    else
        return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

string property::get_name() const
{
    if (is_valid())
        return m_container->get_name();
    else
        return string();
}

/////////////////////////////////////////////////////////////////////////////////////////

type property::get_type() const
{
    if (is_valid())
        return m_container->get_type();
    else
        return detail::get_invalid_type();
}

/////////////////////////////////////////////////////////////////////////////////////////

type property::get_declaring_type() const
{
    if (is_valid())
        return m_container->get_declaring_type();
    else
        return detail::get_invalid_type();
}

/////////////////////////////////////////////////////////////////////////////////////////

bool property::set_value(instance object, argument arg) const
{
    if (is_valid())
        return m_container->set_value(object, arg);
    else
        return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

variant property::get_value(instance object) const
{
    if (is_valid())
        return m_container->get_value(object);
    else
        return variant();
}

/////////////////////////////////////////////////////////////////////////////////////////

variant property::get_meta_data(const variant& key) const
{
    if (is_valid())
        return m_container->get_meta_data(key);
    else
        return variant();
}

/////////////////////////////////////////////////////////////////////////////////////////

bool property::operator==(const property& other) const
{
    return (m_container == other.m_container); 
}

/////////////////////////////////////////////////////////////////////////////////////////

bool property::operator!=(const property& other) const
{
    return (m_container != other.m_container); 
}

/////////////////////////////////////////////////////////////////////////////////////////

} // end namespace rttr

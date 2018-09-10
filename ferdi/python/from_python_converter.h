// Licensed under the MIT License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software distributed 
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
// CONDITIONS OF ANY KIND, either express or implied. See the License for the 
// specific language governing permissions and limitations under the License.

#pragma once

#include <boost/python.hpp>
#include <boost/property_tree/ptree.hpp>

namespace ferdi {
namespace python {

template <typename ContainerType>    
ContainerType ConvertFromPythonList(const boost::python::list& py_list);

/** Can't handle nested structures */
boost::property_tree::ptree ConvertFromPythonDictionaryToPtree(const boost::python::dict& dict);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
template <typename ContainerType>    
inline ContainerType ConvertFromPythonList(const boost::python::list& py_list) {
    ContainerType container;
    typedef typename ContainerType::value_type ValueType;
    const auto length = len(py_list);
    for (int i = 0; i < length; ++i) {
        const boost::python::extract<ValueType> extracted_value(py_list[i]);
        if (extracted_value.check()){  
            container.push_back(extracted_value);
        } else {
            throw std::invalid_argument(std::string(__FUNCTION__) + "::Error: invalid value.");
        }
    }
    return container;
}

inline boost::property_tree::ptree ConvertFromPythonDictionaryToPtree(const boost::python::dict& dict) {
    boost::property_tree::ptree tree;
    const auto keys = dict.keys();  
    for (int i=0; i<len(keys); ++i) {  
        const boost::python::extract<std::string> extracted_key(keys[i]); 
        const std::string key = extracted_key;  
        
        const boost::python::extract<std::string> extracted_val_str(dict[key]);  
        if (extracted_val_str.check()) {  
            std::string value = extracted_val_str;
            tree.put<std::string>(key, value);
        }  else {
            const boost::python::extract<double> extracted_val_double(dict[key]);  
            if (extracted_val_double.check()) {  
                const double value = extracted_val_double;
                tree.put<double>(key, value);
            } else {
                throw std::invalid_argument(std::string(__FUNCTION__) + "::Error: don't know how to handle type.");
            }
        }        
    }    
    return tree;
}



}  // namespace
}  // namespace

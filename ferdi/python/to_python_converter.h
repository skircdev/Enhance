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

namespace ferdi {
namespace python {

template<class ContainerType>
boost::python::list ConvertToPythonList(const ContainerType& container);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
template<class ContainerType>
inline boost::python::list ConvertToPythonList(const ContainerType& container) {
    boost::python::list ret;
    for (const auto& e: container) {
        ret.append(e);
    }
    return ret;
}

}  // namespace
}  // namespace

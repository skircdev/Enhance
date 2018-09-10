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

#include <string>
#include <fstream>

namespace ferdi {
namespace iostreams {

/** Note there is a specialisation for std::string */    
template <typename ValueType> void WriteValueToStream(const ValueType& value, std::ofstream* file);
template <typename ValueType> void ReadValueFromStream(std::ifstream& file, ValueType* value);


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <>
inline void WriteValueToStream<std::string>(const std::string& value, std::ofstream* file) {
    const size_t length = value.size();
    WriteValueToStream(length, file);
    if (length > 0) {
            file->write(value.c_str(), length);
    }
}

template <typename ValueType>
inline void WriteValueToStream(const ValueType& value, std::ofstream* file) {
    file->write((char*)&value, sizeof(ValueType));
}

template <>
inline void ReadValueFromStream<std::string>(std::ifstream& file, std::string* value) {
    size_t length = 0;
    ReadValueFromStream(file, &length);
    if (length > 0) {
            char* temp = new char[length + 1];
            file.read(temp, length);
            temp[length] = '\0';
            (*value) = temp;
            delete[] temp;
    }
}

template <typename ValueType>
inline void ReadValueFromStream(std::ifstream& file, ValueType* value) {
    file.read((char*)value, sizeof(ValueType));
}

}  // namespace iostreams
}  // namespace ferdi

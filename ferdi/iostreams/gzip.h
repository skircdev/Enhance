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

#include <boost/filesystem.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/copy.hpp>

namespace ferdi {
namespace iostreams {

/** Mimics linux command 'gzip'. 'remove_src' is the inverse of '--keep' */
::boost::filesystem::path ZipFile(const ::boost::filesystem::path& src_filename, bool remove_src);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//  https://stackoverflow.com/questions/30154080/using-boost-to-compress-and-decompress-gzip-streams
::boost::filesystem::path ZipFile(const ::boost::filesystem::path& src_filename, bool remove_src) {
    ::boost::filesystem::path dst_filename;
    if (exists(src_filename)) {
        dst_filename = src_filename.string() + ".gz";
        std::ifstream src_file(src_filename.string());
        std::ofstream dst_file(dst_filename.string());
        boost::iostreams::filtering_streambuf< boost::iostreams::input> compressor;
        compressor.push(boost::iostreams::gzip_compressor());
        compressor.push(src_file);
        boost::iostreams::copy(compressor, dst_file);
        if (remove_src && exists(dst_filename)) {
            boost::filesystem::remove(src_filename);
        }
    }
    return dst_filename;
}

}  // namespace
}  // namespace
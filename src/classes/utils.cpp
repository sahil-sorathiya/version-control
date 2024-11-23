#include "../headers.h"

//: Decompress an STL string using zlib and return the original data.
string Utils::decompress(const string& str) {

    //: z_stream is zlib's control structure
    z_stream zs;                        
    memset(&zs, 0, sizeof(zs));

    if (inflateInit(&zs) != Z_OK) {
        throw(runtime_error("inflateInit failed while decompressing."));
    }

    zs.next_in = (Bytef*)str.data();
    zs.avail_in = str.size();

    int ret;
    char outbuffer[10240];
    string outstring;

    //: Get the decompressed bytes blockwise using repeated calls to inflate
    do {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);

        ret = inflate(&zs, 0);

        if (outstring.size() < zs.total_out) {
            //: Append the block to the output string
            outstring.append(outbuffer, zs.total_out - outstring.size());
        }

    } while (ret == Z_OK);

    inflateEnd(&zs);

    //: An error occurred that was not EOF
    if (ret != Z_STREAM_END) {          
        ostringstream oss;
        oss << "Exception during zlib decompression: (" << ret << ") " << zs.msg;
        throw(runtime_error(oss.str()));
    }

    return outstring;
}

//: Reading file from given filePath
string Utils::readFile(const string& filePath) {

    //: Open the file in binary format
    ifstream file(filePath, ios::binary);
    if (!file.is_open()) {
        throw(runtime_error("Error opening file!"));
    }

    //: Read file content into the buffer
    stringstream buffer;
    buffer << file.rdbuf();

    //: Close the file
    file.close();

    //: returning the string
    return buffer.str(); 
}
#include "../headers.h"

void catFile(const string& flag, const string& sha) {
    
    //: Building filePath
    const string dirPath = string(GIT_DIRECTORY_PATH) + "/objects/" + sha.substr(0, 2) + "/";
    const string fileName = sha.substr(2);
    const string filePath = dirPath + fileName;
    
    //: Reading file content in binary
    const string fileData = Utils::readFile(filePath);
    
    //: Decompressing file content using zlib
    const string decompressedData = Utils::decompress(fileData);

    //: Find the first blank space
    const size_t blank_space_index = decompressedData.find(' ');
    //: Find the null char, starting after the first word
    const size_t null_char_index = decompressedData.find('\0', blank_space_index + 1);

    //: Extracting all three fields
    const string type = decompressedData.substr(0, blank_space_index);
    const string size = decompressedData.substr(blank_space_index + 1, null_char_index - blank_space_index - 1);
    const string content = decompressedData.substr(null_char_index + 1);

    //: Printing to stdout according to given flag
    if (flag == "-t") cout << type;
    if (flag == "-s") cout << size;
    if (flag == "-p") cout << content;

    //: flag -d means debug flag, it will print all three values
    if (flag == "-d") {
        cout << "type : " << type << endl;
        cout << "size : " << size << endl;
        cout << "content : " << content << endl;
    }
}
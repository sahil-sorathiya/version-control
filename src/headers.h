#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include <filesystem>

#include <zlib.h>
#include <stdexcept>
#include <iomanip>
#include <openssl/sha.h>

#define GIT_DIRECTORY_PATH "./myGit"
#define AUTHOR "Sahil Patel"
#define AUTHOR_MAIL "sahil.patel4125@gmail.com"
#define COMMITTER "Sahil Patel"
#define COMMITTER_MAIL "sahil.patel4125@gmail.com"

using namespace std;

//: Utils.cpp
class Utils{
    public:
        static string decompress(const string& );
        static string readFile(const string& );
};

//: init.cpp
void init();

//: catFile.cpp
void catFile(const string& , const string& );

#endif // HEADERS_H
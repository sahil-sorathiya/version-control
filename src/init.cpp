#include "headers.h"

void init(){
    //: Creating necessory directories
    filesystem::create_directory(string(GIT_DIRECTORY_PATH));
    filesystem::create_directory(string(GIT_DIRECTORY_PATH) + "/objects");
    filesystem::create_directory(string(GIT_DIRECTORY_PATH) + "/refs");

    //: Writing "ref: refs/heads/main" in HEAD file
    ofstream headFile(string(GIT_DIRECTORY_PATH) + "/HEAD");
    if (headFile.is_open()) {
        headFile << "ref: refs/heads/main\n";
        headFile.close();
    } else {
        throw(runtime_error("Failed to create " + string(GIT_DIRECTORY_PATH) + "/HEAD file."));
    }
    cout << "Initialized git directory\n";
}
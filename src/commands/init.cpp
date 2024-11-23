#include "../headers.h"

void init() {
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

    //: Checking if already a repo or not
    //: If already initialized as a repo and if objects and refs not exitst
    //: then we created them
    if (filesystem::exists(string(GIT_DIRECTORY_PATH))) {
        cout << "Reinitialised Git repository in " << (filesystem::current_path() / string(GIT_DIRECTORY_PATH)).lexically_normal() << endl;
    }
    else {
        cout << "Initialised empty Git repository in " << (filesystem::current_path() / string(GIT_DIRECTORY_PATH)).lexically_normal() << endl;
    }
}
#include "headers.h"

int main(int argc, char *argv[])
{
    //: Flush after every cout / cerr
    cout << unitbuf;
    cerr << unitbuf;

    if (argc < 2) {
        cerr << "No command provided.\n";
        return EXIT_FAILURE;
    }
    
    const string command = argv[1];
    
    //: INIT COMMAND
    if (command == "init") {
        try {
            filesystem::create_directory(string(GIT_DIRECTORY_PATH));
            filesystem::create_directory(string(GIT_DIRECTORY_PATH) + "/objects");
            filesystem::create_directory(string(GIT_DIRECTORY_PATH) + "/refs");
    
            ofstream headFile(string(GIT_DIRECTORY_PATH) + "/HEAD");
            if (headFile.is_open()) {
                headFile << "ref: refs/heads/main\n";
                headFile.close();
            } else {
                cerr << "Failed to create " + string(GIT_DIRECTORY_PATH) + "/HEAD file.\n";
                return EXIT_FAILURE;
            }
    
            cout << "Initialized git directory\n";
        } catch (const filesystem::filesystem_error& e) {
            cerr << "Caught a filesystem_error: " << e.what() << endl;
            return EXIT_FAILURE;
        }
    }
    //: Command Not Found
    else {
        cerr << "Unknown command " << command << '\n';
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

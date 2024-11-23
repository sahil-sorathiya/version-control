#include "headers.h"

int main(int argc, char *argv[]) {

    try {
        //: Flush after every cout / cerr
        cout << unitbuf;
        cerr << unitbuf;

        if (argc < 2) {
            throw(runtime_error("No command provided."));
        }

        //: Reading command from stdin
        const string command = argv[1];

        if (command == "init") {
            init();
        }
        else if (command == "cat-file") {

            //: Validating number of args
            if (argc != 4) {
                throw(runtime_error("Invalid number of args!!"));
            }

            const string flag = argv[2];
            const string sha = argv[3];

            //: Validating flag value
            //: Flag -d means debug flag
            if (flag != "-d" && flag != "-t" && flag != "-s" && flag != "-p") {
                throw(runtime_error("Unknown flag " + flag));
            }

            //: Validating sha value
            if (sha.size() != 40){
                throw(runtime_error("Invalid SHA!!"));
            }

            //: Running the command
            catFile(flag, sha);
        }
        //: Command Not Found
        else {
            throw(runtime_error("Unknown command " + command));
        }
    }
    catch (const filesystem::filesystem_error& e) {
        cerr << "Caught a filesystem_error: " << e.what() << endl;
        return EXIT_FAILURE;
    }
    catch (const runtime_error& e) {
        cerr << "Caught a runtime_error: " << e.what() << endl;
        return EXIT_FAILURE;
    } 
    catch (const exception& e) {
        cerr << "Caught a general exception: " << e.what() << endl;
        return EXIT_FAILURE;
    } 
    catch (...) {
        cerr << "Caught an unknown exception." << endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

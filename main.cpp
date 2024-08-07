#include <bits/stdc++.h>
#include <filesystem>
#include "file organization.h"
using namespace std;
int main() {
    string path;cin>>path;
    if(!filesystem :: exists(path)) {
        cout << "Error: Path does not exist." << endl;
        cout << "Please Enter The Right Path: ";
        main();
    }
    else {
        filesystem::current_path(path.c_str());
        createFolders();
        organizeFiles(path);
        cout << "The organization process was completed successfully.";
    }
    return 0;
}


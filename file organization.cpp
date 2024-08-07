#include "file organization.h"
#include <bits/stdc++.h>
#include <direct.h>
#include <filesystem>
using namespace std;
void createFolders() {
    _mkdir("image");
    _mkdir("video");
    _mkdir("docs");
    _mkdir("programs");
    _mkdir("text");
    _mkdir("other");
}
void organizeFiles(string path) {
    string imagePath = path + "\\image\\";
    string videoPath = path + "\\video\\";
    string textPath = path + "\\text\\";
    string programsPath = path + "\\programs\\";
    string docsPath = path + "\\docs\\";
    string otherPath = path + "\\other\\";

    for (const auto &file : filesystem::directory_iterator(path)) {
        string extension = file.path().extension().string();
        string filename = file.path().filename().string();

            if (extension == ".jpg" || extension == ".png" || extension == ".avif" || extension == ".gif") {
                filesystem::rename(file.path(), imagePath + filename);
            }
            else if (extension == ".mp4" || extension == ".avi" || extension == ".wmv" || extension == ".mpv") {
                filesystem::rename(file.path(), videoPath + filename);
            }
            else if (extension == ".txt") {
                filesystem::rename(file.path(), textPath + filename);
            }
            else if (extension == ".exe") {
                filesystem::rename(file.path(), programsPath + filename);
            }
            else if (extension == ".pdf" || extension == ".crdownload" || extension == ".ppt" || extension == ".doc") {
                filesystem::rename(file.path(), docsPath + filename);
            }
            else if (!extension.empty()) {
                filesystem::rename(file.path(), otherPath + filename);
            }
    }
}

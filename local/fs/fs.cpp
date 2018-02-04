#include "libaio.h"
#include <string>
#include <dirent.h>
#include "fs.h"
#include "../../utils/factory.h"

struct fileInfo {
    int fp;
    int len;
};

struct globInfo {
    char *path;
    int fsNo; //文件编号
    int id;
};


Pos storFs::Write(unsigned char * buf, int len) {
    Pos pos;

    return pos;
}

int storFs::Read(Pos &pos, unsigned char * buf) {
}

bool storFs::Init(char * path) {
    auto v = findAll(path);
    return false;
}

std::vector<std::string> storFs::findAll(char * path) {
    if( path[strlen(path) - 2] != '\\') {
        strcat(path, "\\");
    }

    struct dirent * dirp;
    DIR *dir;
    std::vector<std::string> files;

    dir = opendir(path);
    if( dir == NULL) {
        return files;
    }

    while((dirp = readdir(dir)) != NULL) {
        if( dirp->d_type & DT_DIR) continue;

        files.emplace_back(dirp->d_name);
    }

    return files;
}

REG_MODULE(storFs, "fs");


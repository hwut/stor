#pragma once
#include <vector>
#include <string>
#include "../storIntf.h"

/*
struct fileInfo {
    int fp;
    int len;
};

struct Pos {
    int id;
    int offset;
    int len;
};

struct globInfo {
    char *path;
    int fsNo; //文件编号
    int id;
};
*/

class storFs : public StorDrv{
public:
    virtual bool Init(char * path);

    virtual Pos Write(unsigned char * buf, int len);

    virtual int Read(Pos & p, unsigned char * buf);

    void Info();

protected:
    std::vector<std::string> findAll(char * path);

};

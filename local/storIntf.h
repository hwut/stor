#pragma once

struct Pos {
    int id;
    int offset;
    int len;
};

class StorDrv {
public:
    virtual bool Init(char * path) = 0;

    virtual Pos Write(unsigned char * buf, int len) = 0;

    virtual int Read(Pos & pos, unsigned char * buf) = 0;
};


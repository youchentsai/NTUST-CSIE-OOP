#pragma once
#include "Document.h"

class File : public Document {
private:
    std::string pathname;

public:
    File(std::string text, std::string pathName);
    File(File&);

    // set
    void setPathname(const std::string&);

    // get
    std::string getPathname() const;

    File& operator=(const File&);
};
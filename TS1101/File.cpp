#include "File.h"

File::File(std::string text, std::string _pathName) {
    this->setText(text);
    pathname = _pathName;
}
File::File(File& lhs) {
    this->setText(lhs.getText());
    pathname = lhs.pathname;
}

// set
void File::setPathname(const std::string& lhs) {
    pathname = lhs;
}

// get
std::string File::getPathname() const {
    return pathname;
}

File& File::operator=(const File& lhs) {
    this->setText(lhs.getText());
    pathname = lhs.pathname;
    return *this;
}
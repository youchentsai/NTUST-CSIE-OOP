#pragma once
#ifndef DOCUMENT_H
#    define DOCUMENT_H
#    include <string>

class Document {
private:
    std::string text;

public:
    std::string getText() const;
    void setText(const std::string& string);
    Document() {
        text = "";
    };
    Document(Document&);
    // copy constructor
    Document(const std::string lhs)
        : text(lhs){};

    Document& operator=(const Document& lfs);
};

#endif // !DOCUMENT_H

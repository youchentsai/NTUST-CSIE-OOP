#include "Document.h"
#include <string>

Document::Document(Document& lhs) {
    text = lhs.getText();
}

std::string Document::getText() const {
    return text;
}

Document& Document::operator=(const Document& lhs) {
    text = lhs.getText();
    return *this;
}

void Document::setText(const std::string& source) {
    text = source;
}
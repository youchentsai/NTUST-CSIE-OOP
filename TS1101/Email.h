#pragma once
#include "Document.h"

class Email : public Document {
private:
    std::string sender;
    std::string recipient;
    std::string title;

public:
    Email(std::string text, std::string sender, std::string recipient, std::string title);
    Email(Email& lhs);

    // set
    void setSender(const std::string& lhs);
    void setRecipient(const std::string& lhs);
    void setTitle(const std::string& lhs);

    // get
    std::string getSender() const;
    std::string getRecipient() const;
    std::string getTitle() const;

    Email& operator=(const Email& lfs);
};
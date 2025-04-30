#include "Email.h"

Email::Email(std::string text, std::string _sender, std::string _recipient, std::string _title)
    : Document() {
    this->setText(text);
    sender = _sender;
    recipient = _recipient;
    title = _title;
}

Email::Email(Email& lhs)
    : Document() {
    this->setText(lhs.getText());
    sender = lhs.sender;
    recipient = lhs.recipient;
    title = lhs.title;
}

// set
void Email::setSender(const std::string& lhs) {
    sender = lhs;
}
void Email::setRecipient(const std::string& lhs) {
    recipient = lhs;
}
void Email::setTitle(const std::string& lhs) {
    title = lhs;
}

// get
std::string Email::getSender() const {
    return sender;
}
std::string Email::getRecipient() const {
    return recipient;
}
std::string Email::getTitle() const {
    return title;
}

Email& Email::operator=(const Email& lhs) {
    this->setText(lhs.getText());
    sender = lhs.sender;
    recipient = lhs.recipient;
    title = lhs.title;
    return *this;
}
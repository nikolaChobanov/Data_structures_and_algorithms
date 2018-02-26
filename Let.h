#ifndef LETTER_H
#define LETTER_H

#include <iostream>

const int LETTER_INI = 50;

class Letter
{
    char* receiver;
    char* content;

    void copy_letter(Letter const&);

public:

    Letter();

    Letter(char const*, char const*);

    Letter(Letter const&);

    ~Letter();

    Letter& operator=(Letter const&);

    char const* get_receiver() const { return receiver; }

    char const* get_content() const { return content; }

    void set_receiver(char const*);

    void set_content(char const*);

    friend std::ostream& operator<<(std::ostream& os, Letter const& out)
    {
        os << out.get_receiver()<< "\n";
        os << out.get_content()<< "\n";

        return os;
    }

    friend std::istream& operator>>(std::istream& is, Letter& in)
    {
        char receiver[50];
        char content[2000];
        is.getline(receiver, 50);
        is.getline(content, 2000);
        in.set_receiver(receiver);
        in.set_content(content);

        return is;
    }
};

#endif // LETTER_H

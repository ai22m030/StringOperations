//
// Created by Adnan Vatric User on 17.09.22.
//

#ifndef STRINGOPERATIONS_STRING_H
#define STRINGOPERATIONS_STRING_H


class String {
public:
    String();
    String(const String& string)
            : string_(string.string_)
            , length_(string.length_) {};
    String(String&& string) noexcept
            : string_(string.string_)
            , length_(string.length_)
    {
        delete [] string.string_;
        string.length_ = 0;
    };
    explicit String(const char * string);
    virtual ~String() { delete [] string_; };
    void print() const;
    String& operator=(const String& string);
    String& operator=(const char &string);
    String& operator=(String&& string) noexcept;
    String& operator+=(const String& string);
    explicit operator char * () { return string_; };
    int length() const { return length_; };
    char * c_str() const { return string_; };
    void append(const String& string);
    void append(const char * string);

protected:

private:
    char * string_;
    int length_ = 0;
};


#endif //STRINGOPERATIONS_STRING_H

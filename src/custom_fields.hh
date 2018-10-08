#ifndef CUSTOM_FIELDS_HH
#define CUSTOM_FIELDS_HH

#include <string>

using std::string;

class CustomFieldDatum {
public:
    virtual string toJson() = 0;
};

class StringCustomFieldDatum: public CustomFieldDatum {
public:
    StringCustomFieldDatum(string content): content(content) { }

    string toJson();

private:
    string content;
};

class ListCustomFieldDatum: public CustomFieldDatum {
public:
    ListCustomFieldDatum(string content): content(content) { }

    string toJson();

private:
    string content;
};

#endif /* CUSTOM_FIELDS_HH */

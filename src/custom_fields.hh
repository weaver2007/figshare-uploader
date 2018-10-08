#ifndef CUSTOM_FIELDS_HH
#define CUSTOM_FIELDS_HH

#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::unique_ptr;

class CustomFieldDatum {
public:
    virtual string toJson() = 0;
    virtual string getKey() = 0;
};

class StringCustomFieldDatum: public CustomFieldDatum {
public:
    StringCustomFieldDatum(string content): content(content) { }

    string toJson();
    string getKey();

private:
    string content;
};

class ListCustomFieldDatum: public CustomFieldDatum {
public:
    ListCustomFieldDatum(string content): content(content) { }

    string toJson();
    string getKey();

private:
    string content;
};

typedef vector<unique_ptr<CustomFieldDatum>> CustomFields;

#endif /* CUSTOM_FIELDS_HH */

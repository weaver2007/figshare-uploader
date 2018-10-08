#ifndef CUSTOM_FIELDS_HH
#define CUSTOM_FIELDS_HH

#include <string>
#include <vector>
#include <memory>
#include <QJsonObject>
#include "column_mapping.hh"

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

// A custom field set that manages its own content
class CustomFieldSet {
public:
    CustomFieldSet() { }

    void add(unique_ptr<CustomFieldDatum> datum);

    QJsonObject render() const;
private:
    vector<unique_ptr<CustomFieldDatum>> content;
};

#endif /* CUSTOM_FIELDS_HH */

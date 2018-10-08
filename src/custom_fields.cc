#include "custom_fields.hh"

string StringCustomFieldDatum::toJson() {
    return "STRING VERSION";
}

string StringCustomFieldDatum::getKey() {
    return "some key";
}

string ListCustomFieldDatum::toJson() {
    return "[LIST VERSION]";
}


string ListCustomFieldDatum::getKey() {
    return "some key for a list datum";
}

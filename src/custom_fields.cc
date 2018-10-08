#include "custom_fields.hh"

string StringCustomFieldDatum::toJson() {
    return "STRING VERSION";
}

string ListCustomFieldDatum::toJson() {
    return "[LIST VERSION]";
}

#include <memory>
#include "custom_fields.hh"

using std::move;

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


QJsonObject CustomFieldSet::render() const {
    QJsonObject result;

    for (auto const& d: content) {
        auto jsonKey = QString::fromStdString(d->getKey());
        auto jsonValue = QString::fromStdString(d->toJson());

        result.insert(jsonKey, jsonValue);
    }

    return result;
}


void CustomFieldSet::add(unique_ptr<CustomFieldDatum> datum) {
    content.push_back(move(datum));
}

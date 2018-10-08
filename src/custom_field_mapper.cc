#include <iostream>
#include <memory>
#include "custom_field_mapper.hh"
#include "column_mapping.hh"
#include "utility.hh"
#include "custom_fields.hh"

using std::make_unique;
using std::unique_ptr;
using column_mapping::CustomFieldSpecification;
using column_mapping::FieldEncoder;;

CustomFieldSet CustomFieldMapper::mapCustomFields(const vector<string> excelRow) {
    for (auto col: excelRow) {
        std::cout << col << std::endl;
    }

    CustomFieldSet result;

    // This now becomes a vec->vec transformation with a conditional on 
    // the field encoder enum.
    for (CustomFieldSpecification spec: column_mapping::CUSTOM_FIELDS) {
        string excelRowContent = excelRow.at(spec.position);
        
        if (excelRowContent.empty() || isWhitespaceOnly(excelRowContent))
            continue;

        unique_ptr<CustomFieldDatum> datum;

        if (spec.type == FieldEncoder::STRING) {
            datum = make_unique<StringCustomFieldDatum>(excelRowContent);
        } else if (spec.type == FieldEncoder::LIST) {
            datum = make_unique<ListCustomFieldDatum>(excelRowContent);
        } else {
            throw std::runtime_error("unknown field encoder type");
        }

        result.add(datum);
    }


    return result;
}

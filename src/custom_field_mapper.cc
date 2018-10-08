#include <iostream>
#include "custom_field_mapper.hh"
#include "column_mapping.hh"
#include "utility.hh"
#include "custom_fields.hh"

vector<CustomFieldDatum> CustomFieldMapper::mapCustomFields(const vector<string> excelRow) {
    for (auto col: excelRow) {
        std::cout << col << std::endl;
    }

    vector<CustomFieldDatum> result;


    // This now becomes a vec->vec transformation with a conditional on 
    // the field encoder enum.
    for (CustomFieldSpecification s: column_mapping::CUSTOM_FIELDS) {
        string apiCustomFieldName = iter->first;
        int rowIndex = iter->second;

        string excelRowContent = excelRow.at(rowIndex);
        
        if (excelRowContent.empty() || isWhitespaceOnly(excelRowContent))
            continue;

        result.insert({apiCustomFieldName, excelRowContent});
    }

    return result;
}

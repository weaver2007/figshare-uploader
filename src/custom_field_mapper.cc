#include <iostream>
#include "custom_field_mapper.hh"
#include "column_mapping.hh"
#include "utility.hh"
#include "custom_fields.hh"

using column_mapping::CustomFieldSpecification;

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

        // Now need to make_unique and move it to the vector
//        result.add();
    }

    return result;
}

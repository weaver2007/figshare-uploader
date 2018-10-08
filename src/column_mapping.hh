#ifndef COLUMN_MAPPING_HH
#define COLUMN_MAPPING_HH

// New column indexes for the XLSX schema should be put in this namespace

// These are zero-based indexes, because they are used to reference into raw
// vector<string> (rather than being passed to the excel reader API)

// NB: If you modify these, you also need to modify the minimum and maximum
// columns in xlsx_reader.cc


#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

namespace column_mapping {
    const int CREATOR = 9;
    const int CONTRIBUTORS = 10;
    const int DATE = 11;
    const int TYPE = 12;
    const int SOURCE = 13;
    const int LANGUAGE = 14;
    const int RELATION = 15;
    const int TEMPORAL = 16;
    const int SPATIAL = 17;
    const int SPATIAL_RELATION = 18;
    const int IDENTIFIER = 19;
    const int RIGHTS = 20;
    const int REFERENCES = 6;
    const int GROUP_NAME = 21;
    const int PROJECT = 22;
    const int COLLECTION = 23;

    // Update this if you add fields.  It should be n+1 where n is the highest
    // int above.
    const int MAX_FIELD = 24;
    const string MINIMUM_COLUMN = "A";
    const string MAXIMUM_COLUMN = "X";

    enum class FieldEncoder { STRING, LIST };

    struct CustomFieldSpecification {
        CustomFieldSpecification(
            string name, int position, FieldEncoder type
        ) : name(name), position(position), type(type) { 
        }

        string name;
        int position;
        FieldEncoder type;
    };

    const vector<CustomFieldSpecification> CUSTOM_FIELDS_2 = {
        { "Creator", CREATOR, FieldEncoder::LIST }
    };

    const map<string, int> CUSTOM_FIELDS = {
        {"Creator", CREATOR},
        {"Contributors", CONTRIBUTORS},
        {"Date", DATE},
        {"Type", TYPE},
        {"Source", SOURCE},
        {"Language", LANGUAGE},
        {"Relation", RELATION},
        {"Temporal", TEMPORAL},
        {"Spatial", SPATIAL},
        {"Spatial Relation", SPATIAL_RELATION},
        {"Identifier", IDENTIFIER},
        {"Rights", RIGHTS},
        {"Project", PROJECT},
        {"Collection", COLLECTION}
    };
};


#endif /* COLUMN_MAPPING_HH */

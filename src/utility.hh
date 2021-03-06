#include <string>
#include <vector>

using std::string;
using std::vector;

string resolvePath(string base, string path);

string fetchString(
    const string input, const string key
);

vector<string> splitByRegexp(const string input, const string regexp);
vector<string> splitCommas(const string input);
vector<string> splitSpaces(const string input);
vector<string> splitSemicolons(const string input);

bool containsKey(const string input, const string key);
string basename(string path);

bool isWhitespaceOnly(string input);

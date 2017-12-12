#include <iostream>
#include <vector>
#include <cstdlib>
#include <QDebug>
#include <QApplication>
#include "xlsx.hh"
#include "article_mapper.hh"
#include "http_poster.hh"
#include "figshare_gateway.hh"
#include "requests.hh"
#include "http_getter.hh"
#include "category_mapper.hh"

using std::string;
using std::vector;
using std::cout;

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    qDebug() << "starting";

    char* token_ = getenv("TOKEN");
    
    if (token_ == NULL) {
        throw std::runtime_error("token must exist in environment");
    }

    std::string token(token_);

    string inputPath("resources/test.xlsx");


    HttpGetter* getter = new QtHttpGetter;
    string result = getter->request("https://api.figshare.com/v2/categories");
    CategoryMapper categoryMapper(result);
    XlsxReader theReader(inputPath);
    ArticleTypeMapper typeMapper;
    ArticleMapper mapper(typeMapper, categoryMapper);
    HttpPoster* poster = new QtHttpPoster(token);
    FigshareGateway* gateway = new HttpFigshareGateway(
        poster, categoryMapper
    );


    for (int i = 2; i <= 6; i++) {
        vector<string> row = theReader.rowToString(i);
        ArticleCreationRequest request = mapper.mapFromExcel(row);
        
        string uploadJson = mapper.mapToFigshare(request);

        std::cout << uploadJson << std::endl;

        auto response = gateway->createArticle(request);

        std::cout << response.location << std::endl;

        string relationField = row.at(15);
        
        std::cout << relationField << std::endl;
        return 0;
    }

    return 0;
}


#include <iostream>
#include <QApplication>
#include <QThread>
#include "driver.hh"
#include "figshare_gateway.hh"
#include "part_preparer.hh"
#include "file_spec_generator.hh"
#include "article_mapper.hh"
#include "view.hh"
#include "presenter.hh"
#include "logging.hh"
#include "token_store.hh"
#include "group_mapper.hh"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    // Token store is spooky action at a distance that's used to thread the
    // token through the various dependencies.
    TokenStore tokenStore;

    QtHttpGetter httpGetter(&tokenStore);
    QtHttpPoster httpPoster(&tokenStore);
    QtHttpPutter httpPutter(&tokenStore);
    QtSizeGetter sizeGetter;

    // debugf("loading categories");
    // string result = httpGetter.request("https://api.figshare.com/v2/categories");
    // CategoryMapper categoryMapper(result);
    // debugf("loaded categories");

    CategoryMapper categoryMapper(&httpGetter);

    ArticleTypeMapper typeMapper;
    GroupMapperImpl groupMapper(&httpGetter);
    HttpFigshareGateway gateway(&httpGetter, &httpPoster, &httpPutter, categoryMapper, &groupMapper);

    PartPreparerImpl partPreparer;
    FileSpecGeneratorImpl fileSpecGenerator(&sizeGetter);
    CustomFieldMapper customFieldMapper;
    ArticleMapperImpl articleMapper(typeMapper, categoryMapper, customFieldMapper, &groupMapper);

    Driver driver(&gateway, &partPreparer, &fileSpecGenerator, &articleMapper);

    Presenter* presenter = new PresenterImpl(&driver, &tokenStore);
    ViewImpl* view = new ViewImpl(presenter);

    // To break the cyclic dependency we have to setView on the presenter after
    // it's been constructed.
    presenter->setView(view);
    presenter->initializeView();

    view->show();

    return app.exec();
}

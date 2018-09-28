#ifndef LOGGING_HH
#define LOGGING_HH

#include <memory>
#include <spdlog/spdlog.h>
#include <QtGlobal>
#include <QMessageLogger>

#define debugf(...) QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug(__VA_ARGS__)
void log_init();

using std::shared_ptr;

namespace logging {
    extern shared_ptr<spdlog::logger> log;
};

#endif // LOGGING_HH

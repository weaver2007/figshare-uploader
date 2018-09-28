#include <string>
#include <spdlog/spdlog.h>
#include <QMessageLogger>
#include <QString>

void log_init() {
    QString pattern("%{type} - %{message}");
    qSetMessagePattern(pattern);
}

namespace logging {
    auto log = spdlog::stdout_logger_mt("console", true);
}

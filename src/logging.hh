#ifndef LOGGING_HH
#define LOGGING_HH

#include <QtGlobal>
#include <QMessageLogger>

#define debugf(...) QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug(__VA_ARGS__)
void log_init();

#endif // LOGGING_HH

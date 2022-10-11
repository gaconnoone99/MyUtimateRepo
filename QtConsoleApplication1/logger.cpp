#include "logger.h"

const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);
QString logger::filename = QDir::currentPath() + QDir::separator() + "log.txt";
bool logger::logging = false;

logger::logger(QObject *parent)
	: QObject(parent)
{}

logger::~logger()
{}

void logger::attach()
{
    logger::logging = true;
    qInstallMessageHandler(logger::handler);
}

void logger::handler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    if (logger::logging) {
        QByteArray localMsg = msg.toLocal8Bit();
        const char* file = context.file ? context.file : "";
        const char* function = context.function ? context.function : "";
        switch (type) {
        case QtDebugMsg:
            fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
            break;
        case QtInfoMsg:
            fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
            break;
        case QtWarningMsg:
            fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
            break;
        case QtCriticalMsg:
            fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
            break;
        case QtFatalMsg:
            fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
            break;
        }

        QFile Logfile(logger::filename);
        if (Logfile.open(QIODevice::Append)) {
            QTextStream ts(&Logfile);
            ts << QDateTime::currentDateTime().toString() << " - " << msg << " file: " << context.file << " line: " << context.line << "\r\n";
            ts.flush();
            Logfile.close();
        }
    }

    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);
}

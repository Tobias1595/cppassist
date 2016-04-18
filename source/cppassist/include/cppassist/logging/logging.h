#pragma once

#include <cppassist/cppassist_api.h>

#include <cppassist/logging/LogMessage.h>
#include <cppassist/logging/LogMessageBuilder.h>

namespace loggingzeug
{

class AbstractLogHandler;
class LogMessageBuilder;

/**
  * Creates a stream like object (LogMessageBuilder) to create a LogMessage from the objects
  * passed to it and sends the LogMessage to the global LogMessageHandler when the builder goes out of scope.
  * Similar to `qDebug()` from Qt.
  *
  * \code{.cpp}
  * info() << "Message: " << 3.14;
  * \endcode
  */
CPPASSIST_API LogMessageBuilder info(const std::string & context = "", LogMessage::Level level = LogMessage::Info);
CPPASSIST_API LogMessageBuilder debug(const std::string & context = "");
CPPASSIST_API LogMessageBuilder warning(const std::string & context = "");
CPPASSIST_API LogMessageBuilder critical(const std::string & context = "");
CPPASSIST_API LogMessageBuilder fatal(const std::string & context = "");

CPPASSIST_API void setLoggingHandler(AbstractLogHandler * handler);
CPPASSIST_API AbstractLogHandler * loggingHandler();

CPPASSIST_API void setVerbosityLevel(LogMessage::Level verbosity);
CPPASSIST_API LogMessage::Level verbosityLevel();

/**
 * Uses formatString to write on the usual logging streams.
 *
 *  Sample usage:
 *  \code{.cpp}
 *      fInfo("This is a test: %; pi = %+0E10.5;", 42, 3.141592653589793); // output: "This is a test: 42 pi = +3.14159E+00"
 *      fInfo("%; - %X; - %rf?_10.2;", "a string", 255, 2.71828182846); // output: "a string - 255 - ______2.72"
 *  \endcode
 *
 *   \see formatString
 */
template <typename... Arguments>
void fInfo(const char* format, Arguments... arguments);

/**
 *  \see fInfo
 */
template <typename... Arguments>
void fDebug(const char* format, Arguments... arguments);

/**
 *  \see fInfo
 */
template <typename... Arguments>
void fWarning(const char* format, Arguments... arguments);

/**
 *  \see fInfo
 */
template <typename... Arguments>
void fCritical(const char* format, Arguments... arguments);

/**
 *  \see fInfo
 */
template <typename... Arguments>
void fFatal(const char* format, Arguments... arguments);

} // namespace loggingzeug

#include <cppassist/logging/logging.hpp>
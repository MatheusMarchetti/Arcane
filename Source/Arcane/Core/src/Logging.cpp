#include "Core/Logging.h"

#include <filesystem>
#include <iostream>

void Arcane::ConsoleLogSink::Log(int line, const char* file, const char* format, ...)
{
	std::filesystem::path path = file;

	char finalBuffer[1024 + 100];
	snprintf(finalBuffer, 100, "%s : %d | ", path.filename().string().c_str(), line);

	char buffer[1024];
	
	// Not exactly sure about this !
	va_list args;
	__va_start(&args, format);
	vsnprintf(buffer, 1024, format, args);
	args = (va_list)0;

	strncat_s(finalBuffer, buffer, 1024);

	printf("%s\n", finalBuffer);
}

Arcane::FileLogSink::FileLogSink()
{
	std::string buffer(128, '\0');
	auto timeTApp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	tm appLT;
	localtime_s(&appLT, &timeTApp);

	strftime(&buffer[0], buffer.size(), " %Y-%m-%d@%H-%M LOG.txt", &appLT);

	std::filesystem::path filePath = std::filesystem::current_path() / "Logs";
	std::filesystem::create_directories(filePath);
	filePath /= buffer;

	m_Stream = std::ofstream(filePath.string().c_str(), std::ifstream::binary | std::ifstream::out);
}

Arcane::FileLogSink::~FileLogSink()
{
	m_Stream.close();
}

void Arcane::FileLogSink::Log(int line, const char* file, const char* format, ...)
{
	std::filesystem::path path = file;

	char finalBuffer[1024 + 100];
	snprintf(finalBuffer, 100, "%s : %d | ", path.filename().string().c_str(), line);

	char buffer[1024];
	
	// Not exactly sure about this !
	va_list args;
	__va_start(&args, format);
	vsnprintf(buffer, 1024, format, args);
	args = (va_list)0;

	strncat_s(finalBuffer, buffer, 1024);

	m_Stream << finalBuffer;
	m_Stream << std::endl;
}

Arcane::Logger* Arcane::Logger::Instance()
{
	static Logger s_Instance;
	return &s_Instance;
}

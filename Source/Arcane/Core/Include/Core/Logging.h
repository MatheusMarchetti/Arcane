#pragma once
#include "Core/base.h"

#include <fstream>

#ifdef ARC_CORE_SHARED
#define ARC_CORE_API ARC_EXPORT
#else
#define ARC_CORE_API ARC_IMPORT
#endif // ARC_CORE_SHARED

namespace Arcane
{
	class ARC_CORE_API LogSink
	{
	public:
		virtual void Log(int line, const char* file, const char* format, ...) = 0;
		virtual ~LogSink() = default;
	};

	class ARC_CORE_API ConsoleLogSink : public LogSink
	{
	public:
		ConsoleLogSink() = default;
		~ConsoleLogSink() override = default;

		void Log(int line, const char* file, const char* format, ...) override;
	};

	class ARC_CORE_API FileLogSink : public LogSink
	{
	public:
		FileLogSink();
		~FileLogSink() override;

		void Log(int line, const char* file, const char* format, ...) override;
	private:
		std::ofstream m_Stream;
	};

	class ARC_CORE_API Logger
	{
	public:
		static Logger* Instance();
		
		template<typename T>
		void AttachLogSink()
		{
			m_LogSinks.emplace_back(utl::make_shared<T>());
		}

		template<typename... Args>
		void Log(int line, const char* file, const char* format, Args... args)
		{
			for (auto& LogSink : m_LogSinks)
				LogSink->Log(line, file, format, args...);
		}
	private:
		std::vector< utl::shared_ptr<LogSink> > m_LogSinks;
	};
}

#define ARC_LOG(log,...) ::Arcane::Logger::Instance()->Log(__LINE__,__FILE__,log,##__VA_ARGS__)
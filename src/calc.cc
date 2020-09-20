#include "calc.h"
#include <spdlog/spdlog.h>
#include "spdlog/sinks/rotating_file_sink.h"
#include <iostream>

/**
*	@brief:
*/
int calc::add(int a /*= 0*/, int b /*= 2*/)
{
	std::cout << "I love c++\n";
	

	std::shared_ptr<spdlog::logger> _plog = nullptr;
	//_plog = std::shared_ptr<spdlog::logger>(new spdlog::logger);
	auto max_size = 1048576 * 5;
	auto max_files = 3;
	_plog = spdlog::rotating_logger_mt("lib_sp_log", "log/lib_sp_log.log", max_size, max_files);
	if (_plog)
		_plog->info("ABCD={}", "1234");

	spdlog::shutdown();

	return a + b;
}


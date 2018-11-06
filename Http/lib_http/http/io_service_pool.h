//
// Created by ning on 2018/11/1.
//

#ifndef INTERVIEW_CPP_IO_SERVICE_POOL_H
#define INTERVIEW_CPP_IO_SERVICE_POOL_H

#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>
#include <vector>
#include <memory>

namespace http {

	// multi threads io service
	class io_service_pool : private boost::noncopyable {
	public:
		explicit io_service_pool(std::size_t pool_size);

		void run();

		void stop();

		boost::asio::io_service &get_io_service();

	private:
		using io_service_ptr = std::shared_ptr<boost::asio::io_service>;
		using work_ptr = std::shared_ptr<boost::asio::io_service::work>;

		std::vector<io_service_ptr> io_services_;   // service ptr vector
		std::vector<work_ptr> work_;    // work ptr vector
		std::size_t next_to_service_;
	};
}
#endif //INTERVIEW_CPP_IO_SERVICE_POOL_H

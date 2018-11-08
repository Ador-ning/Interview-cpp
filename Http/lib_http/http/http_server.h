//
// Created by ning on 2018/11/1.
//

#ifndef INTERVIEW_CPP_HTTP_SERVER_H
#define INTERVIEW_CPP_HTTP_SERVER_H

#include "./io_service_pool.h"
#include "../http/connection.cpp"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/noncopyable.hpp>

#include <vector>
#include <string>

namespace http {
	class http_server : private boost::noncopyable {
	public:
		explicit http_server(std::size_t io_service_poil_size);

		enum ssl_method_t {
			sslv2 = boost::asio::ssl::context::sslv2_server,
			sslv3 = boost::asio::ssl::context::sslv3_server,
			tlsv1 = boost::asio::ssl::context::tlsv1_server,
			tlsv11 = boost::asio::ssl::context::tlsv11_server,
			tlsv12 = boost::asio::ssl::context::tlsv12_server,
			sslv23 = boost::asio::ssl::context::sslv23_server,
		};

		struct ssl_config_t {
			ssl_method_t ssl_method;
			std::string private_ky;
			std::string certificate_chain;
			bool is_file;
		};

		http_server &listen(const std::string &address, const std::string &port);

		http_server &listen(const std::string &address, const std::string &port,
		                    const ssl_config_t &ssl_cfg);

		http_server &listen(const std::string &address, const std::string &port,
		                    ssl_method_t ssl_method, const std::string &private_key,
		                    const std::string &certificate_chain, bool is_file = true);

		void run();

		void stop();

		void request_handler(request_handler_t handler) {
			request_handler_ = std::move(handler);
		}

		void set_max_req_size(std::size_t size) {
			max_req_size_ = size;
		}

		void set_keep_alive_timeout(long seconds) {
			keep_alive_timeout_ = seconds;
		}

	private:
		void start_accept(std::shared_ptr<boost::asio::ip::tcp::socket> const &acceptor);

		void start_accept(std::shared_ptr<boost::asio::ip::tcp::socket> const &acceptor,
		                  std::shared_ptr<boost::asio::ssl::context_base> const &ssl_ctx);

		void do_listen(std::shared_ptr<boost::asio::ip::tcp::socket> const &acceptor,
		               const std::string &address, const std::string &port);

		io_service_pool io_service_pool_;
		request_handler_t request_handler_;
		std::size_t max_req_size_ = 3 * 1024 * 1024;
		long keep_alive_timeout_ = 60;
	};
}
#endif //INTERVIEW_CPP_HTTP_SERVER_H

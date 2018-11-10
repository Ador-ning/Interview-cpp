//
// Created by ning on 2018/11/1.
//

#ifndef INTERVIEW_CPP_HTTP_H
#define INTERVIEW_CPP_HTTP_H

#include "./aop.cpp"
#include "./http_router.h"
#include "../../lib_http/http/http_server.h"
#include "../../lib_http/http/utils.h"

#include <boost/thread.hpp>

namespace http {
	class http {
	public:
		void listen(const std::string &address, const std::string &port) {
			listen_infos_.emplace_back(listen_info_t{address, port});
		}

		void listen(const std::string &address, const std::string &port, const http_server::ssl_config_t &ssl_cfg) {
			ssl_listen_infos_.emplace_back(ssl_listen_info_t{listen_info_t{address, port}, ssl_cfg});
		}

		void listen(const std::string &address, const std::string &port, http_server::ssl_method_t ssl_method,
		            const std::string &private_key, const std::string &certificate_chain, bool is_file = true) {
			ssl_listen_infos_.emplace_back(ssl_listen_info_t
					                               {
							                               listen_info_t{address, port},
							                               http_server::ssl_config_t{ssl_method, private_key,
							                                                         certificate_chain, is_file}
					                               });
		}


		void run() {
			http_server server(io_service_pool_size_);
			server.request_handler([this](request const &req, response &res) {
				bool result = http_router_.route(req.get_method(), req.get_url(), req, res);
				if (!result)
					res = reply_static_file(static_path_, req);
			});

			for (auto const &info :listen_infos_)
				server.listen(info.address, info.port);

			for (auto const &info:ssl_listen_infos_
				server.listen(info.info.address, info.info.port, info.config);

			server.set_max_req_size(max_req_size_);
			server.set_keep_alive_timeout(keep_alive_timeout_);
			server.run();
		}

		template<httpmethod... Is, typename Function, typename... AP>
		void register_handler(std::string_view name, Function &&f, AP &&... ap) {
			using result_type = typename timax::function_traits<Function>::result_type;
			static_assert(!iguana::is_reflection_v<result_type> && !std::is_class_v<result_type>);
			http_router_.register_handler<Is...>(name, std::forward<Function>(f), std::forward<AP>(ap)...);
		}

		template<httpmethod... Is, class T, class Type, typename T1, typename... AP>
		void register_handler(std::string_view name, Type T::* f, T1 &&t, AP &&... ap) {
			static_assert(!iguana::is_reflection_v<Type> && !std::is_class_v<Type>);
			http_router_.register_handler<Is...>(name, f, std::forward<T1>(t), std::forward<AP>(ap)...);
		}


		void set_static_path(std::string path) { static_path_ = path; }

		void set_max_req_size(std::size_t sz) { max_req_size_ = sz; }

		void set_keep_alive_timeout(long seconds) { keep_alive_timeout_ = seconds; }

		void set_thread_sum(std::size_t num) { io_service_pool_size_ = num; }

	private:
		struct listen_info_t {
			std::string address;
			std::string port;
		};
		struct ssl_listen_info_t {
			listen_info_t info;
			http_server::ssl_config_t config;
		};

		std::vector<listen_info_t> listen_infos_;
		std::vector<ssl_listen_info_t> ssl_listen_infos_;

		http_router http_router_;
		std::string static_path_;
		std::size_t max_req_size_ = 2 * 1024 * 1024;
		long keep_alive_timeout_ = 60;
		std::size_t io_service_pool_size_ = boost::thread::hardware_concurrency();
	};
}

#endif //INTERVIEW_CPP_HTTP_H

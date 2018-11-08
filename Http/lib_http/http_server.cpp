//
// Created by ning on 2018/11/1.
//

#include "./http/http_server.h"

#include <boost/bind.hpp>
#include <iostream>
#include <memory>

namespace http {
	http_server::http_server(std::size_t io_service_pool_size) : io_service_pool_(io_service_pool_size) {}

	http_server &http_server::listen(const std::string &address, const std::string &port) {
		auto acceptor = std::make_shared<boost::asio::ip::tcp::acceptor>(io_service_pool_.get_io_service());
		do_listen(acceptor, address, port);
		start_accept(acceptor);
	}

	http_server &http_server::listen(const std::string &address, const std::string &port,
	                                 const http::http_server::ssl_config_t &ssl_cfg) {
		auto ssl_ctx = std::make_shared<boost::asio::ssl::context>(
				static_cast<boost::asio::ssl::context::method>(ssl_cfg.ssl_method));

		if (ssl_cfg.is_file) {
			ssl_ctx->use_private_key_file(ssl_cfg.private_key, boost::asio::ssl::context::pem);
			ssl_ctx->use_certificate_chain_file(ssl_cfg.certificate_chain);
		} else {
			ssl_ctx->use_private_key(boost::asio::buffer(ssl_cfg.private_key), boost::asio::ssl::context::pem);
			ssl_ctx->use_certificate_chain(boost::asio::buffer(ssl_cfg.certificate_chain));
		}

		//HTTP2???
		//configure_tls_context_easy(ec, tls);
		auto acceptor = std::make_shared<boost::asio::ip::tcp::acceptor>(io_service_pool_.get_io_service());
		do_listen(acceptor, address, port);
		start_accept(acceptor, ssl_ctx);
		return *this;
	}

	http_server &http_server::listen(const std::string &address, const std::string &port,
	                                 http::http_server::ssl_method_t ssl_method, const std::string &private_key,
	                                 const std::string &certificate_chain, bool is_file) {
		return listen(address, port, ssl_config_t{ssl_method, private_key, certificate_chain, is_file});
	}

	void http_server::run() {
		io_service_pool_.run();
	}

	void http_server::start_accept(std::shared_ptr<boost::asio::ip::tcp::acceptor> const &acceptor) {
		auto new_conn = std::make_shared<connection<boost::asio::ip::tcp::socket>>(
				io_service_pool_.get_io_service(), request_handler_, max_req_size_, keep_alive_timeout_);
		acceptor->async_accept(new_conn->socket(), [this, new_conn, acceptor]
				(const boost::system::error_code &ec) {
			if (!ec) {
				new_conn->socket().set_option(boost::asio::ip::tcp::no_delay(true));
				new_conn->start();
			} else {
				std::cout << "server::handle_accept: " << ec.message() << std::endl;
			}
			start_accept(acceptor); // recursive
		});
	}

	void http_server::start_accept(std::shared_ptr<boost::asio::ip::tcp::acceptor> const &acceptor,
	                               std::shared_ptr<boost::asio::ssl::context_base> const &ssl_ctx) {
		auto new_conn = std::make_shared<connection<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>>>(
				io_service_pool_.get_io_service(), request_handler_, *ssl_ctx, max_req_size_, keep_alive_timeout_);
		acceptor->async_accept(new_conn->socket().lowest_layer(),
		                       [this, new_conn, acceptor, ssl_ctx](const boost::system::error_code &e) {
			                       if (!e) {
				                       new_conn->socket().lowest_layer().set_option(
						                       boost::asio::ip::tcp::no_delay(true));
				                       new_conn->reset_timer();
				                       new_conn->socket().async_handshake(boost::asio::ssl::stream_base::server,
				                                                          [new_conn](
						                                                          const boost::system::error_code &e) {
					                                                          if (e) {
						                                                          return;
					                                                          }
					                                                          //HTTP2???
// 					if (!tls_h2_negotiated(new_conn->socket()))
// 					{
// 						return;
// 					}
					                                                          new_conn->start();
				                                                          });
			                       } else {
				                       std::cout << "server::handle_accept: " << e.message() << std::endl;
			                       }

			                       start_accept(acceptor, ssl_ctx);
		                       });
	}


	void http_server::do_listen(std::shared_ptr<boost::asio::ip::tcp::acceptor> const &acceptor,
	                            const std::string &address, const std::string &port) {
		boost::asio::ip::tcp::resolver resolver(acceptor->get_io_service());
		boost::asio::ip::tcp::resolver::query query(address, port);
		boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(query);
		acceptor->open(endpoint.protocol());
		acceptor->set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
		acceptor->bind(endpoint);
		acceptor->listen();
	}

	void http_server::stop() {
		io_service_pool_.stop();
	}
}
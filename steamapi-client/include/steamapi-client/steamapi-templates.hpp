#ifndef STEAMAPI_CLIENT_STEAMAPI_TEMPLATES_HPP
#define STEAMAPI_CLIENT_STEAMAPI_TEMPLATES_HPP
#include <string>
#include <cstdint>
template<class API> class Response;
template<class API> class Request;
template<class API> std::string interface();
template<class API> std::string interface(std::uint32_t app_id);
template<class API> std::string method();
template<class API> std::string version();
#endif
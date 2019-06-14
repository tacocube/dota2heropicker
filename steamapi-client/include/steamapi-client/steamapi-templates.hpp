#ifndef STEAMAPI_CLIENT_STEAMAPI_TEMPLATES_HPP
#define STEAMAPI_CLIENT_STEAMAPI_TEMPLATES_HPP
#include <string>
template<class API> class Response;
template<class API> class Request;
template<class API> std::string interface();
template<class API> std::string method();
template<class API> std::string version();
#endif
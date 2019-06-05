#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include "cpp-httplib/httplib.h"

const std::string load_static(const std::string& path) {

    std::ifstream static_file(path.c_str(), std::ios::in);

    std::stringstream stream;

    stream << static_file.rdbuf();
    static_file.close();

    return stream.str();
}

int main() {

    httplib::Server svr;

    const std::string html = load_static("static/index.html");

    const std::string js = load_static("static/index.js");

    const std::array<std::string, 3> routes = {"/", "/about", "/contact"};

    for(auto&& r : routes)
        svr.Get(r.c_str(), [&](const httplib::Request& req, httplib::Response& res){
            res.set_content(html, "text/html");
        });

    svr.Get("/index.js", [&](const httplib::Request& req, httplib::Response& res){
        res.set_content(js, "text/javascript");
    });

    svr.listen("localhost", 3000);
}
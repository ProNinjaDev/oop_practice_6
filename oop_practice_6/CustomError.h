#include <exception>
#include <string>


class CustomError : std::exception {

	std::string message;

public:
	CustomError(std::string msg) {
		message = msg;
	}


	virtual const char* what() const override { return message.c_str(); }
	/*std::string What() const {
		return message;
	}*/
};


#include <string>

class Exception
{
public:
  Exception(std::string message);
  Exception(std::string message, int code);
  std::string What() const;
  int GetCode() const;
private:
  std::string m_message;
  int m_code;
};

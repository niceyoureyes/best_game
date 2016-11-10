#include "exception.h"

Exception::Exception(std::string message){
  m_message = message;
}

Exception::Exception(std::string message, int code){
  m_message = message; m_code = code;
}

std::string Exception::What() const{
  return m_message;
}

int Exception::GetCode() const{
  return m_code;
}

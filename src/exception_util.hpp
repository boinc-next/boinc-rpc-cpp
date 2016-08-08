// This file is part of boinc-rpc-cpp.

// https://github.com/skybon/boinc-rpc-cpp
// Copyright (C) 2016 Artem Vorotnikov
//
// boinc-rpc-cpp is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License
// as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// boinc-rpc-cpp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with boinc-rpc-cpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _EXCEPTION_UTIL_HPP_
#define _EXCEPTION_UTIL_HPP_

#include <string>

#ifndef DEFINE_EXCEPTION
#define DEFINE_EXCEPTION(ClassName, Message)                                              \
  class ClassName : public std::exception                                                 \
  {                                                                                       \
  private:                                                                                \
    std::string msg;                                                                      \
                                                                                          \
  public:                                                                                 \
    ClassName() { msg = std::string(Message); }                                           \
    ClassName(std::string arg) { msg = std::string(Message) + std::string(" : ") + arg; } \
    virtual const char* what() const throw() { return msg.data(); }                       \
  }
#endif

#endif

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

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include <vector>
#include <string>

#include <glibmm.h>

#include "models.hpp"

namespace Boinc
{
struct Client
{
  std::string addr;
  int port;
  std::string password;

  std::vector<Message> get_messages(int = 0);
  std::vector<ProjectInfo> get_projects();
  AccountManagerInfo get_account_manager_info();
  int get_account_manager_rpc_status();
  void account_manager_rpc(Glib::ustring, Glib::ustring, Glib::ustring);
  VersionInfo exchange_versions(VersionInfo);
  std::vector<Result> get_results(bool = false);
  void set_mode(Component, RunMode, double = 0);
  HostInfo get_host_info();
  void set_language(Glib::ustring);
};
}
#endif

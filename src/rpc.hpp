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

#ifndef _RPC_HPP_
#define _RPC_HPP_

#include <string>

#include <glibmm.h>

#include "util.hpp"

namespace Boinc
{
std::string compute_nonce_hash(std::string, std::string);
void query_boinc_daemon(Glib::ustring, int, Glib::ustring, XMLCallback, XMLCallback = nullptr);
}
#endif

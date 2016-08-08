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

#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <functional>
#include <map>
#include <memory>

#include <glibmm.h>
#include <libxml++/libxml++.h>

namespace Boinc
{
typedef std::function<void(xmlpp::Node*)> XMLCallback;
typedef std::map<Glib::ustring, XMLCallback> XMLCallbackMap;

void map_xml_node(xmlpp::Node*, XMLCallbackMap, std::function<void(Glib::ustring)> = nullptr);
void xml_clear_children(xmlpp::Node*);
Glib::ustring xml_node_to_string(xmlpp::Node* = nullptr);
std::shared_ptr<xmlpp::Document> load_xml(Glib::ustring);
}
#endif

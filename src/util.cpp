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

#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <map>

#include <glibmm.h>
#include <libxml++/libxml++.h>

#include "exception_list.hpp"

#include "util.hpp"

namespace Boinc
{

void
map_xml_node(xmlpp::Node* p, XMLCallbackMap b, std::function<void(Glib::ustring)> cb_unknown_key)
{
  for (auto v : p->get_children())
  {
    auto k = v->get_name();
    XMLCallback f;
    try
    {
      f = b.at(k);
    }
    catch (const std::out_of_range& e)
    {
      if (cb_unknown_key)
      {
        cb_unknown_key(k);
      }
      continue;
    }
    f(v);
  }
}

void
xml_clear_children(xmlpp::Node* n)
{
  auto children = n->get_children();
  std::for_each(std::begin(children), std::end(children), [n](xmlpp::Node* v) { n->remove_child(v); });
}

Glib::ustring
xml_node_to_string(xmlpp::Node* n)
{
  if (!n)
  {
    return "";
  }

  xmlpp::Document doc("1.0");
  doc.create_root_node_by_import(n);

  return doc.write_to_string();
}

std::shared_ptr<xmlpp::Document>
load_xml(Glib::ustring data)
{
  if (!data.validate())
  {
    throw DataParseError("invalid UTF-8");
  }
  xmlpp::DomParser dp;
  try
  {
    dp.parse_memory(data);
  }
  catch (const std::exception& e)
  {
    throw DataParseError(e.what());
  }
  auto dp_doc = dp.get_document();
  if (!dp_doc)
  {
    throw DataParseError("no document formed from data");
  }

  auto dp_root = dp_doc->get_root_node();
  if (!dp_root)
  {
    throw DataParseError("no root node in parsed data");
  }

  if (dp_root->get_name().empty())
  {
    throw DataParseError("root node name is empty");
  }

  auto doc = std::shared_ptr<xmlpp::Document>(new xmlpp::Document("1.0"));

  doc->create_root_node_by_import(dp_root);

  return doc;
}
}

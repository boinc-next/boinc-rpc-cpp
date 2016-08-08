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

#ifndef _EXCEPTION_LIST_HPP_
#define _EXCEPTION_LIST_HPP_

#include "exception_util.hpp"

namespace Boinc
{
DEFINE_EXCEPTION(ConnectError, "failed to connect");
DEFINE_EXCEPTION(DataParseError, "error parsing data");
DEFINE_EXCEPTION(InvalidPasswordError, "invalid password");
DEFINE_EXCEPTION(DaemonError, "daemon returned error");
DEFINE_EXCEPTION(NullError, "unexpected null detected");
DEFINE_EXCEPTION(NetworkError, "network error occurred");
DEFINE_EXCEPTION(AuthError, "auth error occurred");
DEFINE_EXCEPTION(InvalidURLError, "invalid URL");
DEFINE_EXCEPTION(AlreadyAttachedError, "already attached");
}
#endif

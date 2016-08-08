# boinc-rpc-cpp

C++ RPC API for BOINC client.

## Dependencies

- [CMake](https://cmake.org) (3.5+)
- [Boost](http://boost.org) (1.58+)
- [libxml++](https://developer.gnome.org/libxml++/stable/) (2.40+)

## Installation

```
$ mkdir build
$ cd build
$ cmake -DCMAKE_INSTALL_PREFIX=/usr ..
$ make
# make DESTDIR=/usr install
```

## Usage example

```
#include <boinc-rpc-cpp/boinc-rpc-cpp.hpp>

int main() {
    Boinc::Client c {.addr = "127.0.0.1", .port = 31416, .password = "my-pass-in-gui_rpc_auth.cfg"};
    for (auto msg : c.get_messages()) {
        std::cout << msg.body.value_or("") << std::endl;
    };

    return 0;
}
```

## License

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

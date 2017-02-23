/*
 * Licensed under the MIT License <https://opensource.org/licenses/MIT>.
 * Copyright (c) 2017 Matsuz <xiangsong.zeng@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <string>
#include <sstream>

#include "dns_fetch.h"
#include "http.h"

#define GOOGLE_DNS_BASEURL "https://dns.google.com/resolve"

using namespace std;

namespace dns
{

const string
fetch(const string &name, // the string of domain name
      const int &type,    // query type
      const string &ecs)  // edns client subnet
{
    ostringstream oss;
    oss << GOOGLE_DNS_BASEURL
        << "?name=" << name
        << "&type=" << type
        << "&edns_client_subnet=" << ecs;

    string content = http::get(oss.str());
    return content;
}
}
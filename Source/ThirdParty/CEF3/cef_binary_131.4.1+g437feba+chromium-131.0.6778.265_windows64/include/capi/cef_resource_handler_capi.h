// Copyright (c) 2025 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=4442fed4d8d56eae033533adee7c6798a16106b1$
//

#ifndef CEF_INCLUDE_CAPI_CEF_RESOURCE_HANDLER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_RESOURCE_HANDLER_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"
#include "include/capi/cef_browser_capi.h"
#include "include/capi/cef_callback_capi.h"
#include "include/capi/cef_cookie_capi.h"
#include "include/capi/cef_request_capi.h"
#include "include/capi/cef_response_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
/// Callback for asynchronous continuation of cef_resource_handler_t::skip().
///
typedef struct _cef_resource_skip_callback_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Callback for asynchronous continuation of skip(). If |bytes_skipped| > 0
  /// then either skip() will be called again until the requested number of
  /// bytes have been skipped or the request will proceed. If |bytes_skipped| <=
  /// 0 the request will fail with ERR_REQUEST_RANGE_NOT_SATISFIABLE.
  ///
  void(CEF_CALLBACK* cont)(struct _cef_resource_skip_callback_t* self,
                           int64_t bytes_skipped);
} cef_resource_skip_callback_t;

///
/// Callback for asynchronous continuation of cef_resource_handler_t::read().
///
typedef struct _cef_resource_read_callback_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Callback for asynchronous continuation of read(). If |bytes_read| == 0 the
  /// response will be considered complete. If |bytes_read| > 0 then read() will
  /// be called again until the request is complete (based on either the result
  /// or the expected content length). If |bytes_read| < 0 then the request will
  /// fail and the |bytes_read| value will be treated as the error code.
  ///
  void(CEF_CALLBACK* cont)(struct _cef_resource_read_callback_t* self,
                           int bytes_read);
} cef_resource_read_callback_t;

///
/// Structure used to implement a custom request handler structure. The
/// functions of this structure will be called on the IO thread unless otherwise
/// indicated.
///
typedef struct _cef_resource_handler_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Open the response stream. To handle the request immediately set
  /// |handle_request| to true (1) and return true (1). To decide at a later
  /// time set |handle_request| to false (0), return true (1), and execute
  /// |callback| to continue or cancel the request. To cancel the request
  /// immediately set |handle_request| to true (1) and return false (0). This
  /// function will be called in sequence but not from a dedicated thread. For
  /// backwards compatibility set |handle_request| to false (0) and return false
  /// (0) and the ProcessRequest function will be called.
  ///
  int(CEF_CALLBACK* open)(struct _cef_resource_handler_t* self,
                          struct _cef_request_t* request,
                          int* handle_request,
                          struct _cef_callback_t* callback);

  ///
  /// Begin processing the request. To handle the request return true (1) and
  /// call cef_callback_t::cont() once the response header information is
  /// available (cef_callback_t::cont() can also be called from inside this
  /// function if header information is available immediately). To cancel the
  /// request return false (0).
  ///
  /// WARNING: This function is deprecated. Use Open instead.
  ///
  int(CEF_CALLBACK* process_request)(struct _cef_resource_handler_t* self,
                                     struct _cef_request_t* request,
                                     struct _cef_callback_t* callback);

  ///
  /// Retrieve response header information. If the response length is not known
  /// set |response_length| to -1 and read_response() will be called until it
  /// returns false (0). If the response length is known set |response_length|
  /// to a positive value and read_response() will be called until it returns
  /// false (0) or the specified number of bytes have been read. Use the
  /// |response| object to set the mime type, http status code and other
  /// optional header values. To redirect the request to a new URL set
  /// |redirectUrl| to the new URL. |redirectUrl| can be either a relative or
  /// fully qualified URL. It is also possible to set |response| to a redirect
  /// http status code and pass the new URL via a Location header. Likewise with
  /// |redirectUrl| it is valid to set a relative or fully qualified URL as the
  /// Location header value. If an error occured while setting up the request
  /// you can call set_error() on |response| to indicate the error condition.
  ///
  void(CEF_CALLBACK* get_response_headers)(struct _cef_resource_handler_t* self,
                                           struct _cef_response_t* response,
                                           int64_t* response_length,
                                           cef_string_t* redirectUrl);

  ///
  /// Skip response data when requested by a Range header. Skip over and discard
  /// |bytes_to_skip| bytes of response data. If data is available immediately
  /// set |bytes_skipped| to the number of bytes skipped and return true (1). To
  /// read the data at a later time set |bytes_skipped| to 0, return true (1)
  /// and execute |callback| when the data is available. To indicate failure set
  /// |bytes_skipped| to < 0 (e.g. -2 for ERR_FAILED) and return false (0). This
  /// function will be called in sequence but not from a dedicated thread.
  ///
  int(CEF_CALLBACK* skip)(struct _cef_resource_handler_t* self,
                          int64_t bytes_to_skip,
                          int64_t* bytes_skipped,
                          struct _cef_resource_skip_callback_t* callback);

  ///
  /// Read response data. If data is available immediately copy up to
  /// |bytes_to_read| bytes into |data_out|, set |bytes_read| to the number of
  /// bytes copied, and return true (1). To read the data at a later time keep a
  /// pointer to |data_out|, set |bytes_read| to 0, return true (1) and execute
  /// |callback| when the data is available (|data_out| will remain valid until
  /// the callback is executed). To indicate response completion set
  /// |bytes_read| to 0 and return false (0). To indicate failure set
  /// |bytes_read| to < 0 (e.g. -2 for ERR_FAILED) and return false (0). This
  /// function will be called in sequence but not from a dedicated thread. For
  /// backwards compatibility set |bytes_read| to -1 and return false (0) and
  /// the ReadResponse function will be called.
  ///
  int(CEF_CALLBACK* read)(struct _cef_resource_handler_t* self,
                          void* data_out,
                          int bytes_to_read,
                          int* bytes_read,
                          struct _cef_resource_read_callback_t* callback);

  ///
  /// Read response data. If data is available immediately copy up to
  /// |bytes_to_read| bytes into |data_out|, set |bytes_read| to the number of
  /// bytes copied, and return true (1). To read the data at a later time set
  /// |bytes_read| to 0, return true (1) and call cef_callback_t::cont() when
  /// the data is available. To indicate response completion return false (0).
  ///
  /// WARNING: This function is deprecated. Use Skip and Read instead.
  ///
  int(CEF_CALLBACK* read_response)(struct _cef_resource_handler_t* self,
                                   void* data_out,
                                   int bytes_to_read,
                                   int* bytes_read,
                                   struct _cef_callback_t* callback);

  ///
  /// Request processing has been canceled.
  ///
  void(CEF_CALLBACK* cancel)(struct _cef_resource_handler_t* self);
} cef_resource_handler_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_RESOURCE_HANDLER_CAPI_H_

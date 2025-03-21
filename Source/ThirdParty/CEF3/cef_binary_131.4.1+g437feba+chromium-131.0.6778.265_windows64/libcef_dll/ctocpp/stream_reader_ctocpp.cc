// Copyright (c) 2025 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=b4c20f02d1879db97205c3cc06a666e09e0d477a$
//

#include "libcef_dll/ctocpp/stream_reader_ctocpp.h"

#include "libcef_dll/cpptoc/read_handler_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<CefStreamReader> CefStreamReader::CreateForFile(
    const CefString& fileName) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: fileName; type: string_byref_const
  DCHECK(!fileName.empty());
  if (fileName.empty()) {
    return nullptr;
  }

  // Execute
  cef_stream_reader_t* _retval =
      cef_stream_reader_create_for_file(fileName.GetStruct());

  // Return type: refptr_same
  return CefStreamReaderCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefStreamReader> CefStreamReader::CreateForData(void* data,
                                                          size_t size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: data; type: simple_byaddr
  DCHECK(data);
  if (!data) {
    return nullptr;
  }

  // Execute
  cef_stream_reader_t* _retval = cef_stream_reader_create_for_data(data, size);

  // Return type: refptr_same
  return CefStreamReaderCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefStreamReader> CefStreamReader::CreateForHandler(
    CefRefPtr<CefReadHandler> handler) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: handler; type: refptr_diff
  DCHECK(handler.get());
  if (!handler.get()) {
    return nullptr;
  }

  // Execute
  cef_stream_reader_t* _retval =
      cef_stream_reader_create_for_handler(CefReadHandlerCppToC::Wrap(handler));

  // Return type: refptr_same
  return CefStreamReaderCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
size_t CefStreamReaderCToCpp::Read(void* ptr, size_t size, size_t n) {
  shutdown_checker::AssertNotShutdown();

  cef_stream_reader_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, read)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: ptr; type: simple_byaddr
  DCHECK(ptr);
  if (!ptr) {
    return 0;
  }

  // Execute
  size_t _retval = _struct->read(_struct, ptr, size, n);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
int CefStreamReaderCToCpp::Seek(int64_t offset, int whence) {
  shutdown_checker::AssertNotShutdown();

  cef_stream_reader_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, seek)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->seek(_struct, offset, whence);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int64_t CefStreamReaderCToCpp::Tell() {
  shutdown_checker::AssertNotShutdown();

  cef_stream_reader_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, tell)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int64_t _retval = _struct->tell(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int CefStreamReaderCToCpp::Eof() {
  shutdown_checker::AssertNotShutdown();

  cef_stream_reader_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, eof)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->eof(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") bool CefStreamReaderCToCpp::MayBlock() {
  shutdown_checker::AssertNotShutdown();

  cef_stream_reader_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, may_block)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->may_block(_struct);

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefStreamReaderCToCpp::CefStreamReaderCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefStreamReaderCToCpp::~CefStreamReaderCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_stream_reader_t*
CefCToCppRefCounted<CefStreamReaderCToCpp,
                    CefStreamReader,
                    cef_stream_reader_t>::UnwrapDerived(CefWrapperType type,
                                                        CefStreamReader* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefStreamReaderCToCpp,
                                   CefStreamReader,
                                   cef_stream_reader_t>::kWrapperType =
    WT_STREAM_READER;

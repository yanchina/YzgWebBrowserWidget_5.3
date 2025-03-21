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
// $hash=f214ceb41dbd8968438ce84819e9fe96235a50aa$
//

#include "libcef_dll/ctocpp/shared_process_message_builder_ctocpp.h"

#include "libcef_dll/ctocpp/process_message_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<CefSharedProcessMessageBuilder>
CefSharedProcessMessageBuilder::Create(const CefString& name,
                                       size_t byte_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return nullptr;
  }

  // Execute
  cef_shared_process_message_builder_t* _retval =
      cef_shared_process_message_builder_create(name.GetStruct(), byte_size);

  // Return type: refptr_same
  return CefSharedProcessMessageBuilderCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") bool CefSharedProcessMessageBuilderCToCpp::IsValid() {
  shutdown_checker::AssertNotShutdown();

  cef_shared_process_message_builder_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_valid)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") size_t CefSharedProcessMessageBuilderCToCpp::Size() {
  shutdown_checker::AssertNotShutdown();

  cef_shared_process_message_builder_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, size)) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  size_t _retval = _struct->size(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") void* CefSharedProcessMessageBuilderCToCpp::Memory() {
  shutdown_checker::AssertNotShutdown();

  cef_shared_process_message_builder_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, memory)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  void* _retval = _struct->memory(_struct);

  // Return type: simple_byaddr
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefProcessMessage> CefSharedProcessMessageBuilderCToCpp::Build() {
  shutdown_checker::AssertNotShutdown();

  cef_shared_process_message_builder_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, build)) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_process_message_t* _retval = _struct->build(_struct);

  // Return type: refptr_same
  return CefProcessMessageCToCpp::Wrap(_retval);
}

// CONSTRUCTOR - Do not edit by hand.

CefSharedProcessMessageBuilderCToCpp::CefSharedProcessMessageBuilderCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefSharedProcessMessageBuilderCToCpp::~CefSharedProcessMessageBuilderCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_shared_process_message_builder_t*
CefCToCppRefCounted<CefSharedProcessMessageBuilderCToCpp,
                    CefSharedProcessMessageBuilder,
                    cef_shared_process_message_builder_t>::
    UnwrapDerived(CefWrapperType type, CefSharedProcessMessageBuilder* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType
    CefCToCppRefCounted<CefSharedProcessMessageBuilderCToCpp,
                        CefSharedProcessMessageBuilder,
                        cef_shared_process_message_builder_t>::kWrapperType =
        WT_SHARED_PROCESS_MESSAGE_BUILDER;

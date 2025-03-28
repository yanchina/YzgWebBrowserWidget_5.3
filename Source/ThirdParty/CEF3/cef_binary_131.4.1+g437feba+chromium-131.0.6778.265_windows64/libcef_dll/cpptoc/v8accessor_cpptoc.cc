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
// $hash=377b66bba850cb9cd5cb8da83ced0d60ea9f52d2$
//

#include "libcef_dll/cpptoc/v8accessor_cpptoc.h"

#include "libcef_dll/ctocpp/v8value_ctocpp.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK v8accessor_get(struct _cef_v8accessor_t* self,
                                const cef_string_t* name,
                                struct _cef_v8value_t* object,
                                struct _cef_v8value_t** retval,
                                cef_string_t* exception) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: name; type: string_byref_const
  DCHECK(name);
  if (!name) {
    return 0;
  }
  // Verify param: object; type: refptr_diff
  DCHECK(object);
  if (!object) {
    return 0;
  }
  // Verify param: retval; type: refptr_diff_byref
  DCHECK(retval);
  if (!retval) {
    return 0;
  }
  // Verify param: exception; type: string_byref
  DCHECK(exception);
  if (!exception) {
    return 0;
  }

  // Translate param: retval; type: refptr_diff_byref
  CefRefPtr<CefV8Value> retvalPtr;
  if (retval && *retval) {
    retvalPtr = CefV8ValueCToCpp::Wrap(*retval);
  }
  CefV8Value* retvalOrig = retvalPtr.get();
  // Translate param: exception; type: string_byref
  CefString exceptionStr(exception);

  // Execute
  bool _retval = CefV8AccessorCppToC::Get(self)->Get(
      CefString(name), CefV8ValueCToCpp::Wrap(object), retvalPtr, exceptionStr);

  // Restore param: retval; type: refptr_diff_byref
  if (retval) {
    if (retvalPtr.get()) {
      if (retvalPtr.get() != retvalOrig) {
        *retval = CefV8ValueCToCpp::Unwrap(retvalPtr);
      }
    } else {
      *retval = nullptr;
    }
  }

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK v8accessor_set(struct _cef_v8accessor_t* self,
                                const cef_string_t* name,
                                struct _cef_v8value_t* object,
                                struct _cef_v8value_t* value,
                                cef_string_t* exception) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: name; type: string_byref_const
  DCHECK(name);
  if (!name) {
    return 0;
  }
  // Verify param: object; type: refptr_diff
  DCHECK(object);
  if (!object) {
    return 0;
  }
  // Verify param: value; type: refptr_diff
  DCHECK(value);
  if (!value) {
    return 0;
  }
  // Verify param: exception; type: string_byref
  DCHECK(exception);
  if (!exception) {
    return 0;
  }

  // Translate param: exception; type: string_byref
  CefString exceptionStr(exception);

  // Execute
  bool _retval = CefV8AccessorCppToC::Get(self)->Set(
      CefString(name), CefV8ValueCToCpp::Wrap(object),
      CefV8ValueCToCpp::Wrap(value), exceptionStr);

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefV8AccessorCppToC::CefV8AccessorCppToC() {
  GetStruct()->get = v8accessor_get;
  GetStruct()->set = v8accessor_set;
}

// DESTRUCTOR - Do not edit by hand.

CefV8AccessorCppToC::~CefV8AccessorCppToC() {}

template <>
CefRefPtr<CefV8Accessor>
CefCppToCRefCounted<CefV8AccessorCppToC, CefV8Accessor, cef_v8accessor_t>::
    UnwrapDerived(CefWrapperType type, cef_v8accessor_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefV8AccessorCppToC,
                                   CefV8Accessor,
                                   cef_v8accessor_t>::kWrapperType =
    WT_V8ACCESSOR;

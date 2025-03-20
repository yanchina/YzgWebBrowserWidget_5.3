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
// $hash=470b41107f7bc756ceab2ec688fc7a30bc47af4f$
//

#include "libcef_dll/cpptoc/media_observer_cpptoc.h"

#include "libcef_dll/ctocpp/media_route_ctocpp.h"
#include "libcef_dll/ctocpp/media_sink_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK
media_observer_on_sinks(struct _cef_media_observer_t* self,
                        size_t sinksCount,
                        struct _cef_media_sink_t* const* sinks) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: sinks; type: refptr_vec_diff_byref_const
  DCHECK(sinksCount == 0 || sinks);
  if (sinksCount > 0 && !sinks) {
    return;
  }

  // Translate param: sinks; type: refptr_vec_diff_byref_const
  std::vector<CefRefPtr<CefMediaSink>> sinksList;
  if (sinksCount > 0) {
    for (size_t i = 0; i < sinksCount; ++i) {
      CefRefPtr<CefMediaSink> sinksVal = CefMediaSinkCToCpp::Wrap(sinks[i]);
      sinksList.push_back(sinksVal);
    }
  }

  // Execute
  CefMediaObserverCppToC::Get(self)->OnSinks(sinksList);
}

void CEF_CALLBACK
media_observer_on_routes(struct _cef_media_observer_t* self,
                         size_t routesCount,
                         struct _cef_media_route_t* const* routes) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: routes; type: refptr_vec_diff_byref_const
  DCHECK(routesCount == 0 || routes);
  if (routesCount > 0 && !routes) {
    return;
  }

  // Translate param: routes; type: refptr_vec_diff_byref_const
  std::vector<CefRefPtr<CefMediaRoute>> routesList;
  if (routesCount > 0) {
    for (size_t i = 0; i < routesCount; ++i) {
      CefRefPtr<CefMediaRoute> routesVal = CefMediaRouteCToCpp::Wrap(routes[i]);
      routesList.push_back(routesVal);
    }
  }

  // Execute
  CefMediaObserverCppToC::Get(self)->OnRoutes(routesList);
}

void CEF_CALLBACK media_observer_on_route_state_changed(
    struct _cef_media_observer_t* self,
    struct _cef_media_route_t* route,
    cef_media_route_connection_state_t state) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: route; type: refptr_diff
  DCHECK(route);
  if (!route) {
    return;
  }

  // Execute
  CefMediaObserverCppToC::Get(self)->OnRouteStateChanged(
      CefMediaRouteCToCpp::Wrap(route), state);
}

void CEF_CALLBACK
media_observer_on_route_message_received(struct _cef_media_observer_t* self,
                                         struct _cef_media_route_t* route,
                                         const void* message,
                                         size_t message_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: route; type: refptr_diff
  DCHECK(route);
  if (!route) {
    return;
  }
  // Verify param: message; type: simple_byaddr
  DCHECK(message);
  if (!message) {
    return;
  }

  // Execute
  CefMediaObserverCppToC::Get(self)->OnRouteMessageReceived(
      CefMediaRouteCToCpp::Wrap(route), message, message_size);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefMediaObserverCppToC::CefMediaObserverCppToC() {
  GetStruct()->on_sinks = media_observer_on_sinks;
  GetStruct()->on_routes = media_observer_on_routes;
  GetStruct()->on_route_state_changed = media_observer_on_route_state_changed;
  GetStruct()->on_route_message_received =
      media_observer_on_route_message_received;
}

// DESTRUCTOR - Do not edit by hand.

CefMediaObserverCppToC::~CefMediaObserverCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefMediaObserver> CefCppToCRefCounted<
    CefMediaObserverCppToC,
    CefMediaObserver,
    cef_media_observer_t>::UnwrapDerived(CefWrapperType type,
                                         cef_media_observer_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefMediaObserverCppToC,
                                   CefMediaObserver,
                                   cef_media_observer_t>::kWrapperType =
    WT_MEDIA_OBSERVER;

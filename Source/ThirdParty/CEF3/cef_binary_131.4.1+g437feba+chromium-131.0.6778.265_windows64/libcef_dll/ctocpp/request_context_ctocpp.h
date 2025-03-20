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
// $hash=db55ba31a9c4c18fa49f903f8612cc4807e1b9a6$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_REQUEST_CONTEXT_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_REQUEST_CONTEXT_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_request_context_capi.h"
#include "include/capi/cef_request_context_handler_capi.h"
#include "include/capi/cef_scheme_capi.h"
#include "include/cef_request_context.h"
#include "include/cef_request_context_handler.h"
#include "include/cef_scheme.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefRequestContextCToCpp
    : public CefCToCppRefCounted<CefRequestContextCToCpp,
                                 CefRequestContext,
                                 cef_request_context_t> {
 public:
  CefRequestContextCToCpp();
  virtual ~CefRequestContextCToCpp();

  // CefRequestContext methods.
  bool IsSame(CefRefPtr<CefRequestContext> other) override;
  bool IsSharingWith(CefRefPtr<CefRequestContext> other) override;
  bool IsGlobal() override;
  CefRefPtr<CefRequestContextHandler> GetHandler() override;
  CefString GetCachePath() override;
  CefRefPtr<CefCookieManager> GetCookieManager(
      CefRefPtr<CefCompletionCallback> callback) override;
  bool RegisterSchemeHandlerFactory(
      const CefString& scheme_name,
      const CefString& domain_name,
      CefRefPtr<CefSchemeHandlerFactory> factory) override;
  bool ClearSchemeHandlerFactories() override;
  void ClearCertificateExceptions(
      CefRefPtr<CefCompletionCallback> callback) override;
  void ClearHttpAuthCredentials(
      CefRefPtr<CefCompletionCallback> callback) override;
  void CloseAllConnections(CefRefPtr<CefCompletionCallback> callback) override;
  void ResolveHost(const CefString& origin,
                   CefRefPtr<CefResolveCallback> callback) override;
  CefRefPtr<CefMediaRouter> GetMediaRouter(
      CefRefPtr<CefCompletionCallback> callback) override;
  CefRefPtr<CefValue> GetWebsiteSetting(
      const CefString& requesting_url,
      const CefString& top_level_url,
      cef_content_setting_types_t content_type) override;
  void SetWebsiteSetting(const CefString& requesting_url,
                         const CefString& top_level_url,
                         cef_content_setting_types_t content_type,
                         CefRefPtr<CefValue> value) override;
  cef_content_setting_values_t GetContentSetting(
      const CefString& requesting_url,
      const CefString& top_level_url,
      cef_content_setting_types_t content_type) override;
  void SetContentSetting(const CefString& requesting_url,
                         const CefString& top_level_url,
                         cef_content_setting_types_t content_type,
                         cef_content_setting_values_t value) override;
  void SetChromeColorScheme(cef_color_variant_t variant,
                            cef_color_t user_color) override;
  cef_color_variant_t GetChromeColorSchemeMode() override;
  cef_color_t GetChromeColorSchemeColor() override;
  cef_color_variant_t GetChromeColorSchemeVariant() override;

  // CefPreferenceManager methods.
  bool HasPreference(const CefString& name) override;
  CefRefPtr<CefValue> GetPreference(const CefString& name) override;
  CefRefPtr<CefDictionaryValue> GetAllPreferences(
      bool include_defaults) override;
  bool CanSetPreference(const CefString& name) override;
  bool SetPreference(const CefString& name,
                     CefRefPtr<CefValue> value,
                     CefString& error) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_REQUEST_CONTEXT_CTOCPP_H_

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
// $hash=49c033cb556f562097dc367a61d5faaa928a418f$
//

#ifndef CEF_INCLUDE_CAPI_CEF_REQUEST_CONTEXT_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_REQUEST_CONTEXT_CAPI_H_
#pragma once

#include "include/capi/cef_callback_capi.h"
#include "include/capi/cef_cookie_capi.h"
#include "include/capi/cef_media_router_capi.h"
#include "include/capi/cef_preference_capi.h"
#include "include/capi/cef_values_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_request_context_handler_t;
struct _cef_scheme_handler_factory_t;

///
/// Callback structure for cef_request_context_t::ResolveHost.
///
typedef struct _cef_resolve_callback_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Called on the UI thread after the ResolveHost request has completed.
  /// |result| will be the result code. |resolved_ips| will be the list of
  /// resolved IP addresses or NULL if the resolution failed.
  ///
  void(CEF_CALLBACK* on_resolve_completed)(struct _cef_resolve_callback_t* self,
                                           cef_errorcode_t result,
                                           cef_string_list_t resolved_ips);
} cef_resolve_callback_t;

///
/// A request context provides request handling for a set of related browser or
/// URL request objects. A request context can be specified when creating a new
/// browser via the cef_browser_host_t static factory functions or when creating
/// a new URL request via the cef_urlrequest_t static factory functions. Browser
/// objects with different request contexts will never be hosted in the same
/// render process. Browser objects with the same request context may or may not
/// be hosted in the same render process depending on the process model. Browser
/// objects created indirectly via the JavaScript window.open function or
/// targeted links will share the same render process and the same request
/// context as the source browser. When running in single-process mode there is
/// only a single render process (the main process) and so all browsers created
/// in single-process mode will share the same request context. This will be the
/// first request context passed into a cef_browser_host_t static factory
/// function and all other request context objects will be ignored.
///
typedef struct _cef_request_context_t {
  ///
  /// Base structure.
  ///
  cef_preference_manager_t base;

  ///
  /// Returns true (1) if this object is pointing to the same context as |that|
  /// object.
  ///
  int(CEF_CALLBACK* is_same)(struct _cef_request_context_t* self,
                             struct _cef_request_context_t* other);

  ///
  /// Returns true (1) if this object is sharing the same storage as |that|
  /// object.
  ///
  int(CEF_CALLBACK* is_sharing_with)(struct _cef_request_context_t* self,
                                     struct _cef_request_context_t* other);

  ///
  /// Returns true (1) if this object is the global context. The global context
  /// is used by default when creating a browser or URL request with a NULL
  /// context argument.
  ///
  int(CEF_CALLBACK* is_global)(struct _cef_request_context_t* self);

  ///
  /// Returns the handler for this context if any.
  ///
  struct _cef_request_context_handler_t*(CEF_CALLBACK* get_handler)(
      struct _cef_request_context_t* self);

  ///
  /// Returns the cache path for this object. If NULL an "incognito mode" in-
  /// memory cache is being used.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_cache_path)(
      struct _cef_request_context_t* self);

  ///
  /// Returns the cookie manager for this object. If |callback| is non-NULL it
  /// will be executed asnychronously on the UI thread after the manager's
  /// storage has been initialized.
  ///
  struct _cef_cookie_manager_t*(CEF_CALLBACK* get_cookie_manager)(
      struct _cef_request_context_t* self,
      struct _cef_completion_callback_t* callback);

  ///
  /// Register a scheme handler factory for the specified |scheme_name| and
  /// optional |domain_name|. An NULL |domain_name| value for a standard scheme
  /// will cause the factory to match all domain names. The |domain_name| value
  /// will be ignored for non-standard schemes. If |scheme_name| is a built-in
  /// scheme and no handler is returned by |factory| then the built-in scheme
  /// handler factory will be called. If |scheme_name| is a custom scheme then
  /// you must also implement the cef_app_t::on_register_custom_schemes()
  /// function in all processes. This function may be called multiple times to
  /// change or remove the factory that matches the specified |scheme_name| and
  /// optional |domain_name|. Returns false (0) if an error occurs. This
  /// function may be called on any thread in the browser process.
  ///
  int(CEF_CALLBACK* register_scheme_handler_factory)(
      struct _cef_request_context_t* self,
      const cef_string_t* scheme_name,
      const cef_string_t* domain_name,
      struct _cef_scheme_handler_factory_t* factory);

  ///
  /// Clear all registered scheme handler factories. Returns false (0) on error.
  /// This function may be called on any thread in the browser process.
  ///
  int(CEF_CALLBACK* clear_scheme_handler_factories)(
      struct _cef_request_context_t* self);

  ///
  /// Clears all certificate exceptions that were added as part of handling
  /// cef_request_handler_t::on_certificate_error(). If you call this it is
  /// recommended that you also call close_all_connections() or you risk not
  /// being prompted again for server certificates if you reconnect quickly. If
  /// |callback| is non-NULL it will be executed on the UI thread after
  /// completion.
  ///
  void(CEF_CALLBACK* clear_certificate_exceptions)(
      struct _cef_request_context_t* self,
      struct _cef_completion_callback_t* callback);

  ///
  /// Clears all HTTP authentication credentials that were added as part of
  /// handling GetAuthCredentials. If |callback| is non-NULL it will be executed
  /// on the UI thread after completion.
  ///
  void(CEF_CALLBACK* clear_http_auth_credentials)(
      struct _cef_request_context_t* self,
      struct _cef_completion_callback_t* callback);

  ///
  /// Clears all active and idle connections that Chromium currently has. This
  /// is only recommended if you have released all other CEF objects but don't
  /// yet want to call cef_shutdown(). If |callback| is non-NULL it will be
  /// executed on the UI thread after completion.
  ///
  void(CEF_CALLBACK* close_all_connections)(
      struct _cef_request_context_t* self,
      struct _cef_completion_callback_t* callback);

  ///
  /// Attempts to resolve |origin| to a list of associated IP addresses.
  /// |callback| will be executed on the UI thread after completion.
  ///
  void(CEF_CALLBACK* resolve_host)(struct _cef_request_context_t* self,
                                   const cef_string_t* origin,
                                   struct _cef_resolve_callback_t* callback);

  ///
  /// Returns the MediaRouter object associated with this context.  If
  /// |callback| is non-NULL it will be executed asnychronously on the UI thread
  /// after the manager's context has been initialized.
  ///
  struct _cef_media_router_t*(CEF_CALLBACK* get_media_router)(
      struct _cef_request_context_t* self,
      struct _cef_completion_callback_t* callback);

  ///
  /// Returns the current value for |content_type| that applies for the
  /// specified URLs. If both URLs are NULL the default value will be returned.
  /// Returns nullptr if no value is configured. Must be called on the browser
  /// process UI thread.
  ///
  struct _cef_value_t*(CEF_CALLBACK* get_website_setting)(
      struct _cef_request_context_t* self,
      const cef_string_t* requesting_url,
      const cef_string_t* top_level_url,
      cef_content_setting_types_t content_type);

  ///
  /// Sets the current value for |content_type| for the specified URLs in the
  /// default scope. If both URLs are NULL, and the context is not incognito,
  /// the default value will be set. Pass nullptr for |value| to remove the
  /// default value for this content type.
  ///
  /// WARNING: Incorrect usage of this function may cause instability or
  /// security issues in Chromium. Make sure that you first understand the
  /// potential impact of any changes to |content_type| by reviewing the related
  /// source code in Chromium. For example, if you plan to modify
  /// CEF_CONTENT_SETTING_TYPE_POPUPS, first review and understand the usage of
  /// ContentSettingsType::POPUPS in Chromium:
  /// https://source.chromium.org/search?q=ContentSettingsType::POPUPS
  ///
  void(CEF_CALLBACK* set_website_setting)(
      struct _cef_request_context_t* self,
      const cef_string_t* requesting_url,
      const cef_string_t* top_level_url,
      cef_content_setting_types_t content_type,
      struct _cef_value_t* value);

  ///
  /// Returns the current value for |content_type| that applies for the
  /// specified URLs. If both URLs are NULL the default value will be returned.
  /// Returns CEF_CONTENT_SETTING_VALUE_DEFAULT if no value is configured. Must
  /// be called on the browser process UI thread.
  ///
  cef_content_setting_values_t(CEF_CALLBACK* get_content_setting)(
      struct _cef_request_context_t* self,
      const cef_string_t* requesting_url,
      const cef_string_t* top_level_url,
      cef_content_setting_types_t content_type);

  ///
  /// Sets the current value for |content_type| for the specified URLs in the
  /// default scope. If both URLs are NULL, and the context is not incognito,
  /// the default value will be set. Pass CEF_CONTENT_SETTING_VALUE_DEFAULT for
  /// |value| to use the default value for this content type.
  ///
  /// WARNING: Incorrect usage of this function may cause instability or
  /// security issues in Chromium. Make sure that you first understand the
  /// potential impact of any changes to |content_type| by reviewing the related
  /// source code in Chromium. For example, if you plan to modify
  /// CEF_CONTENT_SETTING_TYPE_POPUPS, first review and understand the usage of
  /// ContentSettingsType::POPUPS in Chromium:
  /// https://source.chromium.org/search?q=ContentSettingsType::POPUPS
  ///
  void(CEF_CALLBACK* set_content_setting)(
      struct _cef_request_context_t* self,
      const cef_string_t* requesting_url,
      const cef_string_t* top_level_url,
      cef_content_setting_types_t content_type,
      cef_content_setting_values_t value);

  ///
  /// Sets the Chrome color scheme for all browsers that share this request
  /// context. |variant| values of SYSTEM, LIGHT and DARK change the underlying
  /// color mode (e.g. light vs dark). Other |variant| values determine how
  /// |user_color| will be applied in the current color mode. If |user_color| is
  /// transparent (0) the default color will be used.
  ///
  void(CEF_CALLBACK* set_chrome_color_scheme)(
      struct _cef_request_context_t* self,
      cef_color_variant_t variant,
      cef_color_t user_color);

  ///
  /// Returns the current Chrome color scheme mode (SYSTEM, LIGHT or DARK). Must
  /// be called on the browser process UI thread.
  ///
  cef_color_variant_t(CEF_CALLBACK* get_chrome_color_scheme_mode)(
      struct _cef_request_context_t* self);

  ///
  /// Returns the current Chrome color scheme color, or transparent (0) for the
  /// default color. Must be called on the browser process UI thread.
  ///
  cef_color_t(CEF_CALLBACK* get_chrome_color_scheme_color)(
      struct _cef_request_context_t* self);

  ///
  /// Returns the current Chrome color scheme variant. Must be called on the
  /// browser process UI thread.
  ///
  cef_color_variant_t(CEF_CALLBACK* get_chrome_color_scheme_variant)(
      struct _cef_request_context_t* self);
} cef_request_context_t;

///
/// Returns the global context object.
///
CEF_EXPORT cef_request_context_t* cef_request_context_get_global_context(void);

///
/// Creates a new context object with the specified |settings| and optional
/// |handler|.
///
CEF_EXPORT cef_request_context_t* cef_request_context_create_context(
    const struct _cef_request_context_settings_t* settings,
    struct _cef_request_context_handler_t* handler);

///
/// Creates a new context object that shares storage with |other| and uses an
/// optional |handler|.
///
CEF_EXPORT cef_request_context_t* cef_create_context_shared(
    cef_request_context_t* other,
    struct _cef_request_context_handler_t* handler);

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_REQUEST_CONTEXT_CAPI_H_

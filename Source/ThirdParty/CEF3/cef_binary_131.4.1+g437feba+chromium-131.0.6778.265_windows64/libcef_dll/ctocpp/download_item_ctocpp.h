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
// $hash=b4524befe00c580a5c0dfff006dc4833ca104578$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_DOWNLOAD_ITEM_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_DOWNLOAD_ITEM_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_download_item_capi.h"
#include "include/cef_download_item.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefDownloadItemCToCpp : public CefCToCppRefCounted<CefDownloadItemCToCpp,
                                                         CefDownloadItem,
                                                         cef_download_item_t> {
 public:
  CefDownloadItemCToCpp();
  virtual ~CefDownloadItemCToCpp();

  // CefDownloadItem methods.
  bool IsValid() override;
  bool IsInProgress() override;
  bool IsComplete() override;
  bool IsCanceled() override;
  bool IsInterrupted() override;
  cef_download_interrupt_reason_t GetInterruptReason() override;
  int64_t GetCurrentSpeed() override;
  int GetPercentComplete() override;
  int64_t GetTotalBytes() override;
  int64_t GetReceivedBytes() override;
  CefBaseTime GetStartTime() override;
  CefBaseTime GetEndTime() override;
  CefString GetFullPath() override;
  uint32_t GetId() override;
  CefString GetURL() override;
  CefString GetOriginalUrl() override;
  CefString GetSuggestedFileName() override;
  CefString GetContentDisposition() override;
  CefString GetMimeType() override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_DOWNLOAD_ITEM_CTOCPP_H_

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
// $hash=3da5a83d21f4314ba28b236dea29334ad7f90278$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_VIEWS_WINDOW_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_VIEWS_WINDOW_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include <vector>

#include "include/capi/views/cef_browser_view_capi.h"
#include "include/capi/views/cef_view_capi.h"
#include "include/capi/views/cef_window_capi.h"
#include "include/views/cef_browser_view.h"
#include "include/views/cef_view.h"
#include "include/views/cef_window.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefWindowCToCpp
    : public CefCToCppRefCounted<CefWindowCToCpp, CefWindow, cef_window_t> {
 public:
  CefWindowCToCpp();
  virtual ~CefWindowCToCpp();

  // CefWindow methods.
  void Show() override;
  void ShowAsBrowserModalDialog(
      CefRefPtr<CefBrowserView> browser_view) override;
  void Hide() override;
  void CenterWindow(const CefSize& size) override;
  void Close() override;
  bool IsClosed() override;
  void Activate() override;
  void Deactivate() override;
  bool IsActive() override;
  void BringToTop() override;
  void SetAlwaysOnTop(bool on_top) override;
  bool IsAlwaysOnTop() override;
  void Maximize() override;
  void Minimize() override;
  void Restore() override;
  void SetFullscreen(bool fullscreen) override;
  bool IsMaximized() override;
  bool IsMinimized() override;
  bool IsFullscreen() override;
  CefRefPtr<CefView> GetFocusedView() override;
  void SetTitle(const CefString& title) override;
  CefString GetTitle() override;
  void SetWindowIcon(CefRefPtr<CefImage> image) override;
  CefRefPtr<CefImage> GetWindowIcon() override;
  void SetWindowAppIcon(CefRefPtr<CefImage> image) override;
  CefRefPtr<CefImage> GetWindowAppIcon() override;
  CefRefPtr<CefOverlayController> AddOverlayView(
      CefRefPtr<CefView> view,
      cef_docking_mode_t docking_mode,
      bool can_activate) override;
  void ShowMenu(CefRefPtr<CefMenuModel> menu_model,
                const CefPoint& screen_point,
                cef_menu_anchor_position_t anchor_position) override;
  void CancelMenu() override;
  CefRefPtr<CefDisplay> GetDisplay() override;
  CefRect GetClientAreaBoundsInScreen() override;
  void SetDraggableRegions(
      const std::vector<CefDraggableRegion>& regions) override;
  CefWindowHandle GetWindowHandle() override;
  void SendKeyPress(int key_code, uint32_t event_flags) override;
  void SendMouseMove(int screen_x, int screen_y) override;
  void SendMouseEvents(cef_mouse_button_type_t button,
                       bool mouse_down,
                       bool mouse_up) override;
  void SetAccelerator(int command_id,
                      int key_code,
                      bool shift_pressed,
                      bool ctrl_pressed,
                      bool alt_pressed,
                      bool high_priority) override;
  void RemoveAccelerator(int command_id) override;
  void RemoveAllAccelerators() override;
  void SetThemeColor(int color_id, cef_color_t color) override;
  void ThemeChanged() override;
  cef_runtime_style_t GetRuntimeStyle() override;

  // CefPanel methods.
  CefRefPtr<CefWindow> AsWindow() override;
  CefRefPtr<CefFillLayout> SetToFillLayout() override;
  CefRefPtr<CefBoxLayout> SetToBoxLayout(
      const CefBoxLayoutSettings& settings) override;
  CefRefPtr<CefLayout> GetLayout() override;
  void Layout() override;
  void AddChildView(CefRefPtr<CefView> view) override;
  void AddChildViewAt(CefRefPtr<CefView> view, int index) override;
  void ReorderChildView(CefRefPtr<CefView> view, int index) override;
  void RemoveChildView(CefRefPtr<CefView> view) override;
  void RemoveAllChildViews() override;
  size_t GetChildViewCount() override;
  CefRefPtr<CefView> GetChildViewAt(int index) override;

  // CefView methods.
  CefRefPtr<CefBrowserView> AsBrowserView() override;
  CefRefPtr<CefButton> AsButton() override;
  CefRefPtr<CefPanel> AsPanel() override;
  CefRefPtr<CefScrollView> AsScrollView() override;
  CefRefPtr<CefTextfield> AsTextfield() override;
  CefString GetTypeString() override;
  CefString ToString(bool include_children) override;
  bool IsValid() override;
  bool IsAttached() override;
  bool IsSame(CefRefPtr<CefView> that) override;
  CefRefPtr<CefViewDelegate> GetDelegate() override;
  CefRefPtr<CefWindow> GetWindow() override;
  int GetID() override;
  void SetID(int id) override;
  int GetGroupID() override;
  void SetGroupID(int group_id) override;
  CefRefPtr<CefView> GetParentView() override;
  CefRefPtr<CefView> GetViewForID(int id) override;
  void SetBounds(const CefRect& bounds) override;
  CefRect GetBounds() override;
  CefRect GetBoundsInScreen() override;
  void SetSize(const CefSize& size) override;
  CefSize GetSize() override;
  void SetPosition(const CefPoint& position) override;
  CefPoint GetPosition() override;
  void SetInsets(const CefInsets& insets) override;
  CefInsets GetInsets() override;
  CefSize GetPreferredSize() override;
  void SizeToPreferredSize() override;
  CefSize GetMinimumSize() override;
  CefSize GetMaximumSize() override;
  int GetHeightForWidth(int width) override;
  void InvalidateLayout() override;
  void SetVisible(bool visible) override;
  bool IsVisible() override;
  bool IsDrawn() override;
  void SetEnabled(bool enabled) override;
  bool IsEnabled() override;
  void SetFocusable(bool focusable) override;
  bool IsFocusable() override;
  bool IsAccessibilityFocusable() override;
  bool HasFocus() override;
  void RequestFocus() override;
  void SetBackgroundColor(cef_color_t color) override;
  cef_color_t GetBackgroundColor() override;
  cef_color_t GetThemeColor(int color_id) override;
  bool ConvertPointToScreen(CefPoint& point) override;
  bool ConvertPointFromScreen(CefPoint& point) override;
  bool ConvertPointToWindow(CefPoint& point) override;
  bool ConvertPointFromWindow(CefPoint& point) override;
  bool ConvertPointToView(CefRefPtr<CefView> view, CefPoint& point) override;
  bool ConvertPointFromView(CefRefPtr<CefView> view, CefPoint& point) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_VIEWS_WINDOW_CTOCPP_H_

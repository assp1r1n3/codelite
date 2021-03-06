//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : macros.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#ifndef MACROS_H
#define MACROS_H

#include <wx/stdpaths.h>
#include <wx/intl.h>
#include <map>
#include <set>

//-------------------------------------------------------
// wxWidgets Connect macros
//-------------------------------------------------------

#define ConnectChoice(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(fn), NULL, this);

#define ConnectButton(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(fn), NULL, this);

#define ConnectListBoxDClick(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(fn), NULL, this);

#define ConnectCheckBox(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(fn), NULL, this);

#define ConnectListCtrlItemSelected(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(fn), NULL, this);

#define ConnectListCtrlItemActivated(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(fn), NULL, this);

#define ConnectKeyDown(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_KEY_DOWN, wxKeyEventHandler(fn), NULL, this);

#define ConnectCharEvent(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_CHAR, wxKeyEventHandler(fn), NULL, this);

#define ConnectCmdTextEntered(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(fn), NULL, this);

#define ConnectCmdTextUpdated(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(fn), NULL, this);

#define ConnectCombo(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(fn), NULL, this);

#define ConnectCheckList(ctrl, fn)\
    ctrl->Connect(ctrl->GetId(), wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler(fn), NULL, this);

#define TrimString(str){\
        str = str.Trim();\
        str = str.Trim(false);\
    }

#define IsSourceFile(ext)\
    (ext == wxT("cpp") || ext == wxT("cxx") || ext == wxT("c") || ext == wxT("c++") || ext == wxT("cc"))

#define BoolToString(b) b ? wxT("yes") : wxT("no")

//-----------------------------------------------------
// Constants
//-----------------------------------------------------

const wxString clCMD_NEW = _("<New...>");
const wxString clCMD_EDIT = _("<Edit...>");
//const wxString clCMD_DELETE = _("<Delete...>");  Unused

// constant message
const wxString BUILD_START_MSG             = _("----------Build Started--------\n");
const wxString BUILD_END_MSG               = _("----------Build Ended----------\n");
const wxString BUILD_PROJECT_PREFIX        = _("----------Building project:[ ");
const wxString CLEAN_PROJECT_PREFIX        = _("----------Cleaning project:[ ");
const wxString SEARCH_IN_WORKSPACE         = _("Entire Workspace");
const wxString SEARCH_IN_PROJECT           = _("Active Project");
const wxString SEARCH_IN_CURR_FILE_PROJECT = _("Current File's Project");
const wxString SEARCH_IN_CURRENT_FILE      = _("Current File");
const wxString SEARCH_IN_OPEN_FILES        = _("Open Files");

const wxString USE_WORKSPACE_ENV_VAR_SET   = _("<Use Defaults>");
const wxString USE_GLOBAL_SETTINGS         = _("<Use Defaults>");

// terminal macro
#ifdef __WXGTK__
#define TERMINAL_CMD  wxString::Format(wxT("%s/codelite_xterm '$(TITLE)' '$(CMD)'"), wxFileName(wxStandardPaths::Get().GetExecutablePath()).GetPath().c_str())
#elif defined(__WXMAC__)
#define TERMINAL_CMD  wxString::Format(wxT("%s/OpenTerm '$(CMD)'"), wxStandardPaths::Get().GetDataDir().c_str())
#else
const wxString TERMINAL_CMD         = wxT("");
#endif

#if defined(__WXMSW__) && !defined(USE_POSIX_LAYOUT)
#define PATH_SEP wxT("\\")
#else
#define PATH_SEP wxT("/")
#endif

#define ID_MENU_CUSTOM_TARGET_FIRST 15000
#define ID_MENU_CUSTOM_TARGET_MAX   15100

#define viewAsMenuItemID         23500
#define viewAsMenuItemMaxID      23500+100

#define viewAsSubMenuID          23499
#define RecentFilesSubMenuID     23600
#define RecentWorkspaceSubMenuID 23650


// ----------------------------- usefule typedefs -------------------------------
typedef std::map<wxString, bool>     wxStringBoolMap_t;
typedef std::set<wxString>           wxStringSet_t;
typedef std::map<wxString, wxString> wxStringMap_t;

// Useful macros
#define CHECK_PTR_RET(p) if ( !p ) return
#define CHECK_PTR_RET_FALSE(p) if ( !p ) return false
#define CHECK_PTR_RET_NULL(p) if ( !p ) return NULL
#define CHECK_PTR_RET_EMPTY_STRING(p) if ( !p ) return wxEmptyString

#define CHECK_COND_RET(p) if ( !(p) ) return
#define CHECK_COND_RET_FALSE(p) if ( !(p) ) return false
#define CHECK_COND_RET_NULL(p) if ( !(p) ) return NULL
#define CHECK_COND_RET_EMPTY_STRING(p) if ( !(p) ) return wxEmptyString

#define CHECK_ITEM_RET(item) if ( !item.IsOk() ) return
#define CHECK_ITEM_RET_FALSE(item) if ( !item.IsOk() ) return false
#define CHECK_ITEM_RET_NULL(item) if ( !item.IsOk() ) return NULL
#define CHECK_ITEM_RET_EMPTY_STRING(item) if ( !item.IsOk() ) return wxEmptyString

#endif // MACROS_H

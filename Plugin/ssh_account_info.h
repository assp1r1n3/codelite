//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2013 by Eran Ifrah
// file name            : ssh_account_info.h
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

#ifndef SSHACCOUNTINFO_H
#define SSHACCOUNTINFO_H

#if USE_SFTP
#include "cl_config.h" // Base class: clConfigItem
#include <vector>
#include "codelite_exports.h"

class WXDLLIMPEXP_SDK SSHAccountInfo : public clConfigItem
{
    wxString      m_accountName;
    wxString      m_username;
    wxString      m_password;
    int           m_port;
    wxString      m_host;
    wxArrayString m_bookmarks;

public:
    typedef std::vector<SSHAccountInfo> Vect_t;

public:
    SSHAccountInfo();

    virtual ~SSHAccountInfo();
    SSHAccountInfo& operator=(const SSHAccountInfo& other);
    
    void AddBookmark(const wxString &location);
    
    void SetBookmarks(const wxArrayString& bookmarks) {
        this->m_bookmarks = bookmarks;
    }
    const wxArrayString& GetBookmarks() const {
        return m_bookmarks;
    }
    void SetAccountName(const wxString& accountName) {
        this->m_accountName = accountName;
    }
    const wxString& GetAccountName() const {
        return m_accountName;
    }
    void SetHost(const wxString& host) {
        this->m_host = host;
    }
    void SetPassword(const wxString& password) {
        this->m_password = password;
    }
    void SetPort(int port) {
        this->m_port = port;
    }
    void SetUsername(const wxString& username) {
        this->m_username = username;
    }
    const wxString& GetHost() const {
        return m_host;
    }
    const wxString& GetPassword() const {
        return m_password;
    }
    int GetPort() const {
        return m_port;
    }
    const wxString& GetUsername() const {
        return m_username;
    }

public:
    virtual void FromJSON(const JSONElement& json);
    virtual JSONElement ToJSON() const;
};
#endif // USE_SFTP
#endif // SSHACCOUNTINFO_H

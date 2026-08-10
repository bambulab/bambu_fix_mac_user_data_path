#ifndef slic3r_GUI_WebView_hpp_
#define slic3r_GUI_WebView_hpp_

#include <wx/webview.h>

class WebView
{
public:
    static wxWebView *CreateWebView(wxWindow *parent, wxString const &url, wxString const &name = wxEmptyString);
    
    static void LoadUrl(wxWebView * webView, wxString const &url);

    static bool RunScript(wxWebView * webView, wxString const & msg);

    static void RecreateAll();

    // Remove WebView cookies named "token" on domains containing "bambulab".
    // Windows: WebView2 CookieManager; macOS: WKHTTPCookieStore (default data store).
    static void ClearBambulabTokenCookies();

    /* Find a per-process WebView user data path.
     * Windows: WebView2 user data folder.
     * macOS: lock dir whose slot id maps to a WKWebsiteDataStore (via wx fork). */
    static wxString BuildWebViewUserDataPath();
};

#endif // !slic3r_GUI_WebView_hpp_

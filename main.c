/* BEGIN WINDOWS */
#define DLLIMPORT __declspec(dllimport)

/* Kernel32 */
DLLIMPORT void *__stdcall GetModuleHandleA(const char *lpModuleName);
DLLIMPORT void __stdcall Sleep(unsigned long dwMilliseconds);
DLLIMPORT void __stdcall ExitProcess(unsigned int uExitCode);

/* User32 */
#define PM_REMOVE 0x0001
#define WM_QUIT 0x0012
#define WM_CONTEXTMENU 0x007B
#define WM_COMMAND 0x0111
#define WM_APP 0x8000
#define LR_LOADFROMFILE 0x00000010
#define MF_BYPOSITION 0x00000400L
#define IMAGE_ICON 1

struct WNDCLASSA {
	unsigned int style;
	long long __stdcall (*lpfnWndProc)(void *hwnd, unsigned int msg, unsigned long long wp, long long lp);
	int cbClsExtra;
	int cbWndExtra;
	void *hInstance;
	void *hIcon;
	void *hCursor;
	void *hbrBackground;
	const char *lpszMenuName;
	const char *lpszClassName;
};
struct POINT {
	long x;
	long y;
};
struct MSG {
	void *hwnd;
	unsigned int message;
	unsigned long long wParam;
	long long lParam;
	unsigned long time;
	struct POINT pt;
	unsigned long lPrivate;
};
struct TPMPARAMS;

DLLIMPORT long long __stdcall DefWindowProcA(void *hwnd, unsigned int msg, unsigned long long wp, long long lp);
DLLIMPORT unsigned short __stdcall RegisterClassA(const struct WNDCLASSA *lpWndClass);
DLLIMPORT void *__stdcall CreateWindowExA(unsigned long dwExStyle, const char *lpClassName, const char *lpWindowName, unsigned long dwStyle, int X, int Y, int nWidth, int nHeight, void *hWndParent, void *hMenu, void *hInstance, void *lpParam);
DLLIMPORT int __stdcall PeekMessageA(struct MSG *lpMsg, void *hWnd, unsigned int wMsgFilterMin, unsigned int wMsgFilterMax, unsigned int wRemoveMsg);
DLLIMPORT int __stdcall TranslateMessage(const struct MSG *lpMsg);
DLLIMPORT long long __stdcall DispatchMessageA(const struct MSG *lpMsg);
DLLIMPORT void *__stdcall LoadImageA(void *hinst, const char *name, unsigned int type, int cx, int cy, unsigned int fu_load);
DLLIMPORT void *__stdcall CreatePopupMenu(void);
DLLIMPORT int __stdcall  InsertMenuA(void *hMenu, unsigned int uPosition, unsigned int uFlags, unsigned long long uIDNewItem, const char *lpNewItem);
DLLIMPORT int __stdcall DestroyMenu(void *hMenu);
DLLIMPORT int __stdcall TrackPopupMenuEx(void *hMenu, unsigned int uFlags, int x, int y, void *hwnd, struct TPMPARAMS *lptpm);
DLLIMPORT void __stdcall PostQuitMessage(int exit_code);

/* Shell32 */
#define NIM_ADD 0x00000000
#define NIM_MODIFY 0x00000001
#define NIM_SETVERSION 0x00000004
#define NOTIFYICON_VERSION_4 4
#define NIF_MESSAGE 0x00000001
#define NIF_ICON 0x00000002
struct GUID {
	unsigned long Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char Data4[8];
};
struct NOTIFYICONDATAA {
	unsigned long cbSize;
	void *hWnd;
	unsigned int uID;
	unsigned int uFlags;
	unsigned int uCallbackMessage;
	void *hIcon;
	char szTip[128];
	unsigned long dwState;
	unsigned long dwStateMask;
	char szInfo[256];
	union {
		unsigned int uTimeout;
		unsigned int uVersion;
	};
	char szInfoTitle[64];
	unsigned long dwInfoFlags;
	struct GUID guidItem;
	void *hBalloonIcon;
};

DLLIMPORT int __stdcall Shell_NotifyIconA(unsigned long msg, struct NOTIFYICONDATAA *data);

/* Ole32 */
DLLIMPORT long __stdcall CoInitializeEx(void *pvReserved, unsigned long dwCoInit);
DLLIMPORT long __stdcall CoInitializeSecurity(void *pSecDesc, long cAuthSvc, void *asAuthSvc, void *pReserved1, unsigned long dwAuthnLevel, unsigned long dwImpLevel, void *pAuthList, unsigned long dwCapabilities, void *pReserved3);
DLLIMPORT long __stdcall CoCreateInstance(const struct GUID *rclsid, void *pUnkOuter, unsigned long dwClsContext, const struct GUID *riid, void **ppv);
DLLIMPORT void __stdcall CoUninitialize(void);

#undef DLLIMPORT
/* END WINDOWS */

/* BEGIN COM */
#define VTBL_INTERFACE(type) \
	long __stdcall (*QueryInterface)(type *This, const struct GUID *riid, void **ppvObject); \
	unsigned long __stdcall (*AddRef)(type *This); \
	unsigned long __stdcall (*Release)(type *This);

extern const struct GUID IID_IWbemContext;
struct IWbemContext {
	const struct {
        	VTBL_INTERFACE(struct IWbemContext)
	} *lpVtbl;
};

extern const struct GUID IID_IWbemServices;
struct IWbemServices {
	const struct {
        	VTBL_INTERFACE(struct IWbemServices)
	} *lpVtbl;
};

extern const struct GUID CLSID_WbemLocator;
extern const struct GUID IID_IWbemLocator;
struct IWbemLocator {
	const struct {
        	VTBL_INTERFACE(struct IWbemLocator)
		long __stdcall (*ConnectServer)(struct IWbemLocator* This, const unsigned short *strNetworkResource, const unsigned short *strUser, const unsigned short *strPassword, const unsigned short *strLocale, long lSecurityFlags, const unsigned short *strAuthority, struct IWbemContext *pCtx, struct IWbemServices **ppNamespace);
	} *lpVtbl;
};

struct IWbemObjectAccess {
	struct {
        	VTBL_INTERFACE(struct IWbemObjectAccess)
		void (*GetQualifierSet)(void);
		void (*Get)(void);
		void (*Put)(void);
		void (*Delete)(void);
		void (*GetNames)(void);
		void (*BeginEnumeration)(void);
		void (*Next)(void);
		void (*EndEnumeration)(void);
		void (*GetPropertyQualifierSet)(void);
		void (*Clone)(void);
		void (*GetObjectText)(void);
		void (*SpawnDerivedClass)(void);
		void (*SpawnInstance)(void);
		void (*CompareTo)(void);
		void (*GetPropertyOrigin)(void);
		void (*InheritsFrom)(void);
		void (*GetMethod)(void);
		void (*PutMethod)(void);
		void (*DeleteMethod)(void);
		void (*BeginMethodEnumeration)(void);
		void (*NextMethod)(void);
		void (*EndMethodEnumeration)(void);
		void (*GetMethodQualifierSet)(void);
		void (*GetMethodOrigin)(void);
		long __stdcall (*GetPropertyHandle)(struct IWbemObjectAccess* This, const unsigned short *wszPropertyName, long *pType, long *plHandle);
		void (*WritePropertyValue)(void);
		void (*ReadPropertyValue)(struct IWbemObjectAccess* This, long lHandle, long lBufferSize, long *plNumBytes, unsigned char *aData);
		void (*ReadDWORD)(void);
		void (*WriteDWORD)(void);
		long __stdcall (*ReadQWORD)(struct IWbemObjectAccess* This, long lHandle, unsigned long long *pqw);
	} *lpVtbl;
};

extern const struct GUID IID_IWbemHiPerfEnum;
struct IWbemHiPerfEnum {
	const struct {
        	VTBL_INTERFACE(struct IWbemHiPerfEnum)
		void (*AddObjects)(void);
		void (*RemoveObjects)(void);
		long __stdcall (*GetObjects)(struct IWbemHiPerfEnum* This, long lFlags, unsigned long uNumObjects, struct IWbemObjectAccess **apObj, unsigned long *puReturned);
	} *lpVtbl;
};

extern const struct GUID CLSID_WbemRefresher;
extern const struct GUID IID_IWbemRefresher;
struct IWbemRefresher {
	const struct {
        	VTBL_INTERFACE(struct IWbemRefresher)
		long __stdcall (*Refresh)(struct IWbemRefresher *This, long lFlags);
	} *lpVtbl;
};

extern const struct GUID IID_IWbemConfigureRefresher;
struct IWbemConfigureRefresher {
	const struct {
        	VTBL_INTERFACE(struct IWbemConfigureRefresher)
		void (*AddObjectByPath)(void);
		void (*AddObjectByTemplate)(void);
		void (*AddRefresher)(void);
		void (*Remove)(void);
		long __stdcall (*AddEnum)(struct IWbemConfigureRefresher *This, struct IWbemServices *pNamespace, const unsigned short *wszClassName, long lFlags, struct IWbemContext *pContext, struct IWbemHiPerfEnum **ppEnum, long *plId);
	} *lpVtbl;
};
/* END COM */

#define MYWM_NOTIFYICON (WM_APP+100)
#define MYWM_NOTIFYQUIT 100

static const char prog_name[] = "Disk Usage Indicator v2.0 by Dawson Frakes";
static struct NOTIFYICONDATAA notify_icon_data;

static long long __stdcall wproc(void *hwnd, unsigned int msg, unsigned long long wp, long long lp) {
	long long result = 0;
	switch (msg) {
	case MYWM_NOTIFYICON: {
		if ((unsigned short) (lp & 0xFFFF) == WM_CONTEXTMENU) {
			struct POINT pt = {wp & 0xFFFF, (wp >> 16) & 0xFFFF};
			void *hmenu = CreatePopupMenu();
			if (hmenu) {
				InsertMenuA(hmenu, 0, MF_BYPOSITION | 1, 0, prog_name);
				InsertMenuA(hmenu, 1, MF_BYPOSITION, MYWM_NOTIFYQUIT, "Exit");
				TrackPopupMenuEx(hmenu, 0, pt.x, pt.y, hwnd, 0);
				DestroyMenu(hmenu);
			}
		}
	} break;
	case WM_COMMAND: {
		if (lp == 0 && (wp & 0xFFFF) == MYWM_NOTIFYQUIT)
			PostQuitMessage(0);
	} break;
	default: { result = DefWindowProcA(hwnd, msg, wp, lp); } break;
	}
	return result;
}

void WinMainCRTStartup(void) {
	struct IWbemServices *name_space;
	struct IWbemRefresher *refresher;
	struct IWbemHiPerfEnum *pEnum;
	struct IWbemObjectAccess *apEnumAccess[8];
	long name_handle;
	long bytespersec_handle;
	struct IWbemLocator *locator;
	struct IWbemConfigureRefresher *config;
	long lID;

	static unsigned short bstr_path[] = L"\\\\.\\root\\cimv2";
	struct {
		int len;
		unsigned short *data;
	} __attribute__((packed)) bstr_namespace = {
		.len = sizeof bstr_path / sizeof bstr_path[0] - 1,
		.data = bstr_path,
	};

	CoInitializeEx(0, 0);
	CoInitializeSecurity(0, -1, 0, 0, 1, 3, 0, 0, 0);

	CoCreateInstance(&CLSID_WbemLocator, 0, 1, &IID_IWbemLocator, (void **) &locator);
	locator->lpVtbl->ConnectServer(locator, bstr_namespace.data, 0, 0, 0, 0, 0, 0, &name_space);
	locator->lpVtbl->Release(locator); locator = 0;

	CoCreateInstance(&CLSID_WbemRefresher, 0, 1, &IID_IWbemRefresher, (void **) &refresher);
	refresher->lpVtbl->QueryInterface(refresher, &IID_IWbemConfigureRefresher, (void **) &config);

	config->lpVtbl->AddEnum(config, name_space, L"Win32_PerfFormattedData_PerfDisk_PhysicalDisk", 0, 0, &pEnum, &lID);
	config->lpVtbl->Release(config); config = 0;

	refresher->lpVtbl->Refresh(refresher, 0);
	unsigned long num_ret = 0;
	pEnum->lpVtbl->GetObjects(pEnum, 0, sizeof apEnumAccess / sizeof apEnumAccess[0], apEnumAccess, &num_ret);

	long name_type;
	long bytespersec_type;
	apEnumAccess[0]->lpVtbl->GetPropertyHandle(apEnumAccess[0], L"Name", &name_type, &name_handle);
	apEnumAccess[0]->lpVtbl->GetPropertyHandle(apEnumAccess[0], L"DiskBytesPersec", &bytespersec_type, &bytespersec_handle);

	void *hinst = GetModuleHandleA(0);
	RegisterClassA(&(struct WNDCLASSA) {
		.lpfnWndProc = wproc,
		.hInstance = hinst,
		.lpszClassName = "A",
	});
	void *hwnd = CreateWindowExA(0, "A", prog_name, 0, 0, 0, 0, 0, 0, 0, hinst, 0);
	void *busy_icon = LoadImageA(0, "busy.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	void *idle_icon = LoadImageA(0, "idle.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);

	notify_icon_data.cbSize = sizeof notify_icon_data;
	notify_icon_data.hWnd = hwnd;
	notify_icon_data.uID = 0;
	notify_icon_data.uFlags = NIF_MESSAGE | NIF_ICON;
	notify_icon_data.uCallbackMessage = MYWM_NOTIFYICON;
	notify_icon_data.hIcon = idle_icon;
	Shell_NotifyIconA(NIM_ADD, &notify_icon_data);

	notify_icon_data.uVersion = NOTIFYICON_VERSION_4;
	Shell_NotifyIconA(NIM_SETVERSION, &notify_icon_data);

	for (;;) {
		struct MSG msg;
		while (PeekMessageA(&msg, hwnd, 0, 0, PM_REMOVE) > 0) {
			if (msg.message == WM_QUIT)
				goto end;
			TranslateMessage(&msg); 
			DispatchMessageA(&msg); 
		}
		refresher->lpVtbl->Refresh(refresher, 0);
		num_ret = 0;
		pEnum->lpVtbl->GetObjects(pEnum, 0, sizeof apEnumAccess / sizeof apEnumAccess[0], apEnumAccess, &num_ret);

		unsigned long long bytespersec = 0;
		for (unsigned long i = 0; i < num_ret; ++i) {
			unsigned char name[128];
			long name_len = 0;
			apEnumAccess[i]->lpVtbl->ReadPropertyValue(apEnumAccess[i], name_handle, sizeof name / sizeof name[0], &name_len, name);
			name_len = name_len / sizeof(unsigned short) - 1;
			int same = name_len == sizeof(L"_Total") / sizeof(unsigned short) - 1;
			for (long j = 0; same && j < name_len; ++j) {
				same &= L"_Total"[j] == ((unsigned short *) name)[j];
			}
			if (same) {
				apEnumAccess[i]->lpVtbl->ReadQWORD(apEnumAccess[i], bytespersec_handle, &bytespersec);
			}
			apEnumAccess[i]->lpVtbl->Release(apEnumAccess[i]); apEnumAccess[i] = 0;
		}
		notify_icon_data.hIcon = bytespersec > 0 ? busy_icon : idle_icon;
		Shell_NotifyIconA(NIM_MODIFY, &notify_icon_data);
		Sleep(100);
	}
end:
	pEnum->lpVtbl->Release(pEnum);
	name_space->lpVtbl->Release(name_space);
	refresher->lpVtbl->Release(refresher);
	CoUninitialize();
	ExitProcess(0);
}

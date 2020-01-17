#include "AInfoLoad.h"

static const FileColHeading FileColNames[1]
{
	{L"Select", L"0COL2", L"0COL3"},
};

static const ColHeading ColNames[COL_SELLIM]
{
{L"Select", L"0COL2", L"0COL3", L"0COL4"},
{L"Select1", L"1COL2", L"1COL3", L"1COL4"},
{L"Select2", L"2COL2", L"2COL3", L"2COL4"},
{L"Select3", L"3COL2", L"3COL3", L"3COL4"},
{L"Select4", L"4COL2", L"4COL3", L"4COL4"},
{L"Select5", L"5COL2", L"5COL3", L"5COL4"},
{L"Select6", L"6COL2", L"6COL3", L"6COL4"},
{L"Select7", L"7COL2", L"7COL3", L"7COL4"},
{L"Select8", L"8COL2", L"8COL3", L"8COL4"},
{L"Select9", L"9COL2", L"9COL3", L"9COL4"}
};
static const ColWidth ColWidVals[10]
{
{16, 16, 16, 16},
{16, 16, 16, 16},
{16, 16, 16, 16},
{16, 16, 16, 16},
{16, 16, 16, 16},
{16, 16, 16, 16},
{16, 16, 16, 16},
{16, 16, 16, 16},
{16, 16, 16, 16},
{16, 16, 16, 16}
};

int j = 0;
/*Following block is from vector considerations

Protos:
//static std::wstring _dummy_foobar;
//std::wstring FormsInfo(std::wstring const& arrInit = _dummy_foobar);
std::vector<std::wstring> FormsInfo(std::vector<std::wstring> const& arrInit);

template<typename T, size_t N> T * end(T(&ra)[N])
{
	return ra + N;
}
template <typename T, size_t N> T* begin(T(&ra)[N])
{
	return ra;
}
class StrVec
{
static std::vector<std::wstring> arr;
};
std::vector<std::wstring> arrInit[MAX_LOADSTRING];
std::vector<std::wstring> StrVec::arr(begin(*arrInit), end(*arrInit)); // definition};
std::vector<std::wstring> FormsInfo(std::vector<std::wstring> const& arrInit)
{
	std::vector<std::wstring>  x = arrInit;
	return x;
}
Bit awkward */


BOOL GetFilesIn(HWND LVFileshWnd, wchar_t *currPathW)
{
WIN32_FIND_DATAW dw;
BOOL findhandle = TRUE;


memset(&dw, 0, sizeof(WIN32_FIND_DATAW));

HANDLE ds = FindFirstFileW(currPathW, &dw);

InitListView(LVFileshWnd, SKSEFILES);

CreateColumn(LVFileshWnd, 1, FileColNames[0].FileColHeadNames[0], ColWidVals[0].ColWid[0], true);
//Create columns & headers
for (j = 1; j <=2; ++j)
{
	CreateColumn(LVFileshWnd, j, FileColNames[0].FileColHeadNames[j] , ColWidVals[0].ColWid[j]);
}

	if (ds == INVALID_HANDLE_VALUE)
	{
		ErrorExit(L"No files in the Skyrim Special Edition Directory!");
		return FALSE;
	}

	i = 0, j = 0;

	while (ds != INVALID_HANDLE_VALUE && findhandle)
	{

		//Symbolic links, junction points and mount points are all reparse points
		if (!(dw.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ||	dw.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT || dw.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM || dw.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
		{
			//|| dw.dwFileAttributes & FILE_ATTRIBUTE_NOT_CONTENT_INDEXED || dw.dwFileAttributes & FILE_ATTRIBUTE_SPARSE_FILE || dw.dwFileAttributes & FILE_ATTRIBUTE_VIRTUAL || dw.dwFileAttributes & FILE_ATTRIBUTE_TEMPORARY || dw.dwFileAttributes & FILE_ATTRIBUTE_OFFLINE || dw.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED || dw.dwFileAttributes & FILE_ATTRIBUTE_DEVICE

			wcscpy_s(currPathW, RCDATALIM, dw.cFileName);
			CreateLVItems(LVFileshWnd,L"To be Setup", i , 0);
			CreateLVItems(LVFileshWnd,currPathW, i , 1);
			CreateLVItems(LVFileshWnd,currPathW, i , 2);
			
			
			if (i < maxDWORD) 
			{
				i += 1;
			}
			else
			{
				ErrorExit(L"Limit of files in listbox reached!");
				break;
			}				
			//compare with dacfolders[rootFolderC] to check for dups
		}
		findhandle = FindNextFileW(ds, &dw);

	}


FindClose(ds);


return TRUE;
}



BOOL InitListView(HWND LVWnd, int lvType)
{
	retVal = 0;
	LVCOLUMNW lvc;
	memset(&lvc, 0, sizeof(lvc));

	switch (lvType)
	{
	case 256:
	{	
		SendMessageW(LVWnd,
			LVM_SETEXTENDEDLISTVIEWSTYLE,
			LVS_EX_DOUBLEBUFFER |  LVS_EX_GRIDLINES,
			LVS_EX_DOUBLEBUFFER |  LVS_EX_GRIDLINES);
	}
	break;
	case 257:
	{
		SendMessageW(LVWnd,
			LVM_SETEXTENDEDLISTVIEWSTYLE,
			LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES,
			LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	}
	break;
	}

	//Waiting for these to be fixed esp. LVS_EX_JUSTIFYCOLUMNS perhaps also EX_AUTOSIZECOLUMNS
	#if (NTDDI_VERSION >= NTDDI_VISTA)
	#define LVS_EX_JUSTIFYCOLUMNS   0x00200000  // Icons are lined up in columns that use up the whole view area.
	#define LVS_EX_TRANSPARENTBKGND 0x00400000  // Background is painted by the parent via WM_PRINTCLIENT
	#define LVS_EX_TRANSPARENTSHADOWTEXT 0x00800000  // Enable shadow text on transparent backgrounds only (useful with bitmaps)
	#define LVS_EX_AUTOAUTOARRANGE  0x01000000  // Icons automatically arrange if no icon positions have been set
	#define LVS_EX_HEADERINALLVIEWS 0x02000000  // Display column header in all view modes
	#define LVS_EX_AUTOCHECKSELECT  0x08000000
	#define LVS_EX_AUTOSIZECOLUMNS  0x10000000
	#define LVS_EX_COLUMNSNAPPOINTS 0x40000000
	#define LVS_EX_COLUMNOVERFLOW   0x80000000
	#endif
	ListView_SetExtendedListViewStyle(LVWnd, LVS_EX_AUTOSIZECOLUMNS);


	
	SendMessageW(LVWnd, LVM_DELETEALLITEMS, 0, 0);

	//ListView_DeleteAllItems(LVRepshWnd);
	//initialize columns
	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_SUBITEM;
	lvc.fmt = LVCFMT_LEFT;
	lvc.cx=120;
	//lvc.pszText = nullptr; // not needed as not masked
	retVal = ListView_InsertColumn(LVWnd, retVal, &lvc);
	if (retVal < 0) ErrorExit(L"First column in Listview could not be created!");
	return (BOOL)retVal;
}

void AutoSizeCols(HWND LVhWnd)
{
	HWND hWndHdr = (HWND)::SendMessageW(LVhWnd, LVM_GETHEADER, 0, 0);
	int maxCol = (int)::SendMessageW(hWndHdr, HDM_GETITEMCOUNT, 0, 0L);
	for (i = 0; i< maxCol; i++)
	{
		SendMessageW(LVhWnd, LVM_SETCOLUMNWIDTH, i, LVSCW_AUTOSIZE_USEHEADER);
	}


}


BOOL CreateColumn(HWND LVhWnd, int iCol, std::wstring inText, int iWidth, BOOL delDummyCol)
{
	LVCOLUMNW lvc;
	i = 0;
	wchar_t *text = 0;
	text = (wchar_t *)calloc(MAX_LOADSTRING, SIZEOF_WCHAR);
	//https://stackoverflow.com/a/7352131/2128797
	wcscpy_s(text, MAX_LOADSTRING,  inText.c_str());

	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvc.fmt = LVCFMT_LEFT;
	lvc.cx =(int)resX * iWidth;
	lvc.pszText = text;
	lvc.iSubItem = iCol;
	retVal = SendMessageW(LVhWnd, LVM_INSERTCOLUMNW, iCol, (LPARAM)&lvc);
	//i = ListView_InsertColumn(LVhWnd, iCol, &lvc);
	if (retVal < 0)
	{
		ErrorExit(L"Could not Insert a column!",text);
		if (text) free(text);
		return FALSE;
	}
	else
	{
		if (delDummyCol)
		{
			i = ListView_DeleteColumn(LVhWnd, 0);
			if (i < 0)
				ErrorExit(L"Could not delete dummy column!");
		}
		if (text) free(text);
		return TRUE;
	}

}




BOOL CreateLVItems(HWND hwndList, std::wstring Text1, int k, int l)
{
	LVITEMW lvi = { 0 };
	retVal =0;
	
//	std::vector<std::wstring> w[] = { L"X1", L"X2", L"X3", L"X4" };
//	currPathW = (wchar_t *)calloc(maxPathFolder, SIZEOF_WCHAR);
//	wcscpy_s( currPathW,  maxPathFolder, L"B.D. Help for {");

	//const std::wstring prntArray[];
//	std::vector<std::wstring> const& myfoo = FormsInfo(*w);

	//for (auto i : FormsInfo()) //Something like this 
	//for (int i = 0; i<sizeof(prntArray); i++)
	

	// Initialize LVITEMW members that are common to all items.

	wchar_t *buffer= (wchar_t *)calloc(MAX_LOADSTRING, SIZEOF_WCHAR);	
	wcscpy_s( buffer,  MAX_LOADSTRING, Text1.c_str());
	lvi.mask = LVIF_TEXT;
	lvi.pszText = buffer;
	lvi.iItem = k;  //zero based
	lvi.iSubItem = l; // ''
	if (l)
	{
		retVal = SendMessageW(hwndList, LVM_SETITEMTEXTW, k, (LPARAM)&lvi);
		if (retVal == 0)
		{
			buffer = (wchar_t*)realloc(buffer, SIZEOF_WCHAR);
			_itow_s(k, buffer, MAX_LOADSTRING, 10);
			ErrorExit(L"Failed to set text in Listview item", buffer);
			if (buffer) free(buffer);
		}
	}
	else
	{
		retVal = SendMessageW(hwndList, LVM_INSERTITEMW, k, (LPARAM)&lvi);
		if (retVal > 0)
		{
			wchar_t(buf)[16] = {};
			FormatItowNotify(k, buf, buffer);
			if (buffer) free(buffer);
		}
		else
			retVal = 1;
		// Hope there is no actual error on first pass
	}

		// meh VS again
		//char *tmpA = (char *)malloc(sizeof(char));
		//size_t x;
		//wcstombs_s(&x, tmpA, sizeof(char),Text2, SIZEOF_WCHAR);
		//ListView_SetItemText(hwndList, Ret, 1, *tmpA);
return (BOOL)retVal;
}


// https://stackoverflow.com/questions/2933295/embed-text-file-in-a-resource-in-a-native-windows-application
const wchar_t  *LoadInResource(DWORD& size, int name, const wchar_t *rcStrType, int type) // *& is passing the pointer by reference and not by val.
{
wchar_t *data=nullptr;
HRSRC rc = 0;

	HMODULE hInst = ::GetModuleHandleW(NULL);
if (type)
	rc = ::FindResourceW(hInst, MAKEINTRESOURCEW(name), MAKEINTRESOURCEW(type));
else
	rc = ::FindResourceW(hInst, MAKEINTRESOURCEW(name),  rcStrType);

	if (rc)
	{
	HGLOBAL rcData = ::LoadResource(hInst, rc);
	size = ::SizeofResource(hInst, rc);
	data = static_cast<wchar_t*>(::LockResource(rcData)); //LockResource does not actually lock memory; it is just used to obtain a pointer to the memory containing the resource data. 
	return data;
	}
	return NULL;
}
BOOL GetResource(HWND LVRepshWnd, int rcName, const wchar_t *rcStrType, const wchar_t *rcStrType1,  int rcIntType)
{
	DWORD size1 = 0, size2 = 0;
	LVA2D LV2DA(MAX_LOADSTRING, LVA(4));
	ColumnSelectors ColumnSels(ColumnSelectors(COL_SELLIM));
	wchar_t *buffer =nullptr, *buffer1 =nullptr, *buffer2 =nullptr;
	const wchar_t *data, *data1;
	i = 0, j = 0;
	int iMax = 0, jMax=0;
	//data= (wchar_t *)calloc(4 * RCDATALIM, SIZEOF_WCHAR);	

	data = LoadInResource(size1, rcName, rcStrType, rcIntType);

	if (data && size1)
	{
		/* Access bytes in data - here's a simple example involving text output*/
		// The text stored in the resource might not be NULL terminated.
		// alternative memory mgt +but not compat with LocalAlloc in ErrorExit!
		//wchar_t* buffer = new wchar_t[size + 1];
		//::memcpy(buffer, data, size);
		//delete[] buffer; // only delete objects created by "new"
		buffer1= (wchar_t *)calloc(size1 + 1, SIZEOF_WCHAR);
		wcscpy_s( buffer1,  size1, data);
		buffer1[size1] = L'\0'; // NULL terminator
	
		if (rcStrType1)
		{
			data1 = LoadInResource(size2, rcName, rcStrType1, rcIntType);
			if (data1 && size2)
			{
				buffer= (wchar_t *)calloc(size1 + size2 + 2, SIZEOF_WCHAR);
				buffer2= (wchar_t *)calloc(size2 + 1, SIZEOF_WCHAR);
				wcscpy_s( buffer2,  size2, data1);
				buffer2[size2] = L'\0'; // C6011 deferencing warning N/A as size2 > 0
				wcscpy_s(buffer, size1, buffer1);
				wcscat_s(buffer, size1 + size2 + 1, L"\n");
				wcscat_s(buffer, size1 + size2 + 1, buffer2);
				buffer[size1 + size2 + 1] = L'\0'; 
			}
			else
			{
				buffer= (wchar_t *)calloc(MAX_LOADSTRING, SIZEOF_WCHAR);	
				_itow_s(rcName, buffer, MAX_LOADSTRING, 10);
				ErrorExit(L"Could not locate resource!",buffer);
				if (buffer) free (buffer);
				if (buffer1) free (buffer1);
				//if (data) free (data);
				return FALSE;
			}

		LV2DA = ResProc(buffer, COMMA_DELIM, iMax, jMax);
		InitListView(LVRepshWnd, SKSEINFO);
		
		if (!CreateColumn(LVRepshWnd, 1, ColNames[0].ColHeadNames[0], ColWidVals[0].ColWid[0], true))
		return FALSE;
		//Create columns & headers
		for (j = 1; j <=jMax + 1; ++j)
		{
			if (!CreateColumn(LVRepshWnd, j, ColNames[0].ColHeadNames[j] , ColWidVals[0].ColWid[j]))
			return FALSE;
		}
		
		for (i = 0; i <iMax; ++i)
		{
		std::wstring foo = L"Selection";
		ColumnSels.push_back(foo);
		//https://stackoverflow.com/a/48251347/2128797
		std::rotate(ColumnSels.rbegin(), ColumnSels.rbegin() + 1, ColumnSels.rend());
		//ColumnSels.shrink_to_fit();
		wchar_t* tempDest = nullptr;
		// MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, ColumnSels[i].c_str())
		int temp = wcslen(ColumnSels[i].c_str());
		tempDest = (wchar_t *)calloc(temp + SIZEOF_WCHAR, SIZEOF_WCHAR);
		// _itow_s(i, tempDest, MAX_LOADSTRING, 10);
		wcscpy_s(tempDest, temp + SIZEOF_WCHAR, ColumnSels[i].c_str());
		//tempDest[SIZEOF_WCHAR * temp + 1] = '\0';
		 //ErrorExit(L"w", tempDest);
		if (tempDest) free(tempDest);
		for (j = 0; j <=jMax + 1; ++j)
		{
			//if (!CreateLVItems(LVRepshWnd, (j == 0)? (i < 10? ColSelectors[i][0]: L""): LV2DA[i][j -1], i , j))
			if (!CreateLVItems(LVRepshWnd, (j == 0)? (i < 10? ColumnSels[i]: L""): LV2DA[i][j -1], i , j))
			return FALSE;
		}
		}
	}	

		//if (data) free(data);
		if (buffer) free(buffer);
		if (buffer1) free(buffer1);
		if (buffer2) free(buffer2);

		return TRUE;
	}
else
	{
	buffer= (wchar_t *)calloc(MAX_LOADSTRING, SIZEOF_WCHAR);	
	_itow_s(rcName, buffer, MAX_LOADSTRING, 10);
	ErrorExit(L"Could not locate resource!",buffer);
	if (buffer) free (buffer);
	if (buffer1) free (buffer1);
	//if (data) free (data);
	return FALSE;
	}

}

LVA2D ResProc(const wchar_t* strVar, const wchar_t delimiter, int &iMax, int &jMax)
{
	i = 0, j = 0;
	int k = 0;
	iMax = 0;
	jMax=0;
	LVA2D LV2DAOUT(MAX_LOADSTRING, LVA(4));
	wchar_t tmp[MAX_LOADSTRING] ={L""};
	
	for (int l = 0; l <wcslen(strVar); ++l)
	{
		if (i > MAX_LOADSTRING)
		{
			ErrorExit(L"Input data overflow at ", tmp);
			return  LV2DAOUT;
		}
		
		if (strVar[l] == delimiter)
		{
			if (k > MAX_LOADSTRING-1)
			tmp[MAX_LOADSTRING-1] = L'\0';
			else
			tmp[k + 1] =L'\0';

			LV2DAOUT[i][j]= tmp;
			//https://stackoverflow.com/questions/6149314/why-is-an-empty-wchar-t-literal-allowed
			//tmp[0] = L'\0';
			memset(tmp,0,sizeof(tmp));
			j +=1;
			k = 0;
		}
		else
		{
			if (strVar[l] == EOL_DELIM)
			{
			LV2DAOUT[i][j]= tmp;
			memset(tmp,0,sizeof(tmp));
			i +=1;
			if (j > jMax)
			jMax=j;
			j  = 0;
			k = 0;
			}
			else
			{
			tmp[k]= strVar[l];
			k +=1;
			}
		}

	}
//no delims or EOL
iMax = i;
if (!i && !j)
LV2DAOUT[i][j]= tmp;
return  LV2DAOUT;
}

BOOL GetRegVal(wchar_t* keyName, wchar_t* valueName, wchar_t* valueData)
{
	
	HKEY key;
	retVal = 0;
	retVal = RegOpenKeyExW(
		HKEY_LOCAL_MACHINE, 
		keyName,
		0, 
		KEY_READ|KEY_WOW64_64KEY, 
		&key);
	if(retVal!=ERROR_SUCCESS)
	{
		if(retVal == ERROR_FILE_NOT_FOUND || retVal == ERROR_PATH_NOT_FOUND)
		retVal = 0;
		else
		{
		wchar_t * buffer= (wchar_t *)calloc(MAX_LOADSTRING, SIZEOF_WCHAR);	
		_itow_s(retVal, buffer, MAX_LOADSTRING, 10);
		ErrorExit(L"Failed to open SSE registry key!", buffer);
		if (buffer) free(buffer);
		}
		return retVal;
	}

	DWORD length = 0;

	// get the size - it's going to be 4 for a DWORD, but this shows how to deal with REG_SZ, etc
	retVal = RegQueryValueExW(
		key, 
		valueName,
		NULL, 
		NULL, 
		NULL, 
		&length);
	if(retVal!=ERROR_SUCCESS)
	{
		retVal = 1;
		ErrorExit(L"Failed to get buffer size!");
		RegCloseKey(key);
		return retVal;
	}

	wchar_t* lpValue;
	lpValue = new wchar_t[length+1];
	lpValue[length] = '\0';

	// query
	retVal =RegQueryValueExW(
		key, 
		valueName, 
		NULL, NULL, 
		(LPBYTE)lpValue, 
		&length);
	if(retVal==ERROR_SUCCESS)
	{
		wcscpy_s(valueData, RCDATALIM,  lpValue);
		retVal = 0;
	}
	else
	{
		retVal = 1;
		ErrorExit(L"Failed to get value data!");
	}
delete[] lpValue;
RegCloseKey(key);
return retVal;
}


BOOL ChangeWindowMsgFilterEx(HWND hWnd, UINT uMsg)
{

	typedef BOOL (WINAPI * fnChangeWindowMessageFilterEx)(HWND, UINT, DWORD, PCHANGEFILTERSTRUCT);
	fnChangeWindowMessageFilterEx pfn =
		reinterpret_cast<fnChangeWindowMessageFilterEx>(
			reinterpret_cast<void*>(
				GetProcAddress(GetModuleHandleW(L"user32"),	"ChangeWindowMessageFilterEx")));

	if (!(pfn))
		//using the old function gets the C4456
	{

		typedef BOOL (WINAPI * fnChangeWindowMessageFilter)( UINT, DWORD);
		fnChangeWindowMessageFilter pfn1 =
			reinterpret_cast<fnChangeWindowMessageFilter>(
				reinterpret_cast<void*>(
					GetProcAddress(GetModuleHandleW(L"user32"), "ChangeWindowMessageFilter")));
		return pfn1(uMsg, MSGFLT_ADD);
	}
	return pfn(hWnd, uMsg, MSGFLT_ALLOW, NULL);
}
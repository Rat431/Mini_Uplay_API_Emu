#include "pch.h"
#include <fstream>
#include <sstream>
#include <vector>


#define UPLAY_EXPORT extern "C" _declspec(dllexport)

HANDLE fileuplay = 0;
void* DirectoryBuffer = 0;

bool created = false;

int val = 0;

struct Chunks
{
	ULONG_PTR d1;
	void* d2;
};
struct Overmapped
{
	signed char pd[4];
	int32_t f4;
	int32_t f8;
};
struct FileOpen
{
	HANDLE d1;
};
struct FileOpenTwo
{
	int addr1;
	int addr2;
	int addr3;
};
struct FileRead
{
	int addr1;
	int addr2;
	int addr3;
};
struct FileList
{
	ULONG_PTR num;
	void* bufferstring;
	ULONG_PTR pointer;
};
struct MyFileRef
{
	HANDLE hFile;
	int numfile;
	char nameoffile[4024];
};
std::vector<MyFileRef> FileVector;

namespace Uplay_Configuration
{
	char UserName[0x200] = { "Rat" };
	char UserEmail[0x200] = { "UplayEmu@rat43.com" };
	char password[0x200] = { "UplayPassword74" };
	char GameLanguage[0x200] = { "en-US" };
	char SaveDir[MAX_PATH] = { "Default" };
	char UserId[1024] = { "c91c91c9-1c91-c91c-91c9-1c91c91c91c9" };
	char CdKey[1024] = { "1111-2222-3333-4444" };
	char TickedId[1024] = { "noT456umPqRt" };
	bool Offline = false;
	bool appowned = true;

	int cdkey1 = 0;
	int cdkey2 = 0;
	uint32_t gameAppId = 0;
}

DWORD    GetFilePointer(HANDLE hFile) {
	return SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
}
void CreatePath(const char* Path)
{
	if (!created)
	{
		CHAR data[MAX_PATH] = { 0 };
		lstrcpyA(&data[0], Path);
		int size = lstrlenA(data) + 1;
		CHAR out[MAX_PATH] = { 0 };
		int i = 0;
		for (;;)
		{
			if (data[i] == NULL)
				break;

			memcpy(&out[i], &data[i], 1);
			if (out[i] == '\\')
			{
				if (GetFileAttributesA(out) == INVALID_FILE_ATTRIBUTES)
				{
					CreateDirectoryA(out, NULL);
				}
			}
			i++;
		}
		if (GetFileAttributesA(out) == INVALID_FILE_ATTRIBUTES)
		{
			CreateDirectoryA(out, NULL);
		}
		created = true;
	}
	return;
}
static char datapp[1024];
const char* AttachDirFile(const char* Path, const char* file)
{
	memset(datapp, 0, sizeof(datapp));
	sprintf_s(datapp, sizeof(datapp), "%s\\%s", Path, file);
	return datapp;
}
const char* AppIdtoString(int appid)
{
	std::stringstream stream;
	stream << appid;
	return stream.str().c_str();
}
char dataqq[1024] = { 0 };
char dt[1024] = { 0 };
char tmppath[1024] = { 0 };
const char* FormatDir(const char* dir, bool setslashes)
{
	if (dataqq[0] == 0)
	{
		if (strcmp(Uplay_Configuration::SaveDir, "Default") == 0)
		{
			GetModuleFileNameA(UplayModule, tmppath, MAX_PATH);
			int size = lstrlenA(tmppath);
			for (int i = size; i > 0; i--)
			{
				if (tmppath[i] == '\\')
				{
					memset(&tmppath[i], 0, size - i);
					break;
				}
			}
			sprintf(dataqq, "%s\\%s\\%s\\%u", tmppath, dir, Uplay_Configuration::UserName, Uplay_Configuration::gameAppId);
			return dataqq;
		}
		sprintf(dataqq, "%s\\%s\\%s\\%s", Uplay_Configuration::SaveDir, dir, Uplay_Configuration::UserName, AppIdtoString(Uplay_Configuration::gameAppId));
		return dataqq;
	}
	return dataqq;

}

bool IsTargetExist(LPCSTR path)
{
	if (GetFileAttributesA(path) == INVALID_FILE_ATTRIBUTES)
		return false;
	return true;
}



// Exports implementations


UPLAY_EXPORT int UPLAY_ACH_EarnAchievement()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_GetAchievementImage()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_GetAchievements()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_ReleaseAchievementImage()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_ReleaseAchievementList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_Write()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_AVATAR_Get(void* buf1)
{
	return 1;
}
UPLAY_EXPORT int UPLAY_AVATAR_GetAvatarIdForCurrentUser()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_AVATAR_GetBitmap()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_AVATAR_Release()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ClearGameSession()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_AddPlayedWith()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_AddToBlackList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_DisableFriendMenuItem()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_EnableFriendMenuItem()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_GetFriendList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_Init()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_InviteToGame()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_IsBlackListed()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_IsFriend()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_RemoveFriendship()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_RemoveFromBlackList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_RequestFriendship()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_RespondToGameInvite()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_ShowFriendSelectionUI()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_ShowInviteFriendsToGameUI()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_GetLastError()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_GetNextEvent()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_GetOverlappedOperationResult(void* buf1, int* buf2)
{
	Overmapped* ovr = (Overmapped*)buf1;
	if (!ovr->f4) {
		return 0;
	}
	else {
		*buf2 = ovr->f8;
		return 1;
	}
}
UPLAY_EXPORT int UPLAY_HasOverlappedOperationCompleted(void* buf1)
{
	Overmapped* ovr = (Overmapped*)buf1;
	return ovr->f4;
}
UPLAY_EXPORT int UPLAY_INSTALLER_AreChunksInstalled()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_INSTALLER_GetChunkIdsFromTag()
{
	return 0;
}
Chunks* chunks = 0;
UPLAY_EXPORT int UPLAY_INSTALLER_GetChunks(void* buf1)
{
	chunks = (Chunks*)VirtualAlloc(0, 10, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	chunks->d1 = 1;
	chunks->d2 = VirtualAlloc(0, 1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
#ifdef _WIN64
	memcpy(buf1, chunks, 8);
#else
	memcpy(buf1, chunks, 4);
#endif // _WIN64
	return 1;

}
UPLAY_EXPORT const char* UPLAY_INSTALLER_GetLanguageUtf8()
{
	return Uplay_Configuration::GameLanguage;
}
UPLAY_EXPORT int UPLAY_INSTALLER_Init()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_INSTALLER_ReleaseChunkIdList()
{
	VirtualFree((void*)chunks, 0, MEM_DECOMMIT);
	return 1;
}
UPLAY_EXPORT int UPLAY_INSTALLER_UpdateInstallOrder()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_Init()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_METADATA_ClearContinuousTag()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_METADATA_SetContinuousTag()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_METADATA_SetSingleEventTag()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Apply()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Close()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Enumerate()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Get()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Open()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_ReleaseKeyValueList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Set()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_SetInGameState()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_SetShopUrl()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_Show()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_ShowBrowserUrl()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_ShowFacebookAuthentication()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_ShowNotification()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_ShowShopUrl()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_DisablePartyMemberMenuItem()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_EnablePartyMemberMenuItem()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_GetFullMemberList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_GetId()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_GetInGameMemberList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_Init()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_InvitePartyToGame()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_InviteToParty()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_IsInParty()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_IsPartyLeader()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_PromoteToLeader()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_RespondToGameInvite()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_SetGuest()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_SetUserData()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_PARTY_ShowGameInviteOverlayUI()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PRESENCE_SetPresence()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_PeekNextEvent()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_Quit()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_Release()
{
	return 1;
}
const char* savefile = "";
long position = 0;
long firstpos = 0;
void* tempbuffer = VirtualAlloc(NULL, 0x80000, MEM_COMMIT, PAGE_READWRITE);
UPLAY_EXPORT int UPLAY_SAVE_Close(HANDLE hFiledata)
{
	SetFilePointer(hFiledata, 0, 0, 0);
	DWORD data = 0;
	DWORD datat = 0;
	ReadFile(hFiledata, &data, 4, &datat, 0);
	DWORD tt = 0x224;
	if (data == 0)
	{
		SetFilePointer(hFiledata, 0, 0, 0);
		WriteFile(hFiledata, &tt, 4, &data, 0);
		SetFilePointer(hFiledata, 0x28, 0, 0);
		for (std::vector<MyFileRef>::size_type f = 0; f < FileVector.size(); f++)	// Search thorugh initialized files
		{
			if (FileVector[f].hFile == hFiledata)
			{
				WriteFile(hFiledata, FileVector[f].nameoffile, 0x200, &data, NULL);
				break;
			}
		}
		SetFilePointer(hFiledata, 0, 0, 0);
	}
	CloseHandle(hFiledata);
	return 1;
}
const char* dir = 0;
int whichfile = 0;
char name[4024] = { 0 };
UPLAY_EXPORT int UPLAY_SAVE_GetSavegames(void* listpointer, void* mystruct)
{
	void* FirstPointer = VirtualAlloc(NULL, 0x80000, MEM_COMMIT, PAGE_READWRITE);
	void* SecondPointer = VirtualAlloc(NULL, 0x80000, MEM_COMMIT, PAGE_READWRITE);
	ULONG_PTR SecondPointerAddr = (ULONG_PTR)SecondPointer;
	const char* myconstant = AttachDirFile(dir, "*.save");
	DWORD valueofiles = 0;
	WIN32_FIND_DATAA fd = { 0 };
	HANDLE firstFile = FindFirstFileA(myconstant, &fd);

	if (firstFile != INVALID_HANDLE_VALUE)
	{
		do
		{

			if (fd.dwFileAttributes == FILE_ATTRIBUTE_ARCHIVE)
			{
				void* ThirdPointer = VirtualAlloc(NULL, 0x3000, MEM_COMMIT, PAGE_READWRITE);
				int filecounternm = 0;
				sscanf((char*)fd.cFileName, "%d.save", &filecounternm);
				HANDLE hFoundFile = CreateFileA(AttachDirFile(dir, (char*)fd.cFileName), GENERIC_READ, 1, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
				DWORD FileSize = GetFileSize(hFoundFile, NULL);
				DWORD val = FileSize - 0x228;
				DWORD FilePointer = SetFilePointer(hFoundFile, 0x28, NULL, NULL);
				DWORD bytesreaded = 0;
				char* datar2 = (char*)VirtualAlloc(NULL, 0x200, MEM_COMMIT, PAGE_READWRITE);
				ReadFile(hFoundFile, datar2, 0x200, &bytesreaded, NULL);
				FileList* flst = (FileList*)ThirdPointer;
				flst->bufferstring = datar2;
				flst->num = (ULONG_PTR)filecounternm;
				flst->pointer = (ULONG_PTR)val;
#ifdef _WIN64
				memcpy((void*)SecondPointerAddr, &ThirdPointer, 8);
				SecondPointerAddr += 8;
#else
				memcpy((void*)SecondPointerAddr, &ThirdPointer, 4);
				SecondPointerAddr += 4;
#endif			
				CloseHandle(hFoundFile);
				valueofiles++;
			}

		} while (FindNextFileA(firstFile, &fd) == TRUE);
		FindClose(firstFile);
#ifdef _WIN64
		memcpy(FirstPointer, &valueofiles, 8);
		memcpy((void*)((ULONG_PTR)FirstPointer + 8), &SecondPointer, 8);
#else
		memcpy(FirstPointer, &valueofiles, 4);
		memcpy((void*)((ULONG_PTR)FirstPointer + 4), &SecondPointer, 4);
#endif
	}
#ifdef _WIN64
	memcpy(listpointer, &FirstPointer, 8);
#else
	memcpy(listpointer, &FirstPointer, 4);
#endif
	FileRead * flr = (FileRead*)mystruct;
	flr->addr1++;
	flr->addr2 = 1;
	flr->addr3 = 0;

	return 1;
}
UPLAY_EXPORT int UPLAY_SAVE_Open(int dp1, int dp2, void* buf1, void* buf2)		// Init UPLAY SAVES
{
	char file[1024] = { 0 };
	sprintf(file, "%d.save", dp1);
	whichfile = dp1;
	savefile = AttachDirFile(dir, file);
	tempbuffer = VirtualAlloc(0, 0x228, MEM_COMMIT, PAGE_READWRITE);
	MyFileRef ref = { 0 };
	if (dp2 == 0)
	{
		HANDLE fileuplayt = CreateFileA(savefile, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		FileOpen* fp = (FileOpen*)buf1;
		FileOpenTwo* fp2 = (FileOpenTwo*)buf2;
		fp->d1 = fileuplayt;
		fp2->addr1++;
		fp2->addr2 = 1;
		fp2->addr3 = 0;
		ref.hFile = fileuplayt;
		ref.numfile = dp1;
		FileVector.push_back(ref);
		return 1;
	}
	else
	{
		HANDLE fileuplayt = CreateFileA(savefile, SE_GROUP_LOGON_ID, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		DWORD ld;
		WriteFile(fileuplayt, tempbuffer, 0x228, &ld, 0);
		FileOpen* fp = (FileOpen*)buf1;
		FileOpenTwo* fp2 = (FileOpenTwo*)buf2;
		fp->d1 = fileuplayt;
		fp2->addr1++;
		fp2->addr2 = 1;
		fp2->addr3 = 0;
		ref.hFile = fileuplayt;
		ref.numfile = dp1;
		FileVector.push_back(ref);
		return 1;
	}
	return 0;
}
UPLAY_EXPORT int UPLAY_SAVE_Read(HANDLE hFile, SIZE_T datatoread, long offset, void* dt1, DWORD * bytesreaded, void* mystruct)
{
	void* ReadedData = 0;
	if (hFile != INVALID_HANDLE_VALUE)
	{
#ifdef _WIN64
		memcpy(&ReadedData, dt1, 8);
#else
		memcpy(&ReadedData, dt1, 4);
#endif 
		SetFilePointer(hFile, 0x228 + offset, NULL, NULL);
		DWORD wrote;
		ReadFile(hFile, ReadedData, datatoread, bytesreaded, NULL);
		FileRead* flr = (FileRead*)mystruct;
		flr->addr1++;
		flr->addr2 = 1;
		flr->addr3 = 0;
		return 1;
	}
	FileRead* flr = (FileRead*)mystruct;
	flr->addr1++;
	flr->addr2 = 1;
	flr->addr3 = 0;
	return 0;
}
UPLAY_EXPORT int UPLAY_SAVE_ReleaseGameList(void* listpointer)
{
	VirtualFree(listpointer, NULL, MEM_DECOMMIT);
	return 1;
}
UPLAY_EXPORT int UPLAY_SAVE_Remove(int fileindex, void* filestruct)
{
	char file[1024] = { 0 };
	sprintf(file, "%d.save", fileindex);
	savefile = AttachDirFile(dir, file);

	DeleteFileA(savefile);
	FileRead* flr = (FileRead*)filestruct;
	flr->addr1++;
	flr->addr2 = 1;
	flr->addr3 = 0;
	return 1;
}
UPLAY_EXPORT int UPLAY_SAVE_SetName(HANDLE hFileData, const char* namefile)
{
	for (std::vector<MyFileRef>::size_type f = 0; f < FileVector.size(); f++)	// Search thorugh initialized files
	{
		if (FileVector[f].hFile == hFileData)
		{
			strcpy(FileVector[f].nameoffile, namefile);
			break;
		}
	}
	return 1;
}
UPLAY_EXPORT int UPLAY_SAVE_Write(HANDLE hFile, SIZE_T datatowrite, void* buf1, void* buf2)
{
	if (hFile != INVALID_HANDLE_VALUE)
	{
		void* WriteData = 0;
#ifdef _WIN64
		memcpy(&WriteData, buf1, 8);
#else
		memcpy(&WriteData, buf1, 4);
#endif // _WIN64
		DWORD dat = 0;
		WriteFile(hFile, WriteData, datatowrite, &dat, NULL);
		FileRead* flr = (FileRead*)buf2;
		flr->addr1++;
		flr->addr2 = 1;
		flr->addr3 = 0;
		return 1;
	}
	FileRead* flr = (FileRead*)buf2;
	flr->addr1++;
	flr->addr2 = 1;
	flr->addr3 = 0;
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_Checkout()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_GetPartner()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_GetProducts()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_ReleaseProductsList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_ShowProductDetails()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_ShowProducts()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_SetGameSession()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_SetLanguage(const char* language)
{
	strcpy(Uplay_Configuration::GameLanguage, language);
	return 1;
}
UPLAY_EXPORT int UPLAY_Start()
{
	CHAR INI[MAX_PATH] = { 0 };					// Get ini directory
	GetModuleFileNameA(UplayModule, INI, MAX_PATH);
	int Size = lstrlenA(INI);
	for (int i = Size; i > 0; i--)
	{
		if (INI[i] == '\\')
		{
			lstrcpyA(&INI[i], "\\Uplay.ini");
			break;
		}
	}
	if (!IsTargetExist(INI))
	{
		MessageBoxA(0, "Couldn't find Uplay.ini.", "Uplay", MB_ICONERROR);
		ExitProcess(0);
	}
	Uplay_Configuration::appowned = GetPrivateProfileIntA("Uplay", "IsAppOwned", 0, INI) == TRUE;		// Read ini informations
	Uplay_Configuration::Offline = GetPrivateProfileIntA("Uplay", "UplayConnection", 0, INI) == TRUE;
	Uplay_Configuration::gameAppId = GetPrivateProfileIntA("Uplay", "AppId", 0, INI);
	GetPrivateProfileStringA("Uplay", "Username", 0, Uplay_Configuration::UserName, 0x200, INI);
	GetPrivateProfileStringA("Uplay", "Email", 0, Uplay_Configuration::UserEmail, 0x200, INI);
	GetPrivateProfileStringA("Uplay", "Password", 0, Uplay_Configuration::password, 0x200, INI);
	GetPrivateProfileStringA("Uplay", "SavePath", 0, Uplay_Configuration::SaveDir, MAX_PATH, INI);
	GetPrivateProfileStringA("Uplay", "Language", 0, Uplay_Configuration::GameLanguage, 0x200, INI);
	GetPrivateProfileStringA("Uplay", "CdKey", 0, Uplay_Configuration::CdKey, 0x200, INI);
	GetPrivateProfileStringA("Uplay", "UserId", 0, Uplay_Configuration::UserId, 0x200, INI);
	GetPrivateProfileStringA("Uplay", "TickedId", 0, Uplay_Configuration::TickedId, 0x200, INI);

	dir = FormatDir("ApiLocalStorage", 0);			// Storage init
	CreatePath(dir);
	return 0;
}
UPLAY_EXPORT int UPLAY_StartCN()
{
	return UPLAY_Start();
}
UPLAY_EXPORT int UPLAY_Startup()
{
	return UPLAY_Start();
}
UPLAY_EXPORT int UPLAY_USER_ClearGameSession()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_ConsumeItem()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_GetAccountId()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetAccountIdUtf8()
{
	return Uplay_Configuration::UserId;
}
UPLAY_EXPORT int UPLAY_USER_GetCPUScore()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetCdKeyUtf8()
{
	return Uplay_Configuration::CdKey;
}
UPLAY_EXPORT int UPLAY_USER_GetCdKeys()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_USER_GetConsumableItems(void* buf1)
{
#ifdef _WIN64
	memset(buf1, 0, 8);
#else
	memset(buf1, 0, 4);
#endif
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_GetCredentials()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_USER_GetEmail()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetEmailUtf8()
{
	return Uplay_Configuration::UserEmail;
}
UPLAY_EXPORT int UPLAY_USER_GetGPUScore()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_USER_GetGPUScoreConfidenceLevel()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetNameUtf8()
{
	return Uplay_Configuration::UserName;
}
UPLAY_EXPORT int UPLAY_USER_GetPassword()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetPasswordUtf8()
{
	return Uplay_Configuration::password;
}
UPLAY_EXPORT int UPLAY_USER_GetProfile()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetTicketUtf8()
{
	return Uplay_Configuration::TickedId;
}
UPLAY_EXPORT int UPLAY_USER_GetUsername()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetUsernameUtf8()
{
	return Uplay_Configuration::UserName;
}
UPLAY_EXPORT int UPLAY_USER_IsConnected()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_IsInOfflineMode()
{
	return Uplay_Configuration::Offline;
}
UPLAY_EXPORT int UPLAY_USER_IsOwned(int data)
{
	return Uplay_Configuration::appowned;
}
UPLAY_EXPORT int UPLAY_USER_ReleaseCdKeyList()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_ReleaseConsumeItemResult()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_ReleaseProfile()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_USER_SetGameSession()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_Update()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_WIN_GetActions()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_WIN_GetRewards()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_WIN_GetUnitBalance()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_WIN_RefreshActions()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_WIN_ReleaseActionList()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_WIN_ReleaseRewardList()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_WIN_SetActionsCompleted()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_CHAT_GetHistory()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_CHAT_Init()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_CHAT_ReleaseHistoryList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_CHAT_SendMessage()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_CHAT_SentMessagesRead()
{
	return 0;
}
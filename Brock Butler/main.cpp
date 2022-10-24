#include <DxLib.h>

#include "MyClass/Manager/SceneManager.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrvInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SceneManager::GetInstance().Run();
	return 0;
}
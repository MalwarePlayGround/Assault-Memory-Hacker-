// These Address are dynamic xD So I made just to test sth it won't work with u 

#include <Windows.h>
#include <iostream>

#define HealthAddr 0x027DA850
#define RifleAmmoAddr 0x027DA8A8
#define GunAmmoAddr 0x027DA894
#define WINDOW_NAME "AssaultCube"
#define GrenadesAddr 0x027DA8B0

int main() {
	// get a window handle
	std::cout << "Looking For Game ..." << std::endl;
	HWND gameHandle = NULL;
	while (gameHandle == NULL)
	{
		gameHandle = FindWindowA(NULL, WINDOW_NAME);
	}
	std::cout << "Handle to Game Established" << std::endl;

	DWORD procId;
	GetWindowThreadProcessId(gameHandle, &procId);
	if (procId) {
		std::cout << "Process ID Found" << std::endl;
	}
	else {
		std::cout << "Process ID Not Found" << std::endl;
		exit(1);
	}

	// Open Process
	HANDLE hProc;
	hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
	if (hProc) {
		std::cout << "Process Not Found" << std::endl;
	}

	else {
		std::cout << "Process Not Found" << std::endl; 
		exit(1); 
	}

	// Setup for memory hacking 

	bool health = false;
	bool RifleAmmo = false; 
	bool GunAmmo = false;
	bool Grenades = false;

	// Display Meunu 

	bool screen = true; 

	while (true)
	{
		if (screen)
		{
			system("cls");
			std::cout << "Welcome to Assault Cube Memory Hacker" << std::endl;
			std::cout << "======================================" << std::endl;
			std::cout << "[F1] -" << (health ? "on" : "off") << ") Health to 100,000" << std::endl; 
			std::cout << "[F2] -" << (RifleAmmo ? "on" : "off") << ") RifleAmmo to 100,000" << std::endl;
			std::cout << "[F2] -" << (GunAmmo ? "on" : "off") << ") GunAmmo to 100,000" << std::endl;
			std::cout << "[F4] -" << (Grenades ? "on" : "off") << ") Grenades to 100,000" << std::endl;
			screen = false;
		}
		SHORT keypress; 

		// Check For health 
		keypress = GetAsyncKeyState(VK_F1);
		if (keypress)
		{
			health = !health;
			screen = true;
		}
		// keypress for Riffle Ammo 
		keypress = GetAsyncKeyState(VK_F2);
		if (RifleAmmo)
		{
			RifleAmmo = !RifleAmmo;
			screen = true;
		}
		// keypress for gun ammo 
		keypress = GetAsyncKeyState(VK_F3);
		if (keypress)
		{
			GunAmmo = !GunAmmo;
			screen = true;
		}
		// keypress for grenades 
		keypress = GetAsyncKeyState(VK_F4);
		if (keypress)
		{
			Grenades = !Grenades;
			screen = true;
		}
		
		// Apply Current setting for game memory 
		if (health)
		{
			int newValue = 100000;
			WriteProcessMemory(hProc, (LPVOID)HealthAddr, &newValue, sizeof(newValue), NULL);
		}

		if (RifleAmmo)
		{
			int newValue = 100000;
			WriteProcessMemory(hProc, (LPVOID)RifleAmmoAddr, &newValue, sizeof(newValue), NULL);
		}

		if (GunAmmo)
		{
			int newValue = 100000;
			WriteProcessMemory(hProc, (LPVOID)GunAmmoAddr, &newValue, sizeof(newValue), NULL);
		}

		if (Grenades)
		{
			int newValue = 100000;
			WriteProcessMemory(hProc, (LPVOID)GrenadesAddr, &newValue, sizeof(newValue), NULL);
		}
	}

}




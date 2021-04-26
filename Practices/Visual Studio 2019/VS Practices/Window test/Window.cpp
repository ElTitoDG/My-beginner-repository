#include "Window.h"

Window* window = nullptr;

Window::Window() {
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam){
	switch (msg) {
	case WM_CREATE:
	{
		window->onCreate();
		break;
	}
		
	case WM_DESTROY:
	{
		::PostQuitMessage(0);
		break;
	}


	default:
		return::DefWindowProc(hwnd, msg, wparam, lparam);
	}



	return NULL;
}
bool Window::init()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = "MyWindowClass";
	wc.lpszMenuName = "";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;
	if (!::RegisterClassEx(&wc))
		return false;

	m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", "Test 1", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1920, 1080, NULL, NULL, NULL, NULL);

	if (!m_hwnd)
		return false;

	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);


	if (!window)
		window = this;


	return true;
}

bool Window::release()
{
	if (!::DestroyWindow(m_hwnd))
		return false; 

	return true;
}

Window::~Window() {
}

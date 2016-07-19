#include "stdafx.h"
#include "ProcessWindow.h"
#include "global.h"

#include <iostream>
#include <string>
#include <codecvt>

INPUT PressKey(int key);

ProcessWindow::ProcessWindow(HWND hWnd) :
	window_(hWnd)
{
	WCHAR wbuf[1024];

	if (GetWindowText(hWnd, wbuf, 256) > 0)
		title_ = std::wstring(wbuf);

	DWORD proc_id;
	GetWindowThreadProcessId(window_, &proc_id);
	process_ = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, proc_id);
	DWORD wbuf_size = sizeof(wbuf);
	if (QueryFullProcessImageNameW(process_, 0, wbuf, &wbuf_size) > 0)
		moduleFileName_ = std::wstring(wbuf);

	icon_ = (HICON) SendMessage(window_, WM_GETICON, ICON_SMALL2, 0);
	if (icon_ == 0)
		icon_ = (HICON) SendMessage(window_, WM_GETICON, ICON_SMALL, 0);
	if (icon_ == 0)
		icon_ = (HICON) SendMessage(window_, WM_GETICON, ICON_BIG, 0);
	if (icon_ == 0)
		icon_ = (HICON) GetClassLongPtr(window_, GCL_HICON);
	if (icon_ == 0)
		icon_ = (HICON) GetClassLongPtr(window_, GCL_HICONSM);

}

void ProcessWindow::windowInfo() const
{
	std::wcout << "Window: Title:" << title_ << " (" << moduleFileName_ << ", icon: " << icon_ << ")" << std::endl;
}

std::unique_ptr<msgs::Icon> ProcessWindow::encodeIcon() const
{
	// NOTE: The following code does not make any effort to support
	// paletted (aka color-indexed) formats, since we don't make use
	// of them whatsoever, and it makes the code less readable and more
	// complex.

	ICONINFO icon_info;

	if (GetIconInfo(icon_, &icon_info) == FALSE)
		return nullptr;
	
	BITMAP bmp;
	if (!icon_info.hbmColor) {
		std::wcerr << "warning: required icon is black/white (not yet implemented)";
		return nullptr;
	}

	if (GetObject(icon_info.hbmColor, sizeof(bmp), &bmp) <= 0)
		return nullptr;

	// Allocate memory for the header (should also make space for the color table,
	// but we're not using it, so no need for that)
	BITMAPINFOHEADER *hdr = (BITMAPINFOHEADER*) std::malloc(sizeof(*hdr));
	hdr->biSize = sizeof(BITMAPINFOHEADER);
	hdr->biWidth = bmp.bmWidth;
	hdr->biHeight = bmp.bmHeight;
	hdr->biPlanes = 1;
	hdr->biBitCount = bmp.bmPlanes * bmp.bmBitsPixel;
	hdr->biCompression = BI_RGB;
	hdr->biSizeImage = 0;
	hdr->biXPelsPerMeter = 0;  // just not using these
	hdr->biYPelsPerMeter = 0;
	hdr->biClrUsed = 0;
	hdr->biClrImportant = 0;

	HDC hdc = GetDC(NULL);

	// Make the device driver calculate thei image data size (biSizeImage)
	GetDIBits(hdc, icon_info.hbmColor, 0L, bmp.bmHeight,
		NULL, (BITMAPINFO*) hdr, DIB_RGB_COLORS);

	if (hdr->biSizeImage == 0) {
		// Well, that didn't work out. Calculate biSizeImage ourselves.
		// The form ((x + n) & ~n) is a trick to round x up to a multiple of n+1.
		// In this case, a multiple of 32 (== sizeof DWORD)
		hdr->biSizeImage = (((hdr->biWidth * hdr->biBitCount) + 31) & ~31) / 8 * hdr->biHeight;
	}

	// Make space for the image pixels data
	void *new_hdr = std::realloc(hdr, sizeof(BITMAPINFOHEADER) + hdr->biSizeImage);
	if (!new_hdr) {
		std::free(hdr);
		ReleaseDC(NULL, hdc);
		return nullptr;
	}
	hdr = (BITMAPINFOHEADER*)new_hdr;

	void *pixels = ((uint8_t*) hdr) + sizeof(BITMAPINFOHEADER);
	BOOL got_bits = GetDIBits(hdc, icon_info.hbmColor, 
		0L, bmp.bmHeight,
		(LPBYTE) pixels, 
		(BITMAPINFO*)hdr,
		DIB_RGB_COLORS);

	ReleaseDC(NULL, hdc);
	
	if (!got_bits) {
		// Well, damn.
		std::free(hdr);
		return nullptr;
	}

	// Got the bitmap data! Finally!
	auto icon = std::make_unique<msgs::Icon>();
	icon->set_width(hdr->biWidth);
	icon->set_height(hdr->biHeight);
	icon->set_pixels(pixels, hdr->biSizeImage);
	
	std::cerr << icon->DebugString() << '\n';

	std::free(hdr);
	return icon;
}

HWND ProcessWindow::handle() const
{
	return window_;
}

std::string ProcessWindow::title() const
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conversion;
	return conversion.to_bytes(this->title_);
}

bool ProcessWindow::sendKeystroke(msgs::KeystrokeRequest req)
{
	int num_mods = 0;
	INPUT ip[5];
	
	if (req.ctrl()) {
		ip[num_mods++] = PressKey(VK_CONTROL);
	}
	if (req.alt()) {
		ip[num_mods++] = PressKey(0);
	}
	if (req.shift()) {
		ip[num_mods++] = PressKey(0);
	}
	if (req.meta()) {
		ip[num_mods++] = PressKey(0);
	}

	// TODO: convertire da tasto di protocollo
	ip[num_mods++] = PressKey(0);
	
	BringWindowToTop(window_);
	//oppure
	SetForegroundWindow(window_);
	if (SendInput(num_mods, ip, sizeof(INPUT))) {
		for (int i = 0; i < num_mods; i++) {
			ip[i].ki.dwFlags = KEYEVENTF_KEYUP;
		}

		if (SendInput(num_mods, ip, sizeof(INPUT))) {
			return true;
		}
	}

	std::cerr << "unable to send input to the selected window" << std::endl;
	return false;
}

INPUT PressKey(int key) {
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.time = 0;
	input.ki.wScan = 0;
	input.ki.dwExtraInfo = 0;
	input.ki.wVk = key;
	return input;
}
#if 0

Pseudo-code for icon data extraction:

Starting from icon_ (HICON).

if ()1


#endif

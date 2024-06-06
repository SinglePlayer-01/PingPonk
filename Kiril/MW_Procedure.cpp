#include "MainWindow.h"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            GetClientRect(m_hwnd, &Client_rect);
            GetFocus();
            SetTimer(m_hwnd, 1, 16, NULL);
            HFONT hFont = CreateFont(50, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");


            hwnd_EditControl_1 = CreateWindow(L"EDIT", L"0", WS_CHILD | ES_CENTER | ES_READONLY | WS_VISIBLE, 125, 150, 60, 60, m_hwnd, NULL, NULL, NULL, NULL);
            hwnd_EditControl_2 = CreateWindow(L"EDIT", L"0", WS_CHILD | ES_CENTER | ES_READONLY | WS_VISIBLE, 290, 150, 60, 60, m_hwnd, NULL, NULL, NULL, NULL);

            SendMessage(hwnd_EditControl_1, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hwnd_EditControl_2, WM_SETFONT, (WPARAM)hFont, TRUE);

            Create_Factory();
            Create_GraphicResources();
        }
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                // Для гравця 1
                case VK_LEFT:
                    if (0 < x_platform_1)
                    {
                        x_platform_1 -= stap_platform;
                        x_platform_2 -= stap_platform;
                    }
                break;
                case VK_RIGHT:
                    if (x_platform_2 < Client_rect.right)
                    {
                        x_platform_1 += stap_platform;
                        x_platform_2 += stap_platform;
                    }
                break;

                // Для гравця 2
                case 0x31: // Клава 1
                    if (0 < x_platform_12)
                    {
                        x_platform_12 -= stap_platform2;
                        x_platform_22 -= stap_platform2;
                    }
                break;
                case 0x32: // Клава 2
                    if (x_platform_22 < Client_rect.right)
                    {
                        x_platform_12 += stap_platform2;
                        x_platform_22 += stap_platform2;
                    }
                    break;
            }
            InvalidateRect(m_hwnd, NULL, FALSE);
            RedrawWindow(m_hwnd, &Client_rect, NULL, RDW_UPDATENOW);
        }
        return 0;

        case WM_SIZE:
            GetClientRect(m_hwnd, &Client_rect);
            return 0;

        case WM_TIMER:
        {
            x_ellipse += x_speed;
            y_ellipse += y_speed;
            
            // Відскакування від стінок
            if (x_ellipse - radius_ellipse < 0 || x_ellipse + radius_ellipse > Client_rect.right)
            {
                x_speed = -x_speed;
            }
            if (y_ellipse - radius_ellipse < 0 || y_ellipse + radius_ellipse > Client_rect.bottom)
            {
                y_speed = -y_speed;
            }

            // Взаємодія з платформою
            if (x_platform_1 <= x_ellipse && x_ellipse <= x_platform_2 && y_ellipse + radius_ellipse > y_platform_1 - 5)
            {
                y_speed = -y_speed;
                score_1++;
            }
            if (x_platform_12 <= x_ellipse && x_ellipse <= x_platform_22 && y_ellipse - radius_ellipse < y_platform_22 + 5)
            {
                y_speed = -y_speed;
                score_2++;
            }

            // Преобразование int to wchar_t
            wchar_t m_reportFileName_1[100];
            swprintf_s(m_reportFileName_1, L"%d", score_1);
            // Преобразование int to wchar_t
            wchar_t m_reportFileName_2[100];
            swprintf_s(m_reportFileName_2, L"%d", score_2);

            SetWindowText(hwnd_EditControl_1, m_reportFileName_1);
            SetWindowText(hwnd_EditControl_2, m_reportFileName_2);

            InvalidateRect(m_hwnd, NULL, FALSE);
            RedrawWindow(m_hwnd, &Client_rect, NULL, RDW_UPDATENOW);
        }
        return 0;

        case WM_DESTROY:
            Discar_GraphicResources();
            PostQuitMessage(0);
        return 0;

        case WM_PAINT:
            Draw_GraphicResources();
        return 0;

        case WM_CTLCOLORBTN:
        case WM_CTLCOLOREDIT:
        case WM_CTLCOLORSTATIC:
            SetBkMode(HDC(wParam), (COLORREF)RGB(200, 0, 0));
            SetTextColor(HDC(wParam), (COLORREF)RGB(10, 10, 0));
            return LRESULT(HBRUSH(GetStockObject(NULL_BRUSH)));
    }
    return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}
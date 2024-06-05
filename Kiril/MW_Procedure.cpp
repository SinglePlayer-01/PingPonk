#include "MainWindow.h"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
            GetClientRect(m_hwnd, &Client_rect);
            SetTimer(m_hwnd, 1, 16, NULL);
            Create_Factory();
            Create_GraphicResources();
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_LEFT:
                    x_platform_1 -= stap_platform;
                    x_platform_2 -= stap_platform;
                break;

                case VK_RIGHT:
                    x_platform_1 += stap_platform;
                    x_platform_2 += stap_platform;
                break;
            }
            InvalidateRect(m_hwnd, NULL, FALSE);
            RedrawWindow(m_hwnd, &Client_rect, NULL, RDW_UPDATENOW);
        }
        return 0;

        case WM_TIMER:
        {
            x_ellipse += x_speed;
            y_ellipse += y_speed;
            
            if (x_ellipse - radius_ellipse < 0 || x_ellipse + radius_ellipse > Client_rect.right)
            {
                x_speed = -x_speed;
            }
            if (y_ellipse - radius_ellipse < 0 || y_ellipse + radius_ellipse > Client_rect.bottom)
            {
                y_speed = -y_speed;
            }
            if (x_platform_1 <= x_ellipse && x_ellipse <= x_platform_2 && y_ellipse + radius_ellipse > y_platform_1 - 10) y_speed = -y_speed;
            InvalidateRect(m_hwnd, NULL, FALSE);
            RedrawWindow(m_hwnd, &Client_rect, NULL, RDW_UPDATENOW);
        }
        return 0;

        case WM_DESTROY:
            Discar_GraphicResources();
            PostQuitMessage(0);
        return 0;

        case WM_PAINT:
        {
            Draw_GraphicResources();
        }
        return 0;
    }
    return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}
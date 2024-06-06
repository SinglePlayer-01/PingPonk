#include "MainWindow.h"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
            GetClientRect(m_hwnd, &Client_rect);
            GetFocus();
            SetTimer(m_hwnd, 1, 16, NULL);
            Create_Factory();
            Create_GraphicResources();
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                // ƒл€ гравц€ 1
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

                // ƒл€ гравц€ 2
                case 0x31: //  лава 1
                    if (0 < x_platform_12)
                    {
                        x_platform_12 -= stap_platform2;
                        x_platform_22 -= stap_platform2;
                    }
                break;
                case 0x32: //  лава 2
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
            
            // ¬≥дскакуванн€ в≥д ст≥нок
            if (x_ellipse - radius_ellipse < 0 || x_ellipse + radius_ellipse > Client_rect.right)
            {
                x_speed = -x_speed;
            }
            if (y_ellipse - radius_ellipse < 0 || y_ellipse + radius_ellipse > Client_rect.bottom)
            {
                y_speed = -y_speed;
            }

            // ¬заЇмод≥€ з платформою
            if (x_platform_1 <= x_ellipse && x_ellipse <= x_platform_2 && y_ellipse + radius_ellipse > y_platform_1 - 5) y_speed = -y_speed;
            if (x_platform_12 <= x_ellipse && x_ellipse <= x_platform_22 && y_ellipse - radius_ellipse < y_platform_22 + 5) y_speed = -y_speed;


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
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

            // Взаємодія з блоками
            if (block_1.left <= x_ellipse && x_ellipse <= block_1.right && block_1.bottom < y_ellipse - radius_ellipse && block_hit_1 == false) {
                y_speed = -y_speed;
                block_hit_1 = true;
            }
            if (block_2.left <= x_ellipse && x_ellipse <= block_2.right && block_2.bottom < y_ellipse - radius_ellipse && block_hit_2 == false) {
                y_speed = -y_speed;
                block_hit_2 = true;
            }
            if (block_3.left <= x_ellipse && x_ellipse <= block_3.right && block_3.bottom < y_ellipse - radius_ellipse && block_hit_3 == false) {
                y_speed = -y_speed;
                block_hit_3 = true;
            }
            if (block_4.left <= x_ellipse && x_ellipse <= block_4.right && block_4.bottom < y_ellipse - radius_ellipse && block_hit_4 == false) {
                y_speed = -y_speed;
                block_hit_4 = true;
            }
            if (block_5.left <= x_ellipse && x_ellipse <= block_5.right && block_5.bottom < y_ellipse - radius_ellipse && block_hit_5 == false) {
                y_speed = -y_speed;
                block_hit_5 = true;
            }
            if (block_6.left <= x_ellipse && x_ellipse <= block_6.right && block_6.bottom < y_ellipse - radius_ellipse && block_hit_6 == false) {
                y_speed = -y_speed;
                block_hit_6 = true;
            }
            if (block_7.left <= x_ellipse && x_ellipse <= block_7.right && block_7.bottom < y_ellipse - radius_ellipse && block_hit_7 == false) {
                y_speed = -y_speed;
                block_hit_7 = true;
            }
            if (block_8.left <= x_ellipse && x_ellipse <= block_8.right && block_8.bottom < y_ellipse - radius_ellipse && block_hit_8 == false) {
                y_speed = -y_speed;
                block_hit_8 = true;
            }
            if (block_9.left <= x_ellipse && x_ellipse <= block_9.right && block_9.bottom < y_ellipse - radius_ellipse && block_hit_9 == false) {
                y_speed = -y_speed;
                block_hit_9 = true;
            }
            if (block_10.left <= x_ellipse && x_ellipse <= block_10.right && block_10.bottom < y_ellipse - radius_ellipse && block_hit_10 == false) {
                y_speed = -y_speed;
                block_hit_10 = true;
            }


            // Взаємодія з платформою
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
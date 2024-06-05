#pragma once

#include<Windows.h>
#include<d2d1.h>
#include<dwrite.h>

#pragma comment(lib,"d2d1")
#pragma comment(lib,"dwrite")

#include"BaseWindow.h"


class MainWindow : public BaseWindow<MainWindow>
{
    RECT Client_rect;


    // Координати для шару
    int x_ellipse = 300;
    int y_ellipse = 300;
    int radius_ellipse = 15;
    int x_speed = 10;
    int y_speed = 10;

    // Координати для патформи
    int x_platform_1 = 0;
    int y_platform_1 = Client_rect.bottom - 20;
    int x_platform_2 = 150;
    int y_platform_2 = Client_rect.bottom;
    int stap_platform = 30;

    // Координати для блоків
    D2D1_RECT_F block_1{ block_1.left = 0,block_1.top = 0,block_1.right = 40,block_1.bottom = 40 };
    D2D1_RECT_F block_2{ block_2.left = 40,block_2.top = 0,block_2.right = 80,block_2.bottom = 40 };
    D2D1_RECT_F block_3{ block_3.left = 80,block_3.top = 0,block_3.right = 120,block_3.bottom = 40 };
    D2D1_RECT_F block_4{ block_4.left = 120,block_4.top = 0,block_4.right = 160,block_4.bottom = 40 };
    D2D1_RECT_F block_5{ block_5.left = 160,block_5.top = 0,block_5.right = 200,block_5.bottom = 40 };
    D2D1_RECT_F block_6{ block_6.left = 200,block_6.top = 0,block_6.right = 240,block_6.bottom = 40 };
    D2D1_RECT_F block_7{ block_7.left = 240,block_7.top = 0,block_7.right = 280,block_7.bottom = 40 };
    D2D1_RECT_F block_8{ block_8.left = 280,block_8.top = 0,block_8.right = 320,block_8.bottom = 40 };
    D2D1_RECT_F block_9{ block_9.left = 320,block_9.top = 0,block_9.right = 360,block_9.bottom = 40 };
    D2D1_RECT_F block_10{ block_10.left = 360,block_10.top = 0,block_10.right = 400,block_10.bottom = 40 };

    bool block_hit_1 = false;
    bool block_hit_2 = false;
    bool block_hit_3 = false;
    bool block_hit_4 = false;
    bool block_hit_5 = false;
    bool block_hit_6 = false;
    bool block_hit_7 = false;
    bool block_hit_8 = false;
    bool block_hit_9 = false;
    bool block_hit_10 = false;
    ID2D1Factory* m_pFactory_graphic;
    ID2D1DCRenderTarget* m_pRenderTarget;
    ID2D1SolidColorBrush* m_pSolBrush_wallpaper;
    ID2D1SolidColorBrush* m_pSolBrush_ellipse;
    ID2D1SolidColorBrush* m_pSolBrush_platform;
    ID2D1SolidColorBrush* m_pSolBrush_target;
    ID2D1SolidColorBrush* m_pSolBrush_text;

    IDWriteFactory* m_pFactory_write;
    IDWriteTextFormat* m_pTextFormat_1;
    IDWriteTextFormat* m_pTextFormat_2;

    // Create a DC render target.
    D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE_DEFAULT,
        D2D1::PixelFormat(
            DXGI_FORMAT_B8G8R8A8_UNORM,
            D2D1_ALPHA_MODE_IGNORE),
        0,
        0,
        D2D1_RENDER_TARGET_USAGE_NONE,
        D2D1_FEATURE_LEVEL_DEFAULT
    );

    HRESULT Create_Factory();
    HRESULT Create_GraphicResources();
    void    Discar_GraphicResources();
    void    Draw_GraphicResources();

public:



    PCWSTR  ClassName() const { return L"Sample Window Class"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
}; 


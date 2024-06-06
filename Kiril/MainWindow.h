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
    int x_speed = 3;
    int y_speed = 3;

    // Координати для патформи першого гравця
    int x_platform_1 = 0;
    int y_platform_1 = Client_rect.bottom - 20;
    int x_platform_2 = 150;
    int y_platform_2 = Client_rect.bottom;
    int stap_platform = 30;

    // Координати для платформи другого гравця
    int x_platform_12 = 0;
    int y_platform_12 = 0;
    int x_platform_22 = 150;
    int y_platform_22 = 20;
    int stap_platform2 = 30;

    ID2D1Factory* m_pFactory_graphic;
    ID2D1DCRenderTarget* m_pRenderTarget;
    ID2D1SolidColorBrush* m_pSolBrush_wallpaper;
    ID2D1SolidColorBrush* m_pSolBrush_ellipse;
    ID2D1SolidColorBrush* m_pSolBrush_platform1;
    ID2D1SolidColorBrush* m_pSolBrush_platform2;
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


#include"MainWindow.h"

template <class T> void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

void MainWindow::Discar_GraphicResources()
{
    SafeRelease(&m_pFactory_graphic);
    SafeRelease(&m_pRenderTarget);
    SafeRelease(&m_pSolBrush_wallpaper);
    SafeRelease(&m_pSolBrush_ellipse);
    SafeRelease(&m_pSolBrush_platform);
    SafeRelease(&m_pSolBrush_target);
    SafeRelease(&m_pSolBrush_text);

    SafeRelease(&m_pFactory_write);
    SafeRelease(&m_pTextFormat_1);
    SafeRelease(&m_pTextFormat_2);
}

HRESULT MainWindow::Create_Factory()
{
    HRESULT hr = S_OK;
    if (D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pFactory_graphic) == S_FALSE)
    {
        return hr = S_FALSE;
    }
    if (DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&m_pFactory_write)) == S_FALSE)
    {
        return hr = S_FALSE;
    }
    return hr;
}

HRESULT MainWindow::Create_GraphicResources()
{
    HRESULT hr = S_OK;
    if (m_pRenderTarget == NULL)
    {
        hr = m_pFactory_graphic->CreateDCRenderTarget(&props, &m_pRenderTarget);
        if (hr == S_OK)
        {
            m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Gray), &m_pSolBrush_wallpaper);
            m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Yellow), &m_pSolBrush_ellipse);
            m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::GreenYellow), &m_pSolBrush_target);
            hr = m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &m_pSolBrush_platform);
            m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &m_pSolBrush_text);
        }
        if (hr == S_OK)
        {
            m_pFactory_write->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 24.0f, L"en-us", &m_pTextFormat_1);
            m_pFactory_write->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &m_pTextFormat_2);

            m_pTextFormat_1->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            m_pTextFormat_1->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

            m_pTextFormat_2->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            m_pTextFormat_2->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        }
    }
    return hr;
}

void MainWindow::Draw_GraphicResources()
{
    HRESULT hr = Create_GraphicResources();
    if (hr == S_OK)
    {
        PAINTSTRUCT ps{ };

        HDC hdc = BeginPaint(m_hwnd, &ps);

        y_platform_1 = Client_rect.bottom - 20;
        y_platform_2 = Client_rect.bottom;

        m_pRenderTarget->BindDC(hdc, &Client_rect);
        m_pRenderTarget->BeginDraw();
        m_pRenderTarget->FillRectangle(D2D1::RectF(0, 0, Client_rect.right, Client_rect.bottom), m_pSolBrush_wallpaper);

        m_pRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(x_ellipse, y_ellipse), radius_ellipse, radius_ellipse), m_pSolBrush_ellipse);

        m_pRenderTarget->FillRectangle(D2D1::RectF(x_platform_1, y_platform_1, x_platform_2, y_platform_2), m_pSolBrush_platform);

        if (block_hit_1 == false) m_pRenderTarget->FillRectangle(block_1, m_pSolBrush_target);
        if (block_hit_2 == false) m_pRenderTarget->FillRectangle(block_2, m_pSolBrush_target);
        if (block_hit_3 == false) m_pRenderTarget->FillRectangle(block_3, m_pSolBrush_target);
        if (block_hit_4 == false) m_pRenderTarget->FillRectangle(block_4, m_pSolBrush_target);
        if (block_hit_5 == false) m_pRenderTarget->FillRectangle(block_5, m_pSolBrush_target);
        if (block_hit_6 == false) m_pRenderTarget->FillRectangle(block_6, m_pSolBrush_target);
        if (block_hit_7 == false) m_pRenderTarget->FillRectangle(block_7, m_pSolBrush_target);
        if (block_hit_8 == false) m_pRenderTarget->FillRectangle(block_8, m_pSolBrush_target);
        if (block_hit_9 == false) m_pRenderTarget->FillRectangle(block_9, m_pSolBrush_target);
        if (block_hit_10 ==false) m_pRenderTarget->FillRectangle(block_10, m_pSolBrush_target);


        m_pRenderTarget->EndDraw();

        EndPaint(m_hwnd, &ps);
    }
}